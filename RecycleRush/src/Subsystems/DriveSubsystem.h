// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef DRIVESUBSYSTEM_H
#define DRIVESUBSYSTEM_H

#include <vector>

#include "Commands/Subsystem.h"
#include "WPILib.h"

/**
 *
 *
 * @author ExampleAuthor
 */

// Default values for the various configuration
// items that the drive subsystem uses.
namespace DriveSubsystemConfigValueDefaults
{
	const bool Drive_UseGyroDefaultValue = false;
}

enum DriveHeading {
	DriveForward,
	DriveBack,
	DriveLeft,
	DriveRight
};

enum RotateDirection {
	RotateLeft,
	RotateRight
};

enum AutoMode {
	Off,
	Driving,
	Rotating
};

// Helper functions to convert between Driving Related enums and strings.
const std::string& DriveHeadingToString(DriveHeading heading);
const std::string& RotateDirectionToString(RotateDirection direction);
const std::string& AutoModeToString(AutoMode mode);

class DriveSubsystem: public Subsystem {
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	CANTalon* cANTalon1;
	CANTalon* cANTalon3;
	CANTalon* cANTalon2;
	CANTalon* cANTalon4;
	RobotDrive* robotDrive;
	Gyro* gyro1;
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	DriveSubsystem();
	void InitDefaultCommand();
	void MecanumDrive(float x, float y, float twist);
	void EnableDriveSubsystem();

	bool AutoDriveSetup(DriveHeading heading, float distance);
	void AutoDriveExecute();
	bool AutoDriveHasReachedLocation();

	bool AutoRotateSetup(float angle, RotateDirection direction);
	void AutoRotateExecute();
	bool AutoHasFinishedRotating();

	AutoMode AutoModeState() const;
	void AutoModeDisable();

private:
	void SetSafetyMode(CANTalon* motor, bool enabled, float timeout = 0.0);

	void AutoRotateMakeProgress(float gyroAngle);
	void AutoDriveMakeProgress(float distanceTraveled);

	void SetMotorSpeeds(float frontLeftMotorSpeed,
						float rearLeftMotorSpeed,
						float frontRightMotorSpeed,
						float rearRightMotorSpeed);

	void SetMotorSpeeds(float speed);

	enum AutoActionState
	{
		NotStarted,
		InProgress,
		Completed,
	};

	// Holds all the parameters for driving.
	struct AutoDrivingParams
	{
		// Heading of the auto drive.
		DriveHeading autoHeading;

		// Holds the position of the talon being monitored at the start
		// of an auto-drive.  Typically this should be zero.
		double positionCountAtStartOfAutoDrive;

		// Holds the shaft count total when the desired driving position is reached.
		double shaftCountTotalToAtDesiredPosition;

		// When in AutoMode Driving this contains the distance
		// to drive expressed in inches.
		float autoDriveDistanceInInches;

		float motorSpeeds[4];
	};

	// Holds all the parameters for a rotation.
	struct AutoRotationParams
	{
		// Request direction of rotation.
		RotateDirection autoRotateDirection;

		// When in AutoMode Rotation this contains the requested
		// angle to rotate.  This is used in conjunction with the
		// the autoRotateDirection member to determine an absolute
		// angle to get to.
		float autoRotateInputAngle;

		// When in AutoMode Rotation this contains the absolute angle
		// that the robot is to get to. For example, if the autoRotationDirection
		// is Left with an angle of 90 the autoGyroTargetAngle will be set to 270 degrees.
		float autoGyroTargetAngle;

		// The current absolute speed of rotation.
		float absoluteRotationSpeed;
	};

	AutoMode autoMode;

	// Indicates the current state of any AutoMode that has been setup.
	// It is either NotStarted, InProgress or Done.
	AutoActionState autoActionState;

	// The autoMode member above is used as a tag
	// to indicate which of the structures in the
	// union is active.
	union
	{
		AutoDrivingParams autoDrivingParams;
		AutoRotationParams autoRotationParams;
	};


	// Whether or not the subsystem should use the gyro.
	bool useGyro;
};

#endif