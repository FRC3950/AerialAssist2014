// RobotBuilder Version: 1.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
#include "OI.h"
//PLEASE DON'T DEPLOY THE CODE, WORK WITH THE CODE ALLREDY DEPLOYED// 
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

#include "SmartDashboard/SmartDashboard.h"
#include "Commands/AutonomousCommand.h"
#include "Commands/BallScrewUp.h"
#include "Commands/CockShooter.h"
#include "Commands/DriveCommand.h"
#include "Commands/ResetGyroCommand.h"
#include "Commands/LaunchAngle.h"
#include "Commands/ToggleClaw.h"
#include "Commands/Launch.h"
#include "Commands/MoveArm.h"
#include "Commands/RollBallIn.h"
#include "Commands/RollBallOut.h"
#include "Commands/StopIntakeWheels.h"
#include "Commands/FindArmPotOrigin.h"
#include "Commands/DisableArmPIDMode.h"
#include "Commands/Fire.h"

OI::OI() {
	// Process operator interface input here.
    
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	
	
	//xBox = new Joystick(1);
	yellowJoystick = new Joystick(3);
	
#if defined(NOT_YET)
	redJoystick = new Joystick(2);
	blueJoystick = new Joystick(4);
#endif	
// button definition //
/*
	greenJoystick->SetAxisChannel(Joystick::kTwistAxis, 3);
	//xBox->SetAxisChannel(Joystick::kTwistAxis, 4);
	//resetGyroButton = new JoystickButton(xBox, 8);
	//resetGyroButton->WhenPressed(new ResetGyroCommand());


	rollBallInButton = new JoystickButton(xBox, 6);
	rollBallInButton->WhileHeld(new RollBallIn());
	rollBallInButton->WhenReleased(new StopIntakeWheels());
	
	rollBallOutButton = new JoystickButton(xBox, 5);
	rollBallOutButton->WhileHeld(new RollBallOut());
	rollBallOutButton->WhenReleased(new StopIntakeWheels());
	openClawButton = new JoystickButton(xBox, 1);
	openClawButton->WhenPressed(new ToggleClaw());
	
	resetArmPotOriginButton = new JoystickButton(xBox, 7);
	resetArmPotOriginButton->WhenPressed(new FindArmPotOrigin());
	
	gotoLaunchAngle = new JoystickButton(xBox, 3);
	gotoLaunchAngle->WhenPressed(new LaunchAngle());
	
	disableArmPIDMode = new JoystickButton(xBox, 4);
	disableArmPIDMode->WhenPressed(new DisableArmPIDMode());
	
	FireButton = new JoystickButton(xBox, 2);
	FireButton->WhenPressed(new Fire());
	
	DPadUp = new JoystickButton (xBox, 12);
	DPadDown = new JoystickButton (xBox, 13);
*/
// joy sticks //
	
	// Create all the joysticks that are needed here.
	greenJoystick = new Joystick(1);
 	yellowJoystick = new Joystick(3);
	
	greenJoystick->SetAxisChannel(Joystick::kTwistAxis, 3);	
	resetGyroButton = new JoystickButton(greenJoystick, 11);
	resetGyroButton->WhenPressed(new ResetGyroCommand());


	rollBallInButton = new JoystickButton(yellowJoystick, 1);
	rollBallInButton->WhileHeld(new RollBallIn());
	rollBallInButton->WhenReleased(new StopIntakeWheels());
	
	rollBallOutButton = new JoystickButton(yellowJoystick, 2);
	rollBallOutButton->WhileHeld(new RollBallOut());
	rollBallOutButton->WhenReleased(new StopIntakeWheels());
	openClawButton = new JoystickButton(yellowJoystick, 3);
	openClawButton->WhenPressed(new ToggleClaw());
	
	resetArmPotOriginButton = new JoystickButton(yellowJoystick, 10);
	resetArmPotOriginButton->WhenPressed(new FindArmPotOrigin());
	
	gotoLaunchAngle = new JoystickButton(yellowJoystick, 8);
	gotoLaunchAngle->WhenPressed(new LaunchAngle());
	
	disableArmPIDMode = new JoystickButton(yellowJoystick, 9);
	disableArmPIDMode->WhenPressed(new DisableArmPIDMode());
	
	FireButton = new JoystickButton(yellowJoystick, 7);
	FireButton->WhenPressed(new Fire());
	
	//don't un-coment//
//	if (xBox->kDefaultZAxis == -255){
//			new Fire();
//	}
//
// end button definitions //

	// Add SmartDashboard.
	SmartDashboard::PutData("Drive Command", new DriveCommand());
	SmartDashboard::PutData("Reset Gyro Command", new ResetGyroCommand());
	SmartDashboard::PutData("Stop Intake Weels", new StopIntakeWheels());
	SmartDashboard::PutData("Roll Ball In", new RollBallIn());
	SmartDashboard::PutData("Roll Ball Out", new RollBallOut());
	SmartDashboard::PutData("Toggle Claw", new ToggleClaw());
	SmartDashboard::PutData("Find Arm Pot Origin", new FindArmPotOrigin());
	SmartDashboard::PutData("Goto Launch Angle", new LaunchAngle());
	SmartDashboard::PutData("Ball Screw Up", new BallScrewUp());
	SmartDashboard::PutData("Cock Shooter", new CockShooter());
	SmartDashboard::PutData("Launch", new Launch());
	
	
#if defined(NOT_YET)
	launchAngleButton = new JoystickButton(yellowJoystick, 7);
	launchAngleButton->WhenPressed(new LaunchAngle());
     
    // SmartDashboard Buttons
	SmartDashboard::PutData("Autonomous Command", new AutonomousCommand());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	autoLaunchButton = new JoystickButton(yellowJoystick, 7);
	autoLaunchButton->WhenPressed(new Launch());
#endif
	
}
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS
Joystick* OI::getGreenJoystick() {
	return greenJoystick;
}

Joystick* OI::getYellowJoystick() {
	return yellowJoystick;
}
Joystick* OI::getRedJoystick() {
	return redJoystick;
}
Joystick* OI::getBlueJoystick() {
	return blueJoystick;
}
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS
float OI::GetDriveStickX()
{
	return greenJoystick->GetX();
}
float OI::GetDriveStickY()
{
	return greenJoystick->GetY();
}
float OI::GetDriveRotation()
{
	
	return greenJoystick->GetTwist();
}
float OI::GetArmSpeed()
{	
	return yellowJoystick->GetY(); // un-coment for joysticks
	


}

bool OI::GetTopPositionButton()
{
	return yellowJoystick->GetRawButton(9);	
}
bool OI::GetShootPositionButton()
{
	return yellowJoystick->GetRawButton(6);	
}
bool OI::GetBottomPositionButton()
{
	return yellowJoystick->GetRawButton(9);	
}

bool OI::GetLaunchButton()
{
	return yellowJoystick->GetRawButton(7);
}

bool OI::GetOpenClawButton()
{
	return yellowJoystick->GetRawButton(3);
}

bool OI::GetRollOutButton()
{
	return yellowJoystick->GetRawButton(2);
}

bool OI::GetRollInButton()
{
	return yellowJoystick->GetRawButton(1);
}