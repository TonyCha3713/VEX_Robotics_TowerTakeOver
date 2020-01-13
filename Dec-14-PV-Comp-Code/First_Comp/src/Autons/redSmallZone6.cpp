#include "main.h"
void redSmallZone6()
{
    runIntake(-150);
    delay(3000);
    runIntake(115);
    moveBase(1150,50);
    delay(3800);
    moveBasePID(-650,-650,1500);
    turnBase(310,75);
    delay(1300);
    moveBasePID(600,600,1000);
    runIntake(0);
    runTray(70);
    delay(3700);
    runIntake(-75);
    moveBasePID(-200,-200,2000);
}