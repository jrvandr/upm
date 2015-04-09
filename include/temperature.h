/*
 *
 */
#pragma once

#include <sys/types.h>
#include <stdint.h>
#include <mraa/common.h>
//#include "sensor.h"

namespace upm
{

//class Temperature : public virtual Sensor
class Temperature 
{
public:
//    using Sensor::update;
    Temperature(){};
    virtual ~Temperature(){};
    virtual mraa_result_t update(){};// = 0; //Get data from sensor: Pure virtual - Each derived class must implement
    virtual float getTemperature(); //Get the acceleration values

protected:
    float m_temperature;
private:
    // Moved local variables to protected section to avoid having to make get
    // and set functions in derived classes
};

}
