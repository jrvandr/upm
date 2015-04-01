/*
 * Author: Mihai Tudor Panu <mihai.tudor.panu@intel.com>
 * Copyright (c) 2014 Intel Corporation.
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
 * LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
 * OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
 * WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */
#pragma once

//#include <mraa/i2c.h>
#include "i2c.h"
#include "accelerometer.h"

#define READ_BUFFER_LENGTH 6

//address and id
#define ADXL345_I2C_ADDR 0x53
#define ADXL345_ID 0x00

//control registers
#define ADXL345_OFSX 0x1E
#define ADXL345_OFSY 0x1F
#define ADXL345_OFSZ 0x20
#define ADXL345_TAP_THRESH 0x1D
#define ADXL345_TAP_DUR 0x21
#define ADXL345_TAP_LATENCY 0x22
#define ADXL345_ACT_THRESH 0x24
#define ADXL345_INACT_THRESH 0x25
#define ADXL345_INACT_TIME 0x26
#define ADXL345_INACT_ACT_CTL 0x27
#define ADXL345_FALL_THRESH 0x28
#define ADXL345_FALL_TIME 0x29
#define ADXL345_TAP_AXES 0x2A
#define ADXL345_ACT_TAP_STATUS 0x2B

//interrupt registers
#define ADXL345_INT_ENABLE 0x2E
#define ADXL345_INT_MAP 0x2F
#define ADXL345_INT_SOURCE 0x30

//data registers (read only)
#define ADXL345_XOUT_L 0x32
#define ADXL345_XOUT_H 0x33
#define ADXL345_YOUT_L 0x34
#define ADXL345_YOUT_H 0x35
#define ADXL345_ZOUT_L 0x36
#define ADXL345_ZOUT_H 0x37
#define DATA_REG_SIZE 6

//data and power management
#define ADXL345_BW_RATE 0x2C
#define ADXL345_POWER_CTL 0x2D
#define ADXL345_DATA_FORMAT 0x31
#define ADXL345_FIFO_CTL 0x38
#define ADXL345_FIFO_STATUS 0x39

//useful values
#define ADXL345_POWER_ON 0x08
#define ADXL345_AUTO_SLP 0x30
#define ADXL345_STANDBY 0x00

//scales and resolution
#define ADXL345_FULL_RES 0x08
#define ADXL345_10BIT 0x00
#define ADXL345_2G 0x00
#define ADXL345_4G 0x01
#define ADXL345_8G 0x02
#define ADXL345_16G 0x03

namespace upm {

/**
 * @brief Adxl345 accelerometer library
 * @defgroup adxl345 libupm-adxl345
 * @ingroup seeed i2c accelerometer
 */

/**
 * @library adxl345
 * @sensor adxl345
 * @comname Adxl345 3-Axis Digital Accelerometer
 * @type accelerometer
 * @man seeed
 * @con i2c
 *
 * @brief C++ API for Adxl345 (3-axis digital accelerometer)
 *
 * The Adxl345 is a 3-axis digital accelerometer.
 * (http://www.seeedstudio.com/wiki/images/2/2c/ADXL345_datasheet.pdf)
 * The sensor has configurable resolutions for measuring ±2g, ±4g, ±8g or ±16g.
 * Note that the sensor it is incompatible and will not be detected on the I2C bus
 * by the Intel Edison using the Arduino breakout board at 5V (3V3 will work fine).
 *
 * @image html adxl345.jpeg
 * @snippet adxl345.cxx Interesting
 */
class Adxl345 : public Accelerometer {
public:
    /**
     * Creates an Adxl345 object
     *
     * @param bus number of used i2c bus
     */
    Adxl345(int bus, uint8_t address = ADXL345_I2C_ADDR);

    /**
     * Adxl345 object destructor
     */
    ~Adxl345();

    /**
     * Returns the device id
     *
     * @return uint8_t 
     */
//    uint8_t getDeviceID (){}; 

    /**
     * Returns a pointer to a float[3] that contains acceleration (g) forces
     *
     * @return float* to a float[3]
     */
//    float* getAcceleration();

    /**
     * Returns a pointer to an int[3] that contains the raw register values for X, Y and Z
     *
     * @return int* to an int[3]
     */
//    int16_t* getRawValues();

    /**
     * Returns the scale the accelerometer is currently set up to: 2, 4, 8 or 16
     *
     * @return uint with current scale value
     */
    uint8_t getScale();

    /**
     * Updates the acceleration values from i2c bus
     *
     * @return 0 for success
     */
    mraa_result_t update();
private:
//    float m_accel[3];
//    float m_offsets[3];
//    int16_t m_rawaccel[3];
    uint8_t m_buffer[READ_BUFFER_LENGTH];
//    mraa_i2c_context m_i2c;

    // Must provide a connection type in the derived class
    I2C m_i2c_conn;
};

}
