#include "TankDrive.h"
using namespace std;
TankDrive::TankDrive() : isReset(true) {
	Requires(drive);
}

void TankDrive::Initialize() {}


void TankDrive::Execute() {
	//double LeftVal = oi->getDriveStickLeft()->GetY();
	//double RightVal = oi->getDriveStickRight()->GetY();
	double LeftVal = oi->getDriveStickLeft();
	double RightVal = oi->getDriveStickRight();
	//cout<<"leftVal: "<<LeftVal<<endl;
	//cout<<"rightVal: "<<RightVal<<endl;
	double LeftAdjusted = mapToCubic(0.3, 0, LeftVal);
	double RightAdjusted = mapToCubic(0.3, 0, RightVal);
	//frc::SmartDashBoard::PutNumber("left value", LeftVal);
	drive->tankDrive(LeftAdjusted, RightAdjusted);
}

// Takes an input signal and maps it to a cubic output
double TankDrive::mapToCubic(double a, double b, double signal)
{
	double control;

	if (signal > 0)
		control = b + (1 - b) * ((a * pow(signal, 3) + (1 - a) * signal));
	else
		control = -b + (1 - b) * ((a * pow(signal, 3) + (1 - a) * signal));

	return control;
//Algorithm provided from last years code
//Is this fine? -david hang
}

bool TankDrive::IsFinished()
{
	return false;
}

void TankDrive::End() {}

void TankDrive::Interrupted() {}
