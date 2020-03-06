#include "main.h"


/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */


/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	Intake1.set_brake_mode(E_MOTOR_BRAKE_HOLD);
	Intake2.set_brake_mode(E_MOTOR_BRAKE_HOLD);
	arm.set_brake_mode(E_MOTOR_BRAKE_HOLD);
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
/*
int autonCount = 0;

void lcdScroll() {

	if(autonCount < 0)
		autonCount = 0;

	else if(autonCount > 6)
		autonCount = 0;

	switch(autonCount) {

		case 0:
			lcd::set_text(1, "one cube safety");
			break;

		case 1:
			lcd::set_text(1, "red Smallzone 5");
			break;

		case 2:
			lcd::set_text(1, "blue Smallzone 5");
			break;
		case 3:
			lcd::set_text(1, "red BigZone");
			break;
		case 4:
			lcd::set_text(1, "Blue BigZone");
			break;
		case 5:
			lcd::set_text(1, "red SmallZone 8");
			break;
		case 6:
			lcd::set_text(1, "Blue SmallZone 8");
			break;
		default:
			lcd::set_text(1, "how did you mess up");
			break;

	}

}

void on_left_pressed() {

	autonCount--;
	lcdScroll();

}

void on_center_pressed() {

	autonCount = autonCount;
	lcd::shutdown();

}

void on_right_pressed() {

	autonCount++;
	lcdScroll();

}
*/
void competition_initialize() {
	/*lcd::initialize();
	lcd::set_text(0, "Choose auton");
	lcdScroll();
	lcd::register_btn0_cb(on_left_pressed);
	lcd::register_btn1_cb(on_center_pressed);
	lcd::register_btn2_cb(on_right_pressed);
*/
}

void autonomous() {
	redBigZone();
}
/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
	leftBase1.set_brake_mode(E_MOTOR_BRAKE_COAST);
	leftBase2.set_brake_mode(E_MOTOR_BRAKE_COAST);
	rightBase1.set_brake_mode(E_MOTOR_BRAKE_COAST);
	rightBase2.set_brake_mode(E_MOTOR_BRAKE_COAST);
	Intake1.set_brake_mode(E_MOTOR_BRAKE_HOLD);
	Intake2.set_brake_mode(E_MOTOR_BRAKE_HOLD);
	PID trayPID (0.205,0,0);
	PID armPID (0.3,0,0);
	while (true) {
		bool ok = false;
		runLeftBase(master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y));
		runRightBase(master.get_analog(E_CONTROLLER_ANALOG_RIGHT_Y));
		if(master.get_digital(E_CONTROLLER_DIGITAL_R1))
			runIntake(115);
		else if(master.get_digital(E_CONTROLLER_DIGITAL_R2))
			runIntake(-115);
		else
			runIntake(0);
		if(master.get_digital(E_CONTROLLER_DIGITAL_L1))
		{
			Intake1.set_brake_mode(E_MOTOR_BRAKE_HOLD);
			Intake2.set_brake_mode(E_MOTOR_BRAKE_HOLD);
			trayPID.setError(1888 + Tray.get_position());
			runTray(trayPID.runPID());
		}
		else if(master.get_digital(E_CONTROLLER_DIGITAL_L2))
		{
			Intake1.set_brake_mode(E_MOTOR_BRAKE_HOLD);
			Intake2.set_brake_mode(E_MOTOR_BRAKE_HOLD);
			trayPID.setError(0 + Tray.get_position());
			runTray(trayPID.runPID());
		}
		else
		{
			Intake1.set_brake_mode(E_MOTOR_BRAKE_HOLD);
			Intake2.set_brake_mode(E_MOTOR_BRAKE_HOLD);
			runTray(0);
		}
		if(master.get_digital(E_CONTROLLER_DIGITAL_RIGHT))
		{
			if(Tray.get_position() > - 591)
				runTray(115);
			else 
			{
				arm.set_brake_mode(E_MOTOR_BRAKE_HOLD);
				Tray.set_brake_mode(E_MOTOR_BRAKE_HOLD);
				runArm(115);
			}
		}
			/*
			if(!ok)
			{
				if(Tray.get_position() > - 591)
				{
					runTray(115);
				}
				else
				{
					runTray(0);
					ok = true;
				}
				while(ok)
				{
					if(arm.get_position() < 40) runIntake(-115);
					else runIntake(0);
					arm.set_brake_mode(E_MOTOR_BRAKE_HOLD);
					Tray.set_brake_mode(E_MOTOR_BRAKE_HOLD);
					runArm(115);
					if(master.get_digital(E_CONTROLLER_DIGITAL_LEFT)) break;
				}
			}
			*/
		
		else if(master.get_digital(E_CONTROLLER_DIGITAL_LEFT))
		{
			
			arm.set_brake_mode(E_MOTOR_BRAKE_HOLD);
			Tray.set_brake_mode(E_MOTOR_BRAKE_HOLD);
			runArm(-115);
		}
		else runArm(0);
		
		//std:: cout << arm.get_position() << std:: endl;
		delay(10);	
	}
}