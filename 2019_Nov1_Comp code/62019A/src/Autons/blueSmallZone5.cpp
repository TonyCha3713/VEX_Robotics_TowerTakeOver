#include "main.h"
void blueSmallZone5()
{
    runIntake(100);
    moveBase(1350,61);
    delay(4000);
    moveBase(-700,75);
    delay(2300);
    turnBase(-315,60);
    delay(1500);
    moveBase(518,75);
    delay(1000);
    runIntake(0);
    runTray(70);
    delay(4000);
    runIntake(-85);
    delay(500);
    moveBase(-200,100);
    delay(500);
}
