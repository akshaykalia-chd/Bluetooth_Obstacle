#ifndef READDIP_H
#define READDIP_H
#include <Arduino.h>
class ReadDip
{
private:
  uint8_t _dip1;
  uint8_t _dip2;
  bool _dip1_val;
  bool _dip2_val;
  bool bool_map(int dip1_val, int dip2_val);

public:
  ReadDip(uint8_t dip1, uint8_t dip2);
  char dip_mode();
};

#endif
