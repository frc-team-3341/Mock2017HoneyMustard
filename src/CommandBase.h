#ifndef COMMAND_BASE_H
#define COMMAND_BASE_H

#include <memory>
#include <string>

#include <Commands/Command.h>
#include "OI.h"
#include "Subsystems/DriveTrain.h"


class CommandBase: public frc::Command {
public:
	CommandBase(const std::string& name);
	CommandBase() = default;

	static DriveTrain* drive;

	static std::unique_ptr<OI> oi;
	static void initialize();

};

#endif  // COMMAND_BASE_H
