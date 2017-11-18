#include "MoveArm.h"

MoveArm::MoveArm() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void MoveArm::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void MoveArm::Execute() {
	double ArmVal = oi->getArm()->GetY();

		double ArmAdjusted = ArmFun(0.3, 0, ArmVal);

		drive->tankDrive(ArmAdjusted);

}

// Make this return true when this Command no longer needs to run execute()
double MoveArm::ArmVal(double a, double b, double signal){

	double control;

		if (signal > 0)
			control = b + (1 - b) * ((a * pow(signal, 3) + (1 - a) * signal));
		else
			control = -b + (1 - b) * ((a * pow(signal, 3) + (1 - a) * signal));

		return control;

}

bool MoveArm::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void MoveArm::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MoveArm::Interrupted() {
