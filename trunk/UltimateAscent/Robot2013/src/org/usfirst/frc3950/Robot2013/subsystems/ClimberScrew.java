// RobotBuilder Version: 0.0.2
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// Java from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
package org.usfirst.frc3950.Robot2013.subsystems;
import org.usfirst.frc3950.Robot2013.RobotMap;
import org.usfirst.frc3950.Robot2013.commands.*;
import edu.wpi.first.wpilibj.*;
import edu.wpi.first.wpilibj.command.Subsystem;
/**
 *
 */
public class ClimberScrew extends Subsystem {
    private boolean topLimitHit = false;
    private boolean bottomLimitHit = false;
    
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    SpeedController climbingScrew = RobotMap.climberScrewClimbingScrew;
    DigitalInput topLimitSwitch = RobotMap.climberScrewTopLimitSwitch;
    DigitalInput bottomLimitSwitch = RobotMap.climberScrewBottomLimitSwitch;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    // Put methods for controlling this subsystem
    // here. Call these from Commands.
    public void initDefaultCommand() {
        // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
        setDefaultCommand(new ClimberElevate());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
        // Set the default command for a subsystem here.
        //setDefaultCommand(new MySpecialCommand());
    }
    public void setHeight(double height) {
        
//        System.out.println("Climber Scew heigh = " + height);
        boolean limitHit = false;
        height *= -1.0;
        
        if (height < 0.0) {
            limitHit = pollBottomLimitSwitch();
//            System.out.println("bottom limit hit = " + limitHit);
        }
        else if (height > 0.0) {
            limitHit = pollTopLimitSwitch();
//            System.out.println("top limit hit = " + limitHit);
        }
        
        if (limitHit) {
            height = 0.0;
        }
        
//        System.out.println("climber screw motor setting = " + height);
        
        climbingScrew.set(height);
    }
    public boolean topLimitHit() {
        return topLimitHit;
    }
    public boolean bottomLimitHit() {
        return bottomLimitHit;
    }
    
    private boolean pollTopLimitSwitch() {
        boolean switchState = topLimitSwitch.get();
//        System.out.println("topLimitSwitch.get() = " + switchState);
        topLimitHit = switchState;
        return topLimitHit;
    }
    
    private boolean pollBottomLimitSwitch() {
        boolean switchState = bottomLimitSwitch.get();
//        System.out.println("bottomLimitSwitch.get() = " + switchState);
        bottomLimitHit = switchState;
        return bottomLimitHit;
    }
}
