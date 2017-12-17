#ifndef TotalAutonomous_H
#define TotalAutonomous_H

#include <Commands/CommandGroup.h>
#include "Turn.h"
#include "ShootArm.h"
#include "DrivePID.h"

class TotalAutonomous : public CommandGroup {

public:
	TotalAutonomous();
};

#endif  // TotalAutonomous_H
