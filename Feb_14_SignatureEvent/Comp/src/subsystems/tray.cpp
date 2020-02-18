#include "main.h"
void runTray(double input)
{
    Tray.move(-input);
}
void pidTray(double time)
{  
    PID trayPID (0.23, 0, 0);
    std::uint_least32_t now = millis();
    for(int i=0; i<time; i++)
    {
        trayPID.setError(1691 + Tray.get_position());
		runTray(trayPID.runPID());
        Task::delay_until(&now, 1);
    }
    runTray(0);
}
