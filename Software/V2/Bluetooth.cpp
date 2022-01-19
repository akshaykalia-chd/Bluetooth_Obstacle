#include "Bluetooth.h"

Bluetooth::Bluetooth(char mode, bool debug, int step_size_look, int stop_distance, uint8_t motor1,
                     uint8_t motor2, uint8_t motor3, uint8_t motor4, uint8_t ENABLEpin_1, uint8_t ENABLEpin_2, uint8_t trigPin,
                     uint8_t echoPin) : Obstacle(mode, debug, step_size_look, stop_distance, motor1, motor2, motor3, motor4, ENABLEpin_1, ENABLEpin_2, trigPin, echoPin)
{
    input_recived = false;
    act = false;
}

void Bluetooth::act_on_cmd()
{

    input_recived = false;
    act = false;
    read_input();
    cal_distance();
    act = (cmd != last_cmd) | input_recived;

    if (cmd == 55)
    {
        last_cmd = cmd;
        stop_moving(_step_size, _debug);
        last_action = "Stop";
        return;
    }

    if ((dist_to_obj<_stop_distance | dist_to_obj> 1150) & cmd == 49)
    {
        stop_moving(_step_size, _debug);
        last_action = "Stop";
        return;
    }

    if (cmd == 53) // Enable obstacle mode
    {
        start_moving();
        return;
    }

    if (cmd == 49 & (dist_to_obj > _stop_distance & dist_to_obj < 1150)) // Forward
    {
        move_forward(_step_size, _debug);
        last_action = "Move Forward";
        return;
    }

    if (cmd == 50 & act) // Backward
    {
        move_backward(_step_size, _debug);
        stop_moving(_step_size, _debug);
        last_action = "Move Backward";
        last_cmd = cmd;
        return;
    }

    if (cmd == 52 & act) //Right
    {
        turn_right(_step_size, _debug);
        stop_moving(_step_size, _debug);
        last_action = "Turn Right";
        last_cmd = cmd;
        return;
    }

    if (cmd == 51 & act) //Left
    {
        turn_left(_step_size, _debug);
        stop_moving(_step_size, _debug);
        last_action = "Turn Left";
        last_cmd = cmd;
        return;
    }

    if (cmd == 54 & act) //increment step size
    {
        increment_step_size();
        last_action = "Increment step size";
    }

    if (cmd == 56 & act) //decrement step size
    {
        decrement_step_size();
        last_action = "Decrement step size";
    }

    if (cmd == 57 & act) //persist step size
    {
        persist_step_size();
        last_action = "Persist step size";
    }
    if (cmd == 48 & act) //reset stepsize
    {
        reset_step_size();
        last_action = "Reset step size";
    }
}

void Bluetooth::read_input()
{
    if (Serial.available() > 0)
    {
        last_cmd = cmd;
        cmd = Serial.read();
        input_recived = true;
    }
    while (Serial.available() > 0)
    {
        Serial.read();
    }
}

void Bluetooth::decrement_step_size()
{
    if (_step_size > 100)
    {
        _step_size = _step_size - 10;
        eprom_val = eprom_val - 1;
    }
    else
    {
        _step_size = 100;
        eprom_val = 0;
    }
    last_cmd = cmd;
}

void Bluetooth::increment_step_size()
{
    _step_size = _step_size + 10;
    eprom_val = eprom_val + 1;
    last_cmd = cmd;
}

void Bluetooth::persist_step_size()
{
    if (EEPROM.read(1) != eprom_val)
    {
        EEPROM.write(1, eprom_val);
    }
    last_cmd = cmd;
}

void Bluetooth::reset_step_size()
{
    _step_size = 100;
    eprom_val = 0;
    last_cmd = cmd;
}
