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
//const int LEFTMOTOR = 1;
//const int RIGHTMOTOR = 2;
const double ENCODER_RIGHT_1 = 0;
const double ENCODER_RIGHT_2 = 1;
const double ENCODER_LEFT_1 = 2;
const double ENCODER_LEFT_2 = 3;
const int MOTORPORT = 0;

#endif
