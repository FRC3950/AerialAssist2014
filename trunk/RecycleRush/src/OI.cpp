// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "Commands/ToggleLiftSolenoidCommand.h"
#include "Commands/CloseGripCommand.h"
#include "Commands/DropDownCommand.h"
#include "Commands/LiftUpCommand.h"
#include "Commands/OpenGripCommand.h"
#include "Commands/ToggleGripCommand.h"
#include "OI.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "SmartDashboard/SmartDashboard.h"
#include "Commands/AutonomousCommand.h"
#include "Commands/DriveCommand.h"
#include "UtilFun.h"

// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

OI::OI()

{
	// Process operator interface input here.
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS

     

	// SmartDashboard Buttons
	SmartDashboard::PutData("DriveCommand", new DriveCommand());

	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS

	driveJoystick = new Joystick(0);


//to disable lift solenoid
	gantryController = new Joystick(1);

	fireLiftSolenoidButton = new JoystickButton(gantryController, 1);
	liftUpButton = new JoystickButton(gantryController, 2);

	fireLiftSolenoidButton->WhenPressed(new ToggleLiftSolenoidCommand());
	liftUpButton->WhenPressed(new LiftUpCommand());
#if 1
	dropDownButton = new JoystickButton(gantryController, 3);
	openGripButton = new JoystickButton(gantryController, 4);
	closeGripButton = new JoystickButton(gantryController, 5);
	toggleGripButton = new JoystickButton(gantryController, 6);


	dropDownButton->WhenPressed(new DropDownCommand());
	openGripButton->WhenPressed(new OpenGripCommand());
	closeGripButton->WhenPressed(new CloseGripCommand());
	toggleGripButton->WhenPressed(new ToggleGripCommand());

#else

	gantryController = 0;
	//fireLiftSolenoidButton = 0;
	//liftUpButton = 0;
	dropDownButton = 0;
	openGripButton = 0;
	closeGripButton = 0;
	toggleGripButton = 0;

#endif
}
float OI::GetDriveStickX()
{
	return driveJoystick->GetX();
}

float OI::GetDriveStickY()
{
	return driveJoystick->GetY();
}

float OI::GetDriveRotation()
{
	return driveJoystick->GetTwist();
}

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS

// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS
