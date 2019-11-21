#include "main.h"
void redSmallZone8()
{
    runIntake(200);
    moveBase(1255,75);
    delay(3000);
    turnBase(-25,75);
    delay(300);
    moveBase(-1300,170);
    delay(2150);
    turnBase(55,75);
    delay(300);
    moveBase(1255,75);
    delay(3000);
    moveBase(-900,170);
    runTray(30);
    delay(1600);
    turnBase(400,150);
    delay(600);
    moveBase(500,100);
    delay(600);
    runIntake(0);
    runTray(150);
    delay(2000);
    runIntake(-100);
    delay(500);
    moveBase(-400,150);

    
}