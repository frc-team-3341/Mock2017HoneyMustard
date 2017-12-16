#ifndef FindAndPush_H
#define FindAndPush_H

#include "../CommandBase.h"
#include "../Utilities/NetworkTablesInterface.h"

class FindAndPush : public CommandBase {
public:
	FindAndPush();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	int azimuth;
};

#endif  // FindAndPush_H
