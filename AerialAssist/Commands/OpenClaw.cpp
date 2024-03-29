// RobotBuilder Version: 1.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.


#include "OpenClaw.h"

#include "../Logger.h"
#include "../LoggingComponentDefs.h"


OpenClaw::OpenClaw(bool delayActive)
	: delay(delayActive)
{
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::intakeSubsystem);
	
}

// Called just before this Command runs the first time
void OpenClaw::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
static const double DelayTimeInSec = 0.5;
void OpenClaw::Execute() {
	Robot::intakeSubsystem->OpenClaw();
	if (delay) 
	{
		Wait(DelayTimeInSec);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool OpenClaw::IsFinished() {
	Logger::GetInstance()->Log(RobotLogId, Logger::kINFO, "Claw open.");

	return true;
}

// Called once after isFinished returns true
void OpenClaw::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void OpenClaw::Interrupted() {

}
