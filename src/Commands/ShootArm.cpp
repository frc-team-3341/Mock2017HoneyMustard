#include "ShootArm.h"

ShootArm::ShootArm() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(arm);
}

// Called just before this Command runs the first time
void ShootArm::Initialize() {
	arm->pushArmForward();
}

// Called repeatedly when this Command is scheduled to run
void ShootArm::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool ShootArm::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void ShootArm::End() {
	arm->pullArmBack();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ShootArm::Interrupted() {

}
