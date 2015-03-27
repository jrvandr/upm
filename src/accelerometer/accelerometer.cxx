#include "accelerometer.h"

using namespace upm;

Accelerometer::Accelerometer()
{
    
}

Accelerometer::~Accelerometer()
{

}

float* Accelerometer::getAcceleration()
{
    for(int i = 0; i < 3; i++){
        m_accel[i] = m_rawaccel[i] * m_offsets[i];
    }

    return &m_accel[0];
}


int16_t* Accelerometer::getRawValues()
{
    return &m_rawaccel[0];
}
