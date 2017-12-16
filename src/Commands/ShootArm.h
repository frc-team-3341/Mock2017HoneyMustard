#ifndef ShootArm_H
#define ShootArm_H

#include "../CommandBase.h"

class ShootArm : public CommandBase {
public:
	ShootArm();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // ShootArm_H
