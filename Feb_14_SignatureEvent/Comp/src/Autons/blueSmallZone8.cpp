#include "main.h"
void blueSmallZone8()
{
    runIntake(-130);
    runTray(50);
    moveBasePID(345,345,400);
    delay(350);
    runTray(-30);
    runIntake(130);
    moveBase(1050,70);
    delay(3000);
    runTray(0);
    runLeftBase(-65);
    runRightBase(-115);
    delay(1560);
    runLeftBase(0);
    runRightBase(0);
    turnBase(-245,75);
    delay(700);
    moveBase(1050,64);
    delay(3000);
    moveBasePID(-800,-800,1300);
    turnBase(-247,75);
    delay(900);
    moveBasePID(440,440,500);
    runIntake(0);
    delay(100);
    pidTray(2400);
    runIntake(-75);
    moveBasePID(-300,-300,900);

}