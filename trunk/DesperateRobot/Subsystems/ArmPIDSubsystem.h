// RobotBuilder Version: 1.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
#ifndef ARM_PID_SUBSYSTEM_H
#define ARM_PID_SUBSYSTEM_H
#include "Commands/PIDSubsystem.h"
#include "WPILib.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class ArmPIDSubsystem: public PIDSubsystem {
 public:
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	AnalogChannel* potentiometer1;
	SpeedController* armSpeedController;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	DigitalInput* upperArmLimit;
	DigitalInput* lowerArmLimit;
		
	
	ArmPIDSubsystem();
	void InitDefaultCommand();
	void SetPIDSubsystem(bool enable);
	void ManualMoveArmControl(float voltage);

	float SetAbsolutePIDTarget(float target);
	float SetRelativePIDTarget(float target);
	
	void FindOriginPosition(bool forceFind);
	bool HasReachedTargetVoltage(float pidTargetVoltage);
	float GetPotentiometerReading();

	void SetReadyToFireField(bool setting);
	void UpdateReadyToFireField(float targetVoltage);
//	void UpdateReadyToFireField(float targetVoltage, float currVoltage);
	bool UpdateReadyToFireField(float targetVoltage, 
			                    float currVoltage,
			                    float lowerEpsilon,
			                    float upperEpsilon);
	
	
protected:
	// These are overridden base class methods.
	virtual double ReturnPIDInput();
	virtual void UsePIDOutput(double output);
	
	
 private:
	bool PollUpperArmLimit();
	bool PollLowerArmLimit();
	float AngleToVoltage(float angle);
	float PotVoltageToAngle(float voltage);
	
	bool upperArmLimitHit;
	bool lowerArmLimitHit;
	bool pidEnabled;
	float potOrigin;
	bool potOriginCheckComplete;


};
#endif
