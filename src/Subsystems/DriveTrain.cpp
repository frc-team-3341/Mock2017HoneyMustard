#include <math.h>
#include "../RobotMap.h"
#include "../CommandBase.h"
#include "../Commands/TankDrive.h"
//#include "../Commands/TankDriveReverse.h"

#include "DriveTrain.h"

#define max(x, y) (((x) > (y)) ? (x) : (y))

DriveTrain::DriveTrain() : PIDSubsystem("DriveTrain",1.0,0,0), left(new CANTalon(DRIVE_MOTOR_LEFT)),
right(new CANTalon(DRIVE_MOTOR_RIGHT)), mult(1.0), ticksToDistance(114), testDrive(new RobotDrive(left, right)),
encoderLeft(new Encoder(0,1)),
    encoderRight(new Encoder(2,3))//random channels, change if necessary
//make our own subclasses to inherit these functions!
{
	encoderLeft->SetDistancePerPulse(1.0);
	encoderRight->SetDistancePerPulse(1.0);
}

DriveTrain::~DriveTrain()
{
	delete testDrive;
	delete left;
	delete right;
}

void DriveTrain::reverseDrive()
{
	left->SetInverted(!left->GetInverted());
	right->SetInverted(!right->GetInverted());
}

void DriveTrain::setMult(float m)
{
	mult = m;
}

int DriveTrain::getMult()
{
	return mult;
}

void DriveTrain::tankDrive(float moveValueLeft, float moveValueRight)
{
	moveValueLeft = DriveTrain::Limit(moveValueLeft, 1.0);
	moveValueRight = -DriveTrain::Limit(moveValueRight, 1.0);

	if (mult != 0) {
		left->Set(moveValueLeft);
		right->Set(moveValueRight);
	} else {
		left->Set(moveValueLeft);
		right->Set(moveValueRight);
	}

	//testDrive->TankDrive(moveValueLeft, moveValueRight);
}

float DriveTrain::Limit(float num, float max)
{
	if (num > max)
		return max;

	if (num < -max)
		return -max;

	return num;
}

void DriveTrain::InitDefaultCommand()
{
	SetDefaultCommand(new TankDrive());
}

void DriveTrain::setSpeedLeft(double speed)
{
	left->Set(speed * mult);
}

void DriveTrain::setSpeedRight(double speed)
{
	right->Set(speed * mult);
}

void DriveTrain::arcadeDrive(double moveValue, double rotateValue)
{
	testDrive->Drive(moveValue, rotateValue);
}

double DriveTrain::getRate()
{
    // Average of both encoder rates (must negate to get proper direction)
    // TODO: test to see if negation is necessary
    return
    (
        (double) ((encoderLeft->GetRate()) / ticksToDistance) -
        (double) ((encoderRight->GetRate()) / ticksToDistance)
    ) / 2.0;

}

double DriveTrain::getLeftEncoderDistance()
{
	//TODO negate this and the right one below
	//return this->left->GetPosition();

	return -this->encoderLeft->GetDistance();
}

double DriveTrain::getRightEncoderDistance()
{
	return this->encoderRight->GetDistance();
}

double DriveTrain::ReturnPIDInput()
{
    // Average of both encoders (must negate to get proper direction)
    return
    (
        (double) ((encoderLeft->Get()) / ticksToDistance) -
        (double) ((encoderRight->Get()) / ticksToDistance)
    ) / 2.0;
}

void DriveTrain::UsePIDOutput(double output)
{
	tankDrive(output,output);
}
