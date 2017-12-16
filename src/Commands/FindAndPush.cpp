#include "FindAndPush.h"

FindAndPush::FindAndPush() {
	Requires(drive);
	Requires(arm);
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void FindAndPush::Initialize() {
	azimuth = 0;
}

// Called repeatedly when this Command is scheduled to run
void FindAndPush::Execute()
{
	azimuth = NetworkTablesInterface::getAzimuth();
	if(azimuth < 0)
	{
		drive->reverseDrive();
		azimuth *= -1;
	}

	drive->arcadeDrive(azimuth, 0);
}

// Make this return true when this Command no longer needs to run execute()
bool FindAndPush::IsFinished() {
	return (azimuth <= 0.05 || azimuth >= -0.05);
}

// Called once after isFinished returns true
void FindAndPush::End()
{

	arm->pushArmForward(); //TODO: find value through testing
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void FindAndPush::Interrupted() {

}
