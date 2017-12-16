#include <WPILib.h>
#include "OI.h"
#include "Commands/MoveArmHorizontal.h"
using namespace frc;

OI::OI() :
		//LeftStick(new Joystick(0)), RightStick(new Joystick(1))
				logitech(new Joystick(0))//, Arm(new Joystick(2))
{
	pushArmUp = new JoystickButton(logitech, 6); //not actual port, temp
	pullArmDown = new JoystickButton(logitech, 8); //not actual port, temp

	pushActuator = new JoystickButton(logitech, 7);

	pushArmUp->WhenPressed(new MoveArmVertical(5));
	pullArmDown->WhenPressed(new MoveArmVertical(-5));
}
double OI::getDriveStickLeft()
{
	return -logitech->GetY();
}

double OI::getDriveStickRight()
{
	return -logitech->GetRawAxis(3);
}

//Joystick* OI::getArm() {

//}

OI::~OI() {
	//delete LeftStick;
	//delete RightStick;
	delete logitech;
	delete Arm;
}
