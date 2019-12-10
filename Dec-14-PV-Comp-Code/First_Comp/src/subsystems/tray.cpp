#include "main.h"
void runTray(double input)
{
    Tray1.move(-input);
    Tray2.move(input);
}
void pidTray(double time)
{  
    PID trayPID (0.90, 0, 0);
    std::uint_least32_t now = millis();
    for(int i=0; i<time; i++)
    {
        trayPID.setError(trayPot.get_value() - 653);
		runTray(trayPID.runPID());
        Task::delay_until(&now, 1);
    }
    runTray(0);
}
