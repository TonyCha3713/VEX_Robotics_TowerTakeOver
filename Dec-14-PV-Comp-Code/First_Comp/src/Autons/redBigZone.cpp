#include "main.h"
void redBigZone()
{
    runIntake(-150);
    delay(2500);
    runIntake(200);
    moveBase(1300,70);
    delay(3300);
    turnBase(-330,65);
    delay(1000);
    moveBase(1200,70);
    delay(3800);
    runTray(75);
    runIntake(-10);
    delay(2500);
    runIntake(-90);
    delay(1300);
    moveBase(-400,75);
    runTray(-100);
    delay(3000);
    moveBase(-100,75);
}