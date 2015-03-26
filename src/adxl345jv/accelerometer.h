/*
 *
 */
#pragma once

#include <sys/types.h>

namespace upm
{

class Accelerometer
{
public:
    Accelerometer();
    ~Accelerometer();
    float* getAcceleration();
    int16_t* getRawValues(); 
protected:
    float m_accel[3];
    float m_offsets[3];
    int16_t m_rawaccel[3];
private:
    // Moved local variables to protected section to avoid having to make get
    // and set functions in derived classes


};

}
