#ifndef DriveTrain_H
#define DriveTrain_H
#include <CANTalon.h>
#include <WPILib.h>
#include "Commands/Subsystem.h"

class DriveTrain: public PIDSubsystem
{
public:
	DriveTrain();
	~DriveTrain();
	static float Limit(float num, float max);
	void setMult(float m);
	void reverseDrive();
	int getMult();
	void tankDrive(float moveValueLeft, float moveValueRight);
	void setSpeedLeft(double speed);
	void setSpeedRight(double speed);
	void InitDefaultCommand();
	void arcadeDrive(double moveValue, double rotateValue);
	double getDistance();
	double getRate();
	void resetEncoders();
	double getRightEncoderDistance();
	double getLeftEncoderDistance();
	double ReturnPIDInput();
	void UsePIDOutput(double output);
	ADXRS450_Gyro* getGyro();
	Ultrasonic* getUltra();
private:
	CANTalon* left;
	CANTalon* right;
	float mult;
	int ticksToDistance;
	RobotDrive* testDrive;
	//Encoder* encoderLeft;
	//Encoder* encoderRight;
	ADXRS450_Gyro* gyro;
	Ultrasonic* ultra;
};

#endif
