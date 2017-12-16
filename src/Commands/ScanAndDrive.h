#ifndef ScanAndDrive_H
#define ScanAndDrive_H

#include "../CommandBase.h"
#include "../Utilities/NetworkTablesInterface.h"

class ScanAndDrive : public CommandBase {
public:
	ScanAndDrive();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	int measuredDistance, position;
	bool amDone;
};

#endif  // ScanAndDrive_H
