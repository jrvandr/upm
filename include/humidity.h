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

//class Humidity : public virtual Sensor
class Humidity 
{
public:
//    using Sensor::update;
    Humidity(){};
    virtual ~Humidity(){};
    virtual mraa_result_t update(){};// = 0; //Get data from sensor: Pure virtual - Each derived class must implement
    virtual float getHumidity(); //Get the acceleration values

protected:
    float m_humidity;
private:
    // Moved local variables to protected section to avoid having to make get
    // and set functions in derived classes
};

}
