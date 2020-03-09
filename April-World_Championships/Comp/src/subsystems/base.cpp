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
void turnBase(double input, double speed)
{
    leftBase1.move_relative(input, speed); 
    leftBase2.move_relative(input, speed); 
    rightBase1.move_relative(-input, speed); 
    rightBase2.move_relative(-input, speed); 
}

double getLeftBase() {

    return (leftBase1.get_position() + leftBase2.get_position()) / 2.0;
}

double getRightBase() {

    return (rightBase1.get_position() + rightBase2.get_position()) / 2.0;
}
void moveBasePID(double leftBaseDeltaTicks, double rightBaseDeltaTicks, double time)
{
    const double leftBaseTarget = getLeftBase() + leftBaseDeltaTicks;
    const double rightBaseTarget = getRightBase() + rightBaseDeltaTicks;
    PID leftBase (0.3, 0, 0);
    PID rightBase (0.3, 0, 0);
    //leftBase.maxSpeed = _maxSpeed;
    //rightBase.maxSpeed = _maxSpeed;
    std::uint_least32_t now = millis();
     for(int i = 0; i < time; i++) {

        leftBase.setError(leftBaseTarget - getLeftBase());
        rightBase.setError(rightBaseTarget - getRightBase());

        runLeftBase(leftBase.runPID());
        runRightBase(rightBase.runPID());
        Task::delay_until(&now, 1);
     }
    runLeftBase(0);
    runRightBase(0);
}
