#include "main.h"
void redSmallZone6()
{  
    runIntake(100);
    delay(1500);
    moveBase(1100,90);
    delay(2600);
    turnBase(-60,75);
    delay(500);
    moveBasePID(500,500,800);
    moveBasePID(-950,-950,1200);
    turnBase(550,80);
    delay(1400);
    moveBasePID(550,550,450);
    runIntake(-75);
    delay(200);
    runIntake(0);
    pidTray(2750);
    moveBasePID(-500,-500,1000);
}