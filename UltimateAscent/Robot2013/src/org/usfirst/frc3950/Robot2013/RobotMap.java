// RobotBuilder Version: 0.0.2
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// Java from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
package org.usfirst.frc3950.Robot2013;
    
import edu.wpi.first.wpilibj.*;
import edu.wpi.first.wpilibj.CounterBase.EncodingType; import edu.wpi.first.wpilibj.Encoder.PIDSourceParameter;
import edu.wpi.first.wpilibj.smartdashboard.*;
import edu.wpi.first.wpilibj.livewindow.LiveWindow;
import java.util.Vector;
/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */
public class RobotMap {
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    public static SpeedController driveTrainLeftFront;
    public static SpeedController driveTrainLeftBack;
    public static SpeedController driveTrainRightFront;
    public static SpeedController driveTrainRightBack;
    public static RobotDrive driveTrainDriveMotors;
    public static Gyro driveTrainGyro;
    public static DoubleSolenoid transmissionShifter;
    public static DoubleSolenoid climberPistonClimbingSolenoid;
    public static SpeedController climberScrewClimbingScrew;
    public static SpeedController wheelOneSpeedController1;
    public static Encoder wheelOneEncoder1;
    public static PIDController wheelOneWheel1;
    public static SpeedController wheelTwoSpeedController2;
    public static Encoder wheelTwoEncoder2;
    public static PIDController wheelTwoWheel2;
    public static SpeedController shootingScrewScrewSpeedController;
    public static AnalogChannel shootingScrewPotentiometer;
    public static PIDController shootingScrewShooterScrew;
    public static SpeedController conveyorBeltBelt;
    public static Compressor pneumaticsCompressor;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    public static void init() {
        // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
        driveTrainLeftFront = new Victor(1, 1);
	LiveWindow.addActuator("Drive Train", "Left Front", (Victor) driveTrainLeftFront);
        
        driveTrainLeftBack = new Victor(1, 2);
	LiveWindow.addActuator("Drive Train", "Left Back", (Victor) driveTrainLeftBack);
        
        driveTrainRightFront = new Victor(1, 3);
	LiveWindow.addActuator("Drive Train", "Right Front", (Victor) driveTrainRightFront);
        
        driveTrainRightBack = new Victor(1, 4);
	LiveWindow.addActuator("Drive Train", "Right Back", (Victor) driveTrainRightBack);
        
        driveTrainDriveMotors = new RobotDrive(driveTrainLeftFront, driveTrainLeftBack,
              driveTrainRightFront, driveTrainRightBack);
	
        driveTrainDriveMotors.setSafetyEnabled(false);
        driveTrainDriveMotors.setExpiration(0.1);
        driveTrainDriveMotors.setSensitivity(0.5);
        driveTrainDriveMotors.setMaxOutput(1.0);
        driveTrainDriveMotors.setInvertedMotor(RobotDrive.MotorType.kFrontLeft, true);
        driveTrainDriveMotors.setInvertedMotor(RobotDrive.MotorType.kRearLeft, true);
        driveTrainGyro = new Gyro(1, 1);
	LiveWindow.addSensor("Drive Train", "Gyro", driveTrainGyro);
        driveTrainGyro.setSensitivity(0.007);
        transmissionShifter = new DoubleSolenoid(1, 1, 2);      
	
        
        climberPistonClimbingSolenoid = new DoubleSolenoid(1, 5, 6);      
	
        
        climberScrewClimbingScrew = new Victor(1, 6);
	LiveWindow.addActuator("Climber Screw", "Climbing Screw", (Victor) climberScrewClimbingScrew);
        
        wheelOneSpeedController1 = new Victor(1, 7);
	LiveWindow.addActuator("Wheel One", "Speed Controller 1", (Victor) wheelOneSpeedController1);
        
        wheelOneEncoder1 = new Encoder(1, 2, 1, 3, false, EncodingType.k4X);
	LiveWindow.addSensor("Wheel One", "Encoder 1", wheelOneEncoder1);
        wheelOneEncoder1.setDistancePerPulse(1.0);
        wheelOneEncoder1.setPIDSourceParameter(PIDSourceParameter.kRate);
        wheelOneEncoder1.start();
        wheelOneWheel1 = new PIDController(1.0, 0.0, 0.0, 0.0, wheelOneEncoder1, wheelOneSpeedController1, 0.02);
	LiveWindow.addActuator("Wheel One", "Wheel1", wheelOneWheel1);
        wheelOneWheel1.setContinuous(false); wheelOneWheel1.setAbsoluteTolerance(0.2); 
        wheelOneWheel1.setOutputRange(-1.0, 1.0);        
        wheelTwoSpeedController2 = new Victor(1, 8);
	LiveWindow.addActuator("Wheel Two", "Speed Controller 2", (Victor) wheelTwoSpeedController2);
        
        wheelTwoEncoder2 = new Encoder(1, 4, 1, 6, false, EncodingType.k4X);
	LiveWindow.addSensor("Wheel Two", "Encoder 2", wheelTwoEncoder2);
        wheelTwoEncoder2.setDistancePerPulse(1.0);
        wheelTwoEncoder2.setPIDSourceParameter(PIDSourceParameter.kRate);
        wheelTwoEncoder2.start();
        wheelTwoWheel2 = new PIDController(1.0, 0.0, 0.0, 0.0, wheelTwoEncoder2, wheelTwoSpeedController2, 0.02);
	LiveWindow.addActuator("Wheel Two", "Wheel2", wheelTwoWheel2);
        wheelTwoWheel2.setContinuous(false); wheelTwoWheel2.setAbsoluteTolerance(0.2); 
        wheelTwoWheel2.setOutputRange(-1.0, 1.0);        
        shootingScrewScrewSpeedController = new Victor(1, 5);
	LiveWindow.addActuator("Shooting Screw", "Screw Speed Controller", (Victor) shootingScrewScrewSpeedController);
        
        shootingScrewPotentiometer = new AnalogChannel(1, 3);
	LiveWindow.addSensor("Shooting Screw", "Potentiometer", shootingScrewPotentiometer);
        
        shootingScrewShooterScrew = new PIDController(1.0, 0.0, 0.0, 0.0, shootingScrewPotentiometer, shootingScrewScrewSpeedController, 0.02);
	LiveWindow.addActuator("Shooting Screw", "Shooter Screw", shootingScrewShooterScrew);
        shootingScrewShooterScrew.setContinuous(false); shootingScrewShooterScrew.setAbsoluteTolerance(0.2); 
        shootingScrewShooterScrew.setOutputRange(-1.0, 1.0);        
        conveyorBeltBelt = new Victor(1, 9);
	LiveWindow.addActuator("Conveyor Belt", "Belt", (Victor) conveyorBeltBelt);
        
        pneumaticsCompressor = new Compressor(1, 5, 1, 1);
	
        
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
    }
}