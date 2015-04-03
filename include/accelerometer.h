/*
 *
 */
#pragma once

#include <sys/types.h>
#include <stdint.h>
#include <mraa/common.h>
#include "sensor.h"

namespace upm
{

class Accelerometer : public virtual Sensor
{
public:
    using Sensor::update;
    Accelerometer(){};
    virtual ~Accelerometer(){};
    //virtual mraa_result_t update() = 0; //Get data from sensor: Pure virtual - Each derived class must implement
    virtual mraa_result_t calibrate(){}; //Calibrate the device
    virtual float* getAcceleration(); //Get the acceleration values
    virtual int16_t* getRawAccelValues(); //Get the raw acceleration values
    virtual int16_t getAccelX(){}; //Get X acceleration
    virtual int16_t getAccelY(){}; //Get Y acceleration
    virtual int16_t getAccelZ(){}; //Get Z acceleration

protected:
    float m_accel[3];
    float m_offsets[3];
    int16_t m_rawaccel[3];
private:
    // Moved local variables to protected section to avoid having to make get
    // and set functions in derived classes
};

}
