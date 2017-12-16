#ifndef MoveArmHorizontal_H
#define MoveArmHorizontal_H

#include "../CommandBase.h"


class MoveArmHorizontal : public CommandBase {

private:
	 //determined through testing

public:
	MoveArmHorizontal();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // MoveArmHorizontal_H
