#include "GyroPID.h"

#include <LiveWindow/LiveWindow.h>
#include <SmartDashboard/SmartDashboard.h>

#include "../RobotMap.h"

GyroPID::GyroPID() : PIDSubsystem("GyroPID", 1.0, 0.0, 0.0), gyro(new AnalogGyro(0)) {
	gyro->Calibrate();
	gyro->Reset();
	this->SetAbsoluteTolerance(0.05);
}

double GyroPID::ReturnPIDInput() {
	return GetAngle();
}

void GyroPID::UsePIDOutput(double output) {
	this->tick = output;
}

void GyroPID::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

double GyroPID::GetAngle()
{
    return -gyro->GetAngle();
}

void GyroPID::ResetGyro()
{
    gyro->Reset();
}

double GyroPID::GetTick()
{
	return this->tick;
}
