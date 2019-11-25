#include "main.h"
void redSmallZone5()
{
    runIntake(200);
    moveBase(1365,65);
    delay(4000);
    moveBase(-700,75);
    delay(2300);
    turnBase(350,75);
    delay(1300);
    moveBase(470,75);
    delay(1000);
    runIntake(0);
    runTray(85);
    runIntake(-10);
    delay(3500);
    runIntake(-100);
    delay(1000);
    runTray(-100);
    moveBase(-400,100);
}