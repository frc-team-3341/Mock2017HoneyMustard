#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of numbers
 * floating around.
 */

// For example to map the left and right motors, you could define the
// following variables to use with your drivetrain subsystem.
const double DRIVE_MOTOR_LEFT = 0;
const double DRIVE_MOTOR_RIGHT = 1;
const double ARM_VERTICAL = 2;
const double ARM_HORIZONTAL = 3;

#endif
