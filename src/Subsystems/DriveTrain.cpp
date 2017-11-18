/*
 * NOT Thomas' code
 * David did this!
 */

#include <math.h>
#include <CANTalon.h>
#include "../RobotMap.h"
#include "../CommandBase.h"
#include "../Commands/TankDrive.h"
//#include "../Commands/TankDriveReverse.h"

#include "DriveTrain.h"

#define max(x, y) (((x) > (y)) ? (x) : (y))

DriveTrain::DriveTrain() :
		Subsystem("DriveTrain"),
			left(new CANTalon(0)),
			right(new CANTalon(1)),
			encoderLeft(new Encoder(0,0)),
			encoderRight(new Encoder(0,0)),
			mult(1.0),
			ticksToDistance(114){}
			//accel(15){}
// How can Wreorder warning be resolved?
DriveTrain::~DriveTrain(){
	delete left;
	delete right;
	delete encoderLeft;
	delete encoderRight;
	//delete accel;

}

void DriveTrain::reverseDrive(){
	left->SetInverted(!left->GetInverted());
	right->SetInverted(!right->GetInverted());
}

void DriveTrain::setMult(float m) {
	mult = m;
}

int DriveTrain::getMult() {
	return mult;
}

void DriveTrain::resetEncoders() {
	encoderLeft->Reset();
	encoderRight->Reset();
}

void DriveTrain::tankDrive(float moveValueLeft, float moveValueRight) {
	//float leftMotorOutput;
	//float rightMotorOutput;

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

float DriveTrain::Limit(float num, float max) {
	if (num > max)
		return max;

	if (num < -max)
		return -max;

	return num;
}

//NOTE* Return distance in feet
double DriveTrain::getDistance() {
	return ((double) ((encoderLeft->Get()) / ticksToDistance)
			- (double) ((encoderRight->Get()) / ticksToDistance)) / 2.0;
}

double DriveTrain::getRate() {
	return ((double) ((encoderLeft->GetRate()) / ticksToDistance)
			- (double) ((encoderRight->GetRate()) / ticksToDistance)) / 2.0;

}
void DriveTrain::InitDefaultCommand() {

	SetDefaultCommand(new TankDrive());
}

double DriveTrain::getLeftEncoderDistance() {
	return -this->encoderLeft->GetDistance();
}

double DriveTrain::getRightEncoderDistance() {
	return this->encoderRight->GetDistance();
}

void DriveTrain::setSpeedLeft(double speed) {
	left->SetSpeed(speed * mult);
}

void DriveTrain::setSpeedRight(double speed) {
	right->SetSpeed(speed * mult);
}

