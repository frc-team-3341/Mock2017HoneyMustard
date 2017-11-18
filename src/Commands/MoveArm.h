#ifndef MoveArm_H
#define MoveArm_H

#include "../CommandBase.h"

class MoveArm : public CommandBase {
public:
	MoveArm();
	void Initialize();
	void Execute();
	double ArmFun(double a, double b, double signal);
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // MoveArm_H
e
