/*
 * Arm.h
 *      Author: Thomas Le Nguyen
 */

#ifndef Arm_H
#define Arm_H

#include <Commands/Subsystem.h>
#include <WPILIB.h>
#include "CANTalon.h"

class Arm : public Subsystem
{
private:
	double arm; // length arm moves out
	double armHeight; // elevation of arm
	bool out; // should be false because arm is static when out is true arm is out
	CANTalon* verticalArm;
	CANTalon* horizontalArm;


public:
	Arm();
	void InitDefaultCommand();
	void moveUpAndDown(double moveValue);
	void pushArmHorizontal();
};

#endif  // Arm_H
