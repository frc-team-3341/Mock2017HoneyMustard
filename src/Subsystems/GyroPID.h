#ifndef GyroPID_H
#define GyroPID_H

#include <CANTalon.h>
#include <WPILib.h>
#include "Commands/Subsystem.h"

class GyroPID : public PIDSubsystem {
public:
	GyroPID();
	double ReturnPIDInput();
	void UsePIDOutput(double output);
	void InitDefaultCommand();
	double GetAngle();
	void ResetGyro();
	double GetTick();
private:
	Gyro* gyro;
	double tick;
};

#endif  // GyroPID_H
