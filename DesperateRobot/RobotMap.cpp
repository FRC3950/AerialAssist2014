// RobotBuilder Version: 1.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION
SpeedController* RobotMap::driveSubsystemSpeedController1 = NULL;
SpeedController* RobotMap::driveSubsystemSpeedController2 = NULL;
SpeedController* RobotMap::driveSubsystemSpeedController3 = NULL;
SpeedController* RobotMap::driveSubsystemSpeedController4 = NULL;
RobotDrive* RobotMap::driveSubsystemRobotDriveMecanum = NULL;
Gyro* RobotMap::driveSubsystemGyro1 = NULL;
AnalogChannel* RobotMap::armPIDSubsystemPotentiometer1 = NULL;
SpeedController* RobotMap::armPIDSubsystemSpeedController1 = NULL;
DigitalInput* RobotMap::armPIDSubsystemupperArmLimit = NULL;
DigitalInput* RobotMap::armPIDSubsystemlowerArmLimit = NULL;
DigitalInput* RobotMap::shooterSubsystemUpperLimitSwitch = NULL;
DigitalInput* RobotMap::shooterSubsystemLowerLimitSwitch = NULL;
SpeedController* RobotMap::shooterSubsystemShooterMotor = NULL;
Solenoid* RobotMap::shooterSubsystemTriggerSolenoid = NULL;
DoubleSolenoid* RobotMap::intakeSubsystemClawSolenoid = NULL;
Compressor* RobotMap::pneumaticsCompressor = NULL;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION
SpeedController* RobotMap::intakeSubsystemIntakeWheels = NULL;
void RobotMap::init() {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	LiveWindow* lw = LiveWindow::GetInstance();
	driveSubsystemSpeedController1 = new Victor(1, 1);
	lw->AddActuator("DriveSubsystem", "Speed Controller 1", (Victor*) driveSubsystemSpeedController1);
	
	driveSubsystemSpeedController2 = new Victor(1, 2);
	lw->AddActuator("DriveSubsystem", "Speed Controller 2", (Victor*) driveSubsystemSpeedController2);
	
	driveSubsystemSpeedController3 = new Victor(1, 3);
	lw->AddActuator("DriveSubsystem", "Speed Controller 3", (Victor*) driveSubsystemSpeedController3);
	
	driveSubsystemSpeedController4 = new Victor(1, 4);
	lw->AddActuator("DriveSubsystem", "Speed Controller 4", (Victor*) driveSubsystemSpeedController4);

	// The Gyro must be created nbefore the drive subsystem since it
	// it will reachout and grab it.
	driveSubsystemGyro1 = new Gyro(1, 1);
	
	driveSubsystemRobotDriveMecanum = new RobotDrive(driveSubsystemSpeedController1, driveSubsystemSpeedController2,
              driveSubsystemSpeedController3, driveSubsystemSpeedController4);

	driveSubsystemRobotDriveMecanum->SetSafetyEnabled(true);
        driveSubsystemRobotDriveMecanum->SetExpiration(0.1);
        driveSubsystemRobotDriveMecanum->SetSensitivity(0.5);
        driveSubsystemRobotDriveMecanum->SetMaxOutput(1.0);
        driveSubsystemRobotDriveMecanum->SetInvertedMotor(RobotDrive::kFrontLeftMotor, true);
        driveSubsystemRobotDriveMecanum->SetInvertedMotor(RobotDrive::kRearLeftMotor, true);
        
    	lw->AddSensor("DriveSubsystem", "Gyro 1", driveSubsystemGyro1);
    	driveSubsystemGyro1->SetSensitivity(0.007);

	armPIDSubsystemSpeedController1 = new Talon(1, 5);
	lw->AddActuator("Arm PID Subsystem", "Speed Controller 1", (Talon*) armPIDSubsystemSpeedController1);

	armPIDSubsystemupperArmLimit = new DigitalInput(1, 1);
	lw->AddSensor("Arm PID Subsystem", "upperArmLimit", armPIDSubsystemupperArmLimit);
	
	armPIDSubsystemlowerArmLimit = new DigitalInput(1, 2);
	lw->AddSensor("Arm PID Subsystem", "lowerArmLimit", armPIDSubsystemlowerArmLimit);
	
	intakeSubsystemClawSolenoid = new DoubleSolenoid(1, 1, 2);
	lw->AddActuator("Shooter Subsystem", "Claw Solenoid", intakeSubsystemClawSolenoid);
	
	pneumaticsCompressor = new Compressor(1, 5, 1, 1);
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
    
	intakeSubsystemIntakeWheels = new Victor(1, 6);
	lw->AddActuator("Intake Subsystem", "Intake Wheels", (Victor*) intakeSubsystemIntakeWheels);
	
#if NOT_YET
	armPIDSubsystemPotentiometer1 = new AnalogChannel(1, 4);
	lw->AddSensor("Arm PID Subsystem", "Potentiometer 1", armPIDSubsystemPotentiometer1);
	
	

	shooterSubsystemUpperLimitSwitch = new DigitalInput(1, 3);
	lw->AddSensor("Shooter Subsystem", "Upper Limit Switch", shooterSubsystemUpperLimitSwitch);
		
	shooterSubsystemLowerLimitSwitch = new DigitalInput(1, 4);
	lw->AddSensor("Shooter Subsystem", "Lower Limit Switch", shooterSubsystemLowerLimitSwitch);
		
	shooterSubsystemShooterMotor = new Victor(1, 7);
	lw->AddActuator("Shooter Subsystem", "Shooter Motor", (Victor*) shooterSubsystemShooterMotor);
		
	shooterSubsystemTriggerSolenoid = new Solenoid(1, 3);
	lw->AddActuator("Shooter Subsystem", "Trigger Solenoid", shooterSubsystemTriggerSolenoid);
		
#endif	
}
