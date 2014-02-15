// RobotBuilder Version: 1.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
#include "Robot.h"
#include "Logger.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INITIALIZATION
DriveSubsystem* Robot::driveSubsystem = 0;
ArmPIDSubsystem* Robot::armPIDSubsystem = 0;
Pneumatics* Robot::pneumaticsSubsystem = 0;
IntakeSubsystem *Robot::intakeSubsystem = 0;
ShooterSubsystem *Robot::shooterSubsystem = 0;

OI* Robot::oi = 0;

// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INITIALIZATION

Robot::Robot()
	: autonomousCommand(NULL)
{
	// Pass true as the first parameter to log to the console.
	// Pass true as the second parameter to log to a file.
	// By default logging is off, hence default paramters that are both false.
	// Nothing is passed for the default case.
	Logger *logger = Logger::GetInstance(true);
	logger->Log(Logger::kINFO, "Robot class constructor!");
}
void Robot::RobotInit() {
	RobotMap::init();
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	driveSubsystem = new DriveSubsystem();
	
#if defined(NOT_YET)	
	armPIDSubsystem = new ArmPIDSubsystem();
	pneumaticsSubsystem = new Pneumatics();
	intakeSubsystem = new IntakeSubsystem();
	shooterSubsystem = new ShooterSubsystem();
#endif	
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	//armMotorSubsystem = new ArmMotorSubsystem();
	// This MUST be here. If the OI creates Commands (which it very likely
	// will), constructing it during the construction of CommandBase (from
	// which commands extend), subsystems are not guaranteed to be
	// yet. Thus, their requires() statements may grab null pointers. Bad
	// news. Don't move it.
	oi = new OI();
	lw = LiveWindow::GetInstance();
	// instantiate the command used for the autonomous period
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=AUTONOMOUS
#if defined(NOT_YET)
	autonomousCommand = new AutonomousCommand();
#endif
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=AUTONOMOUS
  }
	
void Robot::AutonomousInit() {
	if (autonomousCommand != NULL)
	{
		armPIDSubsystem->FindOriginPosition(true);
		autonomousCommand->Start();
	}
}
	
void Robot::AutonomousPeriodic() {
	Scheduler::GetInstance()->Run();
}
	
void Robot::TeleopInit() {
	// This makes sure that the autonomous stops running when
	// teleop starts running. If you want the autonomous to 
	// continue until interrupted by another command, remove
	// this line or comment it out.
	if (autonomousCommand != NULL)
	{
		autonomousCommand->Cancel();
	}
	
#if defined(NOT_YET)
	armPIDSubsystem->FindOriginPosition(false);
#endif	
}
	
void Robot::TeleopPeriodic() {
	Scheduler::GetInstance()->Run();
}
void Robot::TestPeriodic() {
	lw->Run();
}
START_ROBOT_CLASS(Robot);
