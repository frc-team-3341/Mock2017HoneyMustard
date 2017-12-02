#ifndef MoveArm_H
#define MoveArm_H

#include "../CommandBase.h"

class MoveArmVertical : public CommandBase {
public:
	MoveArmVertical();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // MoveArm_H
