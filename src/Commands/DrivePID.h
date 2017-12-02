#ifndef DrivePID_H
#define DrivePID_H

#include "../CommandBase.h"

class DrivePID : public CommandBase {
public:
	DrivePID();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // DrivePID_H
