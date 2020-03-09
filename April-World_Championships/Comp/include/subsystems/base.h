#ifndef BASE_H
#define BASE_H
void runLeftBase(double input);
void runRightBase(double input);
double getLeftBase();
double getRightBase();
void moveBase(double input, double speed);
void moveBasePID(double leftBaseDeltaTicks, double rightBaseDeltaTicks, double time);
void turnBase(double degree, double speed);
#endif