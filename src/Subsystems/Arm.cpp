/*
 * Arm.cpp
 *      Author: Thomas Le Nguyen
 */

#include "../RobotMap.h"
#include <Commands/MoveArm.h>
#include <Subsystems/Arm.h>
#include <WPILIB.h>
#include <iostream>

Arm::Arm() : Subsystem("Arm"), arm(0), armHeight(0), out(false) {}

void Arm::InitDefaultCommand()
{
	SetDefaultCommand(new MoveArm());
}

void Arm::moveUpAndDown()
{
	// if joy stick is remoted forward
	// then elevate arm up
	// if joy stick is remoted downward
	// then elevate arm down
	// if arm is static
	// don't do anything with arm height
}

void Arm::pushArmOut()
{
	// if button is being pressed down
	// then push out arm
	// if button is not being pressed out AND is out
	// then pull arm back in
	// else keep arm in
	// basically leave it static
}

void Arm::ArmToCubic(float arm)
{
		moveValueRight = -DriveTrain::Limit(moveValueRight, 1.0);

		if (mult != 0) {
			right->Set(moveValueRight);
		} else {
			left->Set(moveValueLeft);
			right->Set(moveValueRight);
		}
}


