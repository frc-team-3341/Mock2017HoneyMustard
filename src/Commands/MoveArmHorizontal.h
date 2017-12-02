#ifndef MoveArmHorizontal_H
#define MoveArmHorizontal_H

#include "../CommandBase.h"


class MoveArmHorizontal : public CommandBase {

private:
	double moveValue; //determined through testing

public:
	MoveArmHorizontal(double move);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // MoveArmHorizontal_H
