#ifndef Turn_H
#define Turn_H

#include "../CommandBase.h"
#include "../Utilities/WVPIDController.h"

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
};

#endif  // Turn_H
