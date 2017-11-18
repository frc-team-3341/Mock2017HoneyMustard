#include "TankDrive.h"

TankDrive::TankDrive() :
		isReset(true) {
	Requires(drive);
}

void TankDrive::Initialize() {

}

void TankDrive::Execute() {
	double LeftVal = oi->getDriveStickLeft()->GetY();
	double RightVal = oi->getDriveStickRight()->GetY();

	double LeftAdjusted = mapToCubic(0.3, 0, LeftVal);
	double RightAdjusted = mapToCubic(0.3, 0, RightVal);

	drive->tankDrive(LeftAdjusted, RightAdjusted);
}

// Takes an input signal and maps it to a cubic output
double TankDrive::mapToCubic(double a, double b, double signal) {
	double control;

	if (signal > 0)
		control = b + (1 - b) * ((a * pow(signal, 3) + (1 - a) * signal));
	else
		control = -b + (1 - b) * ((a * pow(signal, 3) + (1 - a) * signal));

	return control;
//Algorithm provided from last years code
//Is this fine? -david hang
}

bool TankDrive::IsFinished() {
	return false;
}

void TankDrive::End() {
}

void TankDrive::Interrupted() {
}
