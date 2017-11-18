#ifndef DriveTrain_H
#define DriveTrain_H
#include <CANTalon.h>
#include <WPILib.h>
#include "Commands/Subsystem.h"
class DriveTrain: public Subsystem {
private:

	TalonSRX* left;
	TalonSRX* right;
	Encoder* encoderLeft;
	Encoder* encoderRight;
	float mult;
	int ticksToDistance;
	//BuiltInAccelerometer* accel;

public:

	DriveTrain();
	~DriveTrain();

	static float Limit(float num, float max);

	void setMult(float m);
	void reverseDrive();
	int getMult();
	void tankDrive(float moveValueLeft, float moveValueRight);

	double getDistance();
	double getRate();
	void resetEncoders();
	void getAccelerations(double* x, double* y, double* z);

	double getRightEncoderDistance();
	double getLeftEncoderDistance();

	double getGyroAngle();
	void resetGyro();

	double readUltra(uint16_t sensorIndex);

	void setSpeedLeft(double speed);
	void setSpeedRight(double speed);

	void InitDefaultCommand();

};

#endif
