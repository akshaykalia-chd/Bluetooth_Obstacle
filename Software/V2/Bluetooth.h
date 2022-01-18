#ifndef BLUETOOTH_H
#define BLUETOOTH_H
#include <Arduino.h>
#include "Obstacle.h"

class Bluetooth : public Obstacle
{
private:
    bool input_recived;
    int current_cmd;
    bool act;
    void read_input();
    void decrement_step_size();
    void increment_step_size();
    void persist_step_size();
    void reset_step_size();

public:
    Bluetooth(char mode, bool debug, int step_size_look, int stop_distance, uint8_t motor1, uint8_t motor2, uint8_t motor3, uint8_t motor4,
              uint8_t ENABLEpin_1, uint8_t ENABLEpin_2, uint8_t trigPin, uint8_t echoPin);
    void act_on_cmd();
};
#endif
