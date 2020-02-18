#include "main.h"
void blueSmallZone6()
{   
    moveBasePID(350,350,600);
    moveBasePID(-185,-185,450);
    runArm(85);
    delay(250);
    runIntake(-110);
    delay(750);
    runArm(-130);
    delay(1000);
    runIntake(100);
    moveBase(1100,90);
    delay(2600);
    turnBase(60,75);
    delay(500);
    moveBasePID(500,500,800);
    moveBasePID(-950,-950,1200);
    turnBase(-543,80);
    delay(1400);
    moveBasePID(550,550,450);
    runIntake(-75);
    delay(200);
    runIntake(0);
    pidTray(2750);
    moveBasePID(-500,-500,1000);
}