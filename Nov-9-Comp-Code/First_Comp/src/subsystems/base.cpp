#include "main.h"

void runLeftBase(double input)
{
    leftBase1.move(input);
    leftBase2.move(input);
}

void runRightBase(double input)
{
    rightBase1.move(input);
    rightBase2.move(input);
}

void moveBase(double input, double speed)
{
    leftBase1.move_relative(input, speed); 
    leftBase2.move_relative(input, speed); 
    rightBase1.move_relative(input, speed); 
    rightBase2.move_relative(input, speed); 
}

void turnBase(double degree, double speed)
{
    leftBase1.move_relative(degree, speed); 
    leftBase2.move_relative(degree, speed); 
    rightBase1.move_relative(-degree, speed); 
    rightBase2.move_relative(-degree, speed); 
}



