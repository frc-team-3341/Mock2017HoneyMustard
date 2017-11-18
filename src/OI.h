#ifndef OI_H
#define OI_H

#include "RobotMap.h"
#include "WPILib.h"

class OI {
private:
	Joystick* LeftStick;
	Joystick* RightStick;
	Joystick* Arm;

public:
	OI();
	~OI();
	Joystick* getDriveStickLeft();
	Joystick* getDriveStickRight();
	Joystick* getArm();
};

#endif
