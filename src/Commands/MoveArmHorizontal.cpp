#include "MoveArmHorizontal.h"

MoveArmHorizontal::MoveArmHorizontal()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(arm);

}

// Called just before this Command runs the first time
void MoveArmHorizontal::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void MoveArmHorizontal::Execute()
{
	arm->moveUpAndDown(moveValue);
}

// Make this return true when this Command no longer needs to run execute()
bool MoveArmHorizontal::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void MoveArmHorizontal::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MoveArmHorizontal::Interrupted() {

}
