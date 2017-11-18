#ifndef DriveTrain_H
#define DriveTrain_H
#include <ctrlib/CANTalon.h>
#include <WPILib.h>
#include "Commands/Subsystem.h"

class DriveTrain: public Subsystem
{
public:
	DriveTrain();
	~DriveTrain();
	static float Limit(float num, float max);
	void setMult(float m);
	void reverseDrive();
	int getMult();
	void tankDrive(float moveValueLeft, float moveValueRight);
	void setSpeedLeft(double speed);
	void setSpeedRight(double speed);
	void InitDefaultCommand();
private:
	Talon* left;
	Talon* right;
	float mult;
	int ticksToDistance;
};

#endif
