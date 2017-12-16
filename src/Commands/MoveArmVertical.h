#ifndef MoveArm_H
#define MoveArm_H

#include "../CommandBase.h"

class MoveArmVertical : public CommandBase {
public:
	MoveArmVertical(int power);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	int movePower;
};

#endif  // MoveArm_H
