#ifndef OI_H
#define OI_H

#include "RobotMap.h"
#include "WPILib.h"


class OI {
private:
	Joystick* logitech;
	//Joystick* LeftStick;
	//Joystick* RightStick;
	//Joystick* Arm;
	/*
	 * TODO
	 * from Nir
	 * We should try to implement this functionality on the logitech controller as well.
	 */
	Button* pushArmUp;
	Button* pullArmDown;
	Button* pushActuator;

public:
	OI();
	~OI();
	//Joystick* getDriveStickLeft();
	//Joystick* getDriveStickRight();
	double getDriveStickLeft();
	double getDriveStickRight();
	//Joystick* getArm();
};

#endif
