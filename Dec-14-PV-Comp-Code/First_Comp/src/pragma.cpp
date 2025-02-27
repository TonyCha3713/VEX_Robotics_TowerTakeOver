#include "main.h"
pros::Controller master(E_CONTROLLER_MASTER);
ADIAnalogIn trayPot(7);
pros::Motor leftBase1(4, E_MOTOR_GEARSET_18, 0, E_MOTOR_ENCODER_DEGREES);
pros::Motor leftBase2(5, E_MOTOR_GEARSET_18, 0, E_MOTOR_ENCODER_DEGREES);
pros::Motor rightBase1(6, E_MOTOR_GEARSET_18, 1, E_MOTOR_ENCODER_DEGREES);
pros::Motor rightBase2(7, E_MOTOR_GEARSET_18, 1, E_MOTOR_ENCODER_DEGREES);
pros::Motor Intake1(13, E_MOTOR_GEARSET_18, 0, E_MOTOR_ENCODER_DEGREES);
pros::Motor Intake2(19, E_MOTOR_GEARSET_18, 1, E_MOTOR_ENCODER_DEGREES);
pros::Motor Tray1(20, E_MOTOR_GEARSET_18, 1, E_MOTOR_ENCODER_DEGREES);
pros::Motor Tray2(18, E_MOTOR_GEARSET_18, 0, E_MOTOR_ENCODER_DEGREES);
//pros::Motor Arm1();
//pros::Motor Arm2();