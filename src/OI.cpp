#include <WPILib.h>
#include "OI.h"
using namespace frc;

OI::OI() :
		LeftStick(new Joystick(0)), RightStick(new Joystick(1)), Arm(new Joystick(2)) {}
Joystick* OI::getDriveStickLeft() {
	return LeftStick;
}

Joystick* OI::getDriveStickRight() {
	return RightStick;
}

Joystick* OI::getArm() {
	return Arm;
}
void OI::driveButtons() {
	Button* toggleArmDirection = new JoystickButton(Arm, 2);
}
OI::~OI() {
	delete LeftStick;
	delete RightStick;
	delete Arm;
}


