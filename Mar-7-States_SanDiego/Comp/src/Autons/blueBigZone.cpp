#include "main.h"
void blueBigZone()
{
    moveBasePID(350,350,600);
    moveBasePID(-300,-300,450);
    runArm(85);
    delay(250);
    runIntake(-110);
    delay(750);
    runArm(-130);
    delay(1000);
    runIntake(100);
    moveBase(700,75);
    delay(1200);
    turnBase(300,75);
    delay(1000);
    moveBase(500,75);
    delay(850);
    turnBase(180,75);
    delay(600);
    moveBase(535,75);
    delay(700);
    runIntake(0);
    pidTray(3000);
    moveBasePID(-300,-300,450);
}