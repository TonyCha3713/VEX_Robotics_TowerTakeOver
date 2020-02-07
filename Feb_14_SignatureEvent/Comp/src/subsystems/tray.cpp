#include "main.h"
void runTray(double input)
{
    Tray.move(-input);
}
void pidTray(double time)
{  
    PID trayPID (0.1, 0, 0);
    std::uint_least32_t now = millis();
    for(int i=0; i<time; i++)
    {
        trayPID.setError(trayPot.get_value() - 665);
		runTray(trayPID.runPID());
        Task::delay_until(&now, 1);
    }
    runTray(0);
}
