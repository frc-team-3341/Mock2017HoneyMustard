#include "DrivePID.h"

DrivePID::DrivePID() :  /*distancePID(0),*/ currentAngle(0), driveAngle(0), currentDistance(0), drivePower(0)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(drive);
	distancePID = nullptr;
	anglePID = nullptr;
}

// Called just before this Command runs the first time
void DrivePID::Initialize()
{
	anglePID = new WVPIDController(1, 0, 0, 0, false);
	distancePID = new WVPIDController(1, 0, 0, 10, false);
	drive->getGyro()->Reset();
	drive->getGyro()->Calibrate();
	drive->getEncoderLeft()->Reset();
	drive->getEncoderRight()->Reset();
	drive->getUltra()->SetAutomaticMode(true);
}

// Called repeatedly when this Command is scheduled to run
void DrivePID::Execute()
{
	currentAngle = drive->getGyro()->GetAngle();
	driveAngle = anglePID->Tick(currentAngle);

	currentDistance = drive->ReturnPIDInput();
	drivePower = distancePID->Tick(currentDistance);

	drive->arcadeDrive(drivePower, driveAngle);
}

// Make this return true when this Command no longer needs to run execute()
bool DrivePID::IsFinished()
{
	if(distancePID->GetError() < 2)
		return true;
	else
		return false;
}

// Called once after isFinished returns true
void DrivePID::End() {
	drive->arcadeDrive(0, 0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DrivePID::Interrupted() {

}
