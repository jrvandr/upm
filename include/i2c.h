/*
 * Author: John Van Drasek <john.r.van.drasek@intel.com>
 * Copyright (c) 2014 Intel Corporation
 *
 * Description: I2C base class for UPM
 *
 */

#pragma once

#include <mraa/i2c.h>

namespace upm
{

class I2C
{
public:
    I2C(int bus, uint8_t addr);
    ~I2C();

    mraa_result_t write(uint8_t* buf, int length);
    mraa_result_t writeByte(uint8_t data);
    int read(uint8_t** data, int length);
    uint8_t readByte();

    mraa_result_t writeReg(uint8_t reg, uint8_t value);
    uint16_t readReg_16 (int reg);
    uint8_t readReg_8 (int reg);

private:
    int m_bus;
    uint8_t m_addr;
    mraa_i2c_context m_i2c_ctx;
};

}
