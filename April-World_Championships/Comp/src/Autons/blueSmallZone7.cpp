#include "main.h"
void blueSmallZone7()
{   
    arm.set_brake_mode(E_MOTOR_BRAKE_HOLD);
    runIntake(115);
    moveBasePID(500,500,1100);
    moveBase(380,70);
    delay(1300);
    moveBasePID(-250,-250,900);
    turnBase(245,75);
    delay(700);
    moveBasePID(-1000,-1000,1200);
    turnBase(-255,75);
    delay(700);
    moveBase(1100,85);
    delay(2500);
    moveBasePID(-800,-800,1300);
    turnBase(-450,75);
    delay(1300);
    runIntake(0);
    moveBasePID(320,320,750);
    pidTray(2800);
    moveBasePID(-500,-500,1000);

}