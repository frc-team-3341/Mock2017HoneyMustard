#include "ScanAndDrive.h"

ScanAndDrive::ScanAndDrive()
{
	Requires(drive);
	Requires(arm);
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void ScanAndDrive::Initialize()
{
	//TODO: add initialize encoders here
	measuredDistance = position = 0;

}

// Called repeatedly when this Command is scheduled to run
void ScanAndDrive::Execute()
{


	while(measuredDistance <= 10)
	{
		drive->arcadeDrive(5, 0);
		//measuredDistance = encoder values
	}

	Wait(1);
	position = NetworkTablesInterface::getPosition();
	if(position == 2)
	{
		amDone = true;
	}
}

// Make this return true when this Command no longer needs to run execute()
bool ScanAndDrive::IsFinished() {
	return amDone;
}

// Called once after isFinished returns true
void ScanAndDrive::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ScanAndDrive::Interrupted() {

}
