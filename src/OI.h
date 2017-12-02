#ifndef OI_H
#define OI_H

#include "RobotMap.h"
#include "WPILib.h"

class OI {
private:
	Joystick* logitech;
	//Joystick* LeftStick;
	//Joystick* RightStick;
	Joystick* Arm;
	Button* pushArm;
	Button* pullArm;

public:
	OI();
	~OI();
	//Joystick* getDriveStickLeft();
	//Joystick* getDriveStickRight();
	double getDriveStickLeft();
	double getDriveStickRight();
	Joystick* getArm();
};

#endif
