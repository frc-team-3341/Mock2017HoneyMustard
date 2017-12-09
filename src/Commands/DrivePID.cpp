#include "DrivePID.h"

DrivePID::DrivePID() : currentAngle(0), driveAngle(0)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(drive);
	anglePID = nullptr;
}

// Called just before this Command runs the first time
void DrivePID::Initialize()
{
	anglePID = new WVPIDController(1, 0, 0, 0, false);
	drive->getGyro()->Reset();
	drive->getGyro()->Calibrate();
	drive->getUltra()->SetAutomaticMode(true);
}

// Called repeatedly when this Command is scheduled to run
void DrivePID::Execute()
{
	currentAngle = drive->getGyro()->GetAngle();
	driveAngle = anglePID->Tick(currentAngle);

	drive->arcadeDrive(10, driveAngle);
}

// Make this return true when this Command no longer needs to run execute()
bool DrivePID::IsFinished()
{
	if(drive->getUltra()->GetRangeInches() < 2)
		return true;
	else
		return false;
}

// Called once after isFinished returns true
void DrivePID::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DrivePID::Interrupted() {

}
