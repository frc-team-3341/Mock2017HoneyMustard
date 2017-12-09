#ifndef DrivePID_H
#define DrivePID_H

#include "../CommandBase.h"
#include "../Utilities/WVPIDController.h"

class DrivePID : public CommandBase {
private:
	//PIDController* distancePID;
	//PIDController* anglePID;
	WVPIDController* anglePID;
	double currentAngle;
	double driveAngle;
	//double currentDistance;
	//double drivePower;
public:
	DrivePID();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // DrivePID_H
