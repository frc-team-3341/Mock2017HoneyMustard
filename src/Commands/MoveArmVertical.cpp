#include "MoveArmVertical.h"

MoveArmVertical::MoveArmVertical(int power) : movePower(power)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(arm);
}

// Called just before this Command runs the first time
void MoveArmVertical::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void MoveArmVertical::Execute()
{
	arm->moveUpAndDown(movePower);
	// double ArmAdjusted = ArmFun(0.3, 0, ArmVal);
	//drive->tankDrive(ArmAdjusted);
}

// Make this return true when this Command no longer needs to run execute()

bool MoveArmVertical::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void MoveArmVertical::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MoveArmVertical::Interrupted() {}
