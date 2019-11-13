#include "main.h"
void redSmallZone5()
{
    runIntake(100);
    moveBase(1350,60);
    delay(4000);
    moveBase(-700,75);
    delay(2300);
    turnBase(360,60);
    delay(1500);
    moveBase(468,75);
    delay(1000);
    runIntake(0);
    runTray(70);
    delay(4000);
    runIntake(-85);
    delay(500);
    moveBase(-200,100);
    delay(500);
}