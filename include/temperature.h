/*
 *
 */
#pragma once

#include <sys/types.h>
#include <stdint.h>
#include <mraa/common.h>

namespace upm
{

class Temperature 
{
public:
    Temperature():m_temperature(0.0f){};
    virtual ~Temperature(){};
    virtual mraa_result_t update(){}; //Get data from sensor
    virtual float getTemperature(); 

protected:
    float m_temperature;
};

}
