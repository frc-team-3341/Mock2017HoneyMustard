#include "TotalAutonomous.h"

TotalAutonomous::TotalAutonomous() {
	/*
	 * TODO
	 * HEY ALL ASC PEEPS (from Nir)
	 * Here is where you will add the commands
	 * DrivePID and TurnPID, and MoveArm, in
	 * order to accomplish the autonomous
	 * task. In the DriveTrain and GyroPID subsystems, I did some work implementing
	 * an internal PID controller by extending PIDSubsystem. In order to use these
	 * PIDs, you need to call Enable() in the commands, and the PIDSubsystem class
	 * (http://first.wpi.edu/FRC/roborio/release/docs/cpp/classfrc_1_1PIDSubsystem.html)
	 * has all the functions you need to set the necessary values (such as setpoint, proportion
	 * integral derivative constants, etc.)
	 */
	std::cout << "help" << std::endl;
	AddSequential(new DrivePID());
	AddSequential(new ShootArm());
	AddSequential(new Turn(90));

	// Add Commands here:
	// e.g. AddSequential(new Command1());
	//      AddSequential(new Command2());
	// these will run in order.

	// To run multiple commands at the same time,
	// use AddParallel()
	// e.g. AddParallel(new Command1());
	//      AddSequential(new Command2());
	// Command1 and Command2 will run in parallel.

	// A command group will require all of the subsystems that each member
	// would require.
	// e.g. if Command1 requires chassis, and Command2 requires arm,
	// a CommandGroup containing them would require both the chassis and the
	// arm.
}
