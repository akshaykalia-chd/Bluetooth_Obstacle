#ifndef BOT_H
#define BOT_H
#include <Arduino.h>
#include "ReadDip.h"
#include "Bluetooth.h"

class Bot : public Bluetooth, public ReadDip
{
private:
    char readmode;
    void read_mode();

public:
    Bot(char mode, bool debug, int step_size_look, int stop_distance, uint8_t motor1,
        uint8_t motor2, uint8_t motor3, uint8_t motor4, uint8_t ENABLEpin_1, uint8_t ENABLEpin_2,
        uint8_t trigPin, uint8_t echoPin, uint8_t dip1, uint8_t dip2);    
    void set_mode_debug();
    void lets_go();
};

#endif