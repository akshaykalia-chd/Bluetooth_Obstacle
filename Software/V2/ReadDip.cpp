#include "ReadDip.h"

ReadDip::ReadDip(uint8_t dip1, uint8_t dip2)
{
    _dip1 = dip1;
    _dip2 = dip2;
    _dip1_val = false;
    _dip2_val = false;
}

bool ReadDip::bool_map(int dip1_val, int dip2_val)
{
    if (dip1_val >= 512) //slected mid point of 1024 as the mode was fliping due to noise
    {
        _dip1_val = true;
    }
    else
    {
        _dip1_val = false;
    }

    if (dip2_val >= 512) //slected mid point of 1024 as the mode was fliping due to noise
    {
        _dip2_val = true;
    }
    else
    {
        _dip2_val = false;
    }
}

char ReadDip::mode()
{
    bool_map(analogRead(_dip1), analogRead(_dip2));
    if (_dip1_val & _dip2_val)
    {
        return '1';
    }
    if (_dip1_val & !_dip2_val)
    {
        return '2';
    }
    if (!_dip1_val & _dip2_val)
    {
        return '3';
    }
    if (!_dip1_val & !_dip2_val)
    {
        return '4';
    }
}
