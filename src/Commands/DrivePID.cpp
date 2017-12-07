#include "DrivePID.h"

DrivePID::DrivePID() : distancePID(new PIDController(1, 0, 0, , Output, Period))
) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(drive);
}

// Called just before this Command runs the first time
void DrivePID::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void DrivePID::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool DrivePID::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void DrivePID::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DrivePID::Interrupted() {

}
