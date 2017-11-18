/*
 * Arm.h
 *      Author: Thomas Le Nguyen
 */

#ifndef Arm_H
#define Arm_H

#include <Commands/Subsystem.h>
#include <WPILIB.h>

class Arm : public Subsystem
{
private:
	double arm; // length arm moves out
	double armHeight; // elevation of arm
	bool out; // should be false because arm is static when out is true arm is out

public:
	Arm();
	void InitDefaultCommand();
	void moveUpAndDown();
	void pushArmOut();
	void ArmToCubic(float arm);
};

#endif  // Arm_H
