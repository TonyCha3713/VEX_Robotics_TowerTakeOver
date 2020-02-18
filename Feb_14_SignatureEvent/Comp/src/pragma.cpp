#include "main.h"
pros::Controller master(E_CONTROLLER_MASTER);
pros::Motor leftBase1(6, E_MOTOR_GEARSET_18, 0, E_MOTOR_ENCODER_DEGREES);
pros::Motor leftBase2(3, E_MOTOR_GEARSET_18, 0, E_MOTOR_ENCODER_DEGREES);
pros::Motor rightBase1(10, E_MOTOR_GEARSET_18, 1, E_MOTOR_ENCODER_DEGREES);
pros::Motor rightBase2(4, E_MOTOR_GEARSET_18, 1, E_MOTOR_ENCODER_DEGREES);
pros::Motor Intake1(19, E_MOTOR_GEARSET_18, 1, E_MOTOR_ENCODER_DEGREES);
pros::Motor Intake2(17, E_MOTOR_GEARSET_18, 0, E_MOTOR_ENCODER_DEGREES);
pros::Motor Tray(18, E_MOTOR_GEARSET_18, 0, E_MOTOR_ENCODER_DEGREES);
pros::Motor arm(20, E_MOTOR_GEARSET_18, 1, E_MOTOR_ENCODER_DEGREES);