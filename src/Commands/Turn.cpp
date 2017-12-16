#include "Turn.h"

Turn::Turn(double angle) : anglePID(new WVPIDController(1, 0, 0, angle, false))
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(drive);
	//anglePID->SetSetPoint(angle);
	currentAngle = powerAngle = 0;
	//drive->resetEncoders();

}

// Called just before this Command runs the first time
void Turn::Initialize()
{
	drive->getGyro()->Reset();

	drive->getGyro()->Calibrate();
	drive->getUltra()->SetAutomaticMode(true);

}

// Called repeatedly when this Command is scheduled to run
void Turn::Execute()
{


	currentAngle = drive->getGyro()->GetAngle();
	std::cout << "Gyro angle: " << currentAngle << std::endl;
	powerAngle = anglePID->Tick(currentAngle);

	drive->arcadeDrive(0, powerAngle);

}

// Make this return true when this Command no longer needs to run execute()
bool Turn::IsFinished()
{
	return (anglePID->GetError() <= 0.05 || anglePID->GetError() >= -0.05);
}

// Called once after isFinished returns true
void Turn::End()
{
	drive->arcadeDrive(0, 0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Turn::Interrupted() {

}
