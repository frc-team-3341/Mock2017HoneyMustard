#ifndef Turn_H
#define Turn_H

#include "../CommandBase.h"
#include <ADXRS450_Gyro.h>

class Turn : public CommandBase {
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
