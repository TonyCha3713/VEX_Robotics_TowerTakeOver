#include "main.h"
void blueBigZone()
{
    runIntake(200);
    moveBase(1300,65);
    delay(4000);
    turnBase(330,65);
    delay(1000);
    moveBase(1200,70);
    delay(4000);
    runTray(75);
    runIntake(-10);
    delay(2500);
    runIntake(-90);
    delay(1300);
    moveBase(-400,75);
    runTray(-100);
}