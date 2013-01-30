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
    public static DoubleSolenoid driveTrainShifter;
    public static Gyro driveTrainGyro;
    public static Accelerometer driveTrainAccelerometer;
    public static SpeedController climberClimbingScrew;
    public static DoubleSolenoid climberClimbingSolenoid;
    public static SpeedController shooterSpeedController1;
    public static Encoder shooterEncoder1;
    public static PIDController shooterWheel1;
    public static SpeedController shooterSpeedController2;
    public static Encoder shooterEncoder2;
    public static PIDController shooterWheel2;
    public static SpeedController shooterScrewSpeedController;
    public static AnalogChannel shooterPotentiometer;
    public static PIDController shooterScrew;
    public static DoubleSolenoid shooterSolenoid;
    public static Compressor pneumaticsCompressor;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    public static void init() {
        // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
        driveTrainLeftFront = new Victor(1, 1);
	LiveWindow.addActuator("Drive Train", "LeftFront", (Victor) driveTrainLeftFront);
        
        driveTrainLeftBack = new Victor(1, 2);
	LiveWindow.addActuator("Drive Train", "LeftBack", (Victor) driveTrainLeftBack);
        
        driveTrainRightFront = new Victor(1, 3);
	LiveWindow.addActuator("Drive Train", "RightFront", (Victor) driveTrainRightFront);
        
        driveTrainRightBack = new Victor(1, 4);
	LiveWindow.addActuator("Drive Train", "RightBack", (Victor) driveTrainRightBack);
        
        driveTrainDriveMotors = new RobotDrive(driveTrainLeftFront, driveTrainLeftBack,
              driveTrainRightFront, driveTrainRightBack);
	
        driveTrainDriveMotors.setSafetyEnabled(true);
        driveTrainDriveMotors.setExpiration(0.1);
        driveTrainDriveMotors.setSensitivity(0.5);
        driveTrainDriveMotors.setMaxOutput(1.0);
        driveTrainShifter = new DoubleSolenoid(1, 1, 2);      
	
        
        driveTrainGyro = new Gyro(1, 1);
	LiveWindow.addSensor("Drive Train", "Gyro", driveTrainGyro);
        driveTrainGyro.setSensitivity(1.25);
        driveTrainAccelerometer = new Accelerometer(1, 2);
	LiveWindow.addSensor("Drive Train", "Accelerometer", driveTrainAccelerometer);
        driveTrainAccelerometer.setSensitivity(1.0);
        driveTrainAccelerometer.setZero(2.5);
        climberClimbingScrew = new Victor(1, 5);
	LiveWindow.addActuator("Climber", "ClimbingScrew", (Victor) climberClimbingScrew);
        
        climberClimbingSolenoid = new DoubleSolenoid(1, 5, 6);      
	
        
        shooterSpeedController1 = new Victor(1, 7);
	LiveWindow.addActuator("Shooter", "SpeedController1", (Victor) shooterSpeedController1);
        
        shooterEncoder1 = new Encoder(1, 2, 1, 3, false, EncodingType.k4X);
	LiveWindow.addSensor("Shooter", "Encoder1", shooterEncoder1);
        shooterEncoder1.setDistancePerPulse(1.0);
        shooterEncoder1.setPIDSourceParameter(PIDSourceParameter.kRate);
        shooterEncoder1.start();
        shooterWheel1 = new PIDController(1.0, 0.0, 0.0, 0.0, shooterEncoder1, shooterSpeedController1, 0.02);
	LiveWindow.addActuator("Shooter", "Wheel1", shooterWheel1);
        shooterWheel1.setContinuous(false); shooterWheel1.setAbsoluteTolerance(0.2); 
        shooterWheel1.setOutputRange(-1.0, 1.0);        
        shooterSpeedController2 = new Victor(1, 8);
	LiveWindow.addActuator("Shooter", "Speed Controller2", (Victor) shooterSpeedController2);
        
        shooterEncoder2 = new Encoder(1, 4, 1, 5, false, EncodingType.k4X);
	LiveWindow.addSensor("Shooter", "Encoder2", shooterEncoder2);
        shooterEncoder2.setDistancePerPulse(1.0);
        shooterEncoder2.setPIDSourceParameter(PIDSourceParameter.kRate);
        shooterEncoder2.start();
        shooterWheel2 = new PIDController(1.0, 0.0, 0.0, 0.0, shooterEncoder2, shooterSpeedController2, 0.02);
	LiveWindow.addActuator("Shooter", "Wheel2", shooterWheel2);
        shooterWheel2.setContinuous(false); shooterWheel2.setAbsoluteTolerance(0.2); 
        shooterWheel2.setOutputRange(-1.0, 1.0);        
        shooterScrewSpeedController = new Victor(1, 6);
	LiveWindow.addActuator("Shooter", "ScrewSpeedController", (Victor) shooterScrewSpeedController);
        
        shooterPotentiometer = new AnalogChannel(1, 3);
	LiveWindow.addSensor("Shooter", "Potentiometer", shooterPotentiometer);
        
        shooterScrew = new PIDController(1.0, 0.0, 0.0, 0.0, shooterPotentiometer, shooterScrewSpeedController, 0.02);
	LiveWindow.addActuator("Shooter", "Screw", shooterScrew);
        shooterScrew.setContinuous(false); shooterScrew.setAbsoluteTolerance(0.2); 
        shooterScrew.setOutputRange(-1.0, 1.0);        
        shooterSolenoid = new DoubleSolenoid(1, 7, 8);      
	
        
        pneumaticsCompressor = new Compressor(1, 1, 1, 1);
	
        
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
    }
}
