#include "main.h"
void blueSmallZone8()
{
    runIntake(-130);
    moveBasePID(280,280,500);
    runIntake(0);
    runTray(30);
    delay(500);
    runTray(-50);
    runIntake(100);
    delay(200);
    moveBase(1200,80);
    delay(2700);
    turnBase(46,75);
    delay(300);
    runLeftBase(-150);
    runRightBase(-170);
    delay(2500);
    //moveBasePID(-1180,-1180,2500);
    turnBase(-49,75);
    delay(300);
    moveBase(1100,78);
    delay(2700);
    
}