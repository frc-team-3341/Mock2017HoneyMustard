#include <math.h>
#include "../RobotMap.h"
#include "../CommandBase.h"
#include "../Commands/TankDrive.h"
//#include "../Commands/TankDriveReverse.h"

#include "DriveTrain.h"

#define max(x, y) (((x) > (y)) ? (x) : (y))

DriveTrain::DriveTrain() : Subsystem("DriveTrain"), left(new Talon(0)), right(new Talon(1)), mult(1.0), ticksToDistance(114)
{

}

DriveTrain::~DriveTrain()
{
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
