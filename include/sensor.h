/*
 *
 */

#pragma once
#include <mraa/common.h>

namespace upm
{
class Sensor
{
public:
    virtual ~Sensor(){};
    virtual mraa_result_t update() = 0; //Get data from sensor:Pure virtual-Each derived class must implement};
};
}
