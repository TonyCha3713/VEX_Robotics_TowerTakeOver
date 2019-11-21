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
int autonCount = 0;

void lcdScroll() {

	if(autonCount < 0)
		autonCount = 0;

	else if(autonCount > 3)
		autonCount = 0;

	switch(autonCount) {

		case 0:
			lcd::set_text(1, "one cube safety");
			break;

		case 1:
			lcd::set_text(1, "red small zone 5");
			break;

		case 2:
			lcd::set_text(1, "blue zone 5");
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
void competition_initialize() {
	lcd::initialize();
	lcd::set_text(0, "Choose auton");
	lcdScroll();
	lcd::register_btn0_cb(on_left_pressed);
	lcd::register_btn1_cb(on_center_pressed);
	lcd::register_btn2_cb(on_right_pressed);

}

void autonomous() {
	/*if(autonCount == 0)
    	oneCubeSafety();

    else if(autonCount == 1)
    	redSmallZone5();
    
    else if(autonCount == 2)
    	blueSmallZone5();*/
	//oneCubeSafety();

	redSmallZone5();
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
	Intake1.set_brake_mode(E_MOTOR_BRAKE_HOLD);
	Intake2.set_brake_mode(E_MOTOR_BRAKE_HOLD);
	while (true) {
		runLeftBase(master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y) * .7);
		runRightBase(master.get_analog(E_CONTROLLER_ANALOG_RIGHT_Y) * .7);
		if(master.get_digital(E_CONTROLLER_DIGITAL_R1))
			runIntake(115);
		else if(master.get_digital(E_CONTROLLER_DIGITAL_R2))
			runIntake(-115);
		else
			runIntake(0);
		if(master.get_digital(E_CONTROLLER_DIGITAL_L1))
			runTray(100);
		else if(master.get_digital(E_CONTROLLER_DIGITAL_L2))
			runTray(-115);
		else
			runTray(0);
	}
}