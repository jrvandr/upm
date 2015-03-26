/*
 * Author: John Van Drasek <john.r.van.drasek@intel.com>
 * Copyright (c) 2014 Intel Corporation
 *
 * Description: I2C base class for UPM
 *
 */

#include "i2c.h"

using namespace upm;

I2C::I2C(int bus, uint8_t addr)
{
    m_bus = bus;
    m_addr = addr;
    m_i2c = mraa_i2c_init(m_bus);
}

I2C::~I2C()
{
    mraa_i2c_stop(m_i2c);
}

mraa_result_t
I2C::i2c_write(uint8_t* buf, int length)
{
    mraa_i2c_address(m_i2c, m_addr);
    return mraa_i2c_write(m_i2c, buf, length);
}

mraa_result_t
I2C::i2c_write_byte(uint8_t data)
{
    mraa_i2c_address(m_i2c, m_addr);
    return mraa_i2c_write_byte(m_i2c, data);
}

int
I2C::i2c_read(uint8_t** data, int length)
{
   return mraa_i2c_read(m_i2c, *data, length);
}

uint8_t
I2C::i2c_read_byte()
{
   return mraa_i2c_read_byte(m_i2c);
}

