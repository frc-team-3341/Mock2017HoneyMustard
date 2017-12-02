#ifndef TurnPID_H
#define TurnPID_H

#include "../CommandBase.h"

class TurnPID : public CommandBase {
public:
	TurnPID();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // TurnPID_H
