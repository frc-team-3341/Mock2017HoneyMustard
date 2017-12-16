#ifndef Turn_H
#define Turn_H

#include "../CommandBase.h"
<<<<<<< HEAD
#include <ADXRS450_Gyro.h>
=======
#include "../Utilities/WVPIDController.h"
>>>>>>> a2014a6498bfa04a62f3dd07e882e332a031bd2f

class Turn : public CommandBase {
private:
	WVPIDController* anglePID;
	double currentAngle;
	double powerAngle;

public:
	Turn(double angle);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	double angle;
	double getAngle;
};

#endif  // Turn_H
