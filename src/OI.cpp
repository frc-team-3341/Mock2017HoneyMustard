#include <WPILib.h>
#include "OI.h"
using namespace frc;

OI::OI() :
		//LeftStick(new Joystick(0)), RightStick(new Joystick(1))
				logitech(new Joystick(0)), Arm(new Joystick(2))
{
	pushArm = new JoystickButton(3); //not actual port, temp
	pullArm = new JoystickButton(4); //not actual port, temp
}
double OI::getDriveStickLeft()
{
	return logitech->GetY();
}

double OI::getDriveStickRight()
{
	return logitech->GetRawAxis(3);
}

Joystick* OI::getArm() {
	return Arm;
}

OI::~OI() {
	//delete LeftStick;
	//delete RightStick;
	delete logitech;
	delete Arm;
}
