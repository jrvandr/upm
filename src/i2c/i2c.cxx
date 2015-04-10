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
    m_i2c_ctx = mraa_i2c_init(m_bus);
}

I2C::~I2C()
{
    mraa_i2c_stop(m_i2c_ctx);
}

mraa_result_t
I2C::write(uint8_t* buf, int length)
{
    mraa_i2c_address(m_i2c_ctx, m_addr);
    return mraa_i2c_write(m_i2c_ctx, buf, length);
}

mraa_result_t
I2C::writeByte(uint8_t data)
{
    mraa_i2c_address(m_i2c_ctx, m_addr);
    return mraa_i2c_write_byte(m_i2c_ctx, data);
}

int
I2C::read(uint8_t** data, int length)
{
   return mraa_i2c_read(m_i2c_ctx, *data, length);
}

uint8_t
I2C::readByte()
{
   return mraa_i2c_read_byte(m_i2c_ctx);
}

mraa_result_t I2C::writeReg(uint8_t reg, uint8_t value)
{
    mraa_result_t error = MRAA_SUCCESS;

    uint8_t data[2] = { reg, value };
    mraa_i2c_address (m_i2c_ctx, m_addr);
    error = mraa_i2c_write (m_i2c_ctx, data, 2);

    return error;

}

uint16_t I2C::readReg_16 (int reg)
{
    uint16_t data;
    mraa_i2c_address(m_i2c_ctx, m_addr);
    data  = (uint16_t)mraa_i2c_read_byte_data(m_i2c_ctx, reg) << 8;
    data |= (uint16_t)mraa_i2c_read_byte_data(m_i2c_ctx, reg+1);
    return data;
}

uint8_t I2C::readReg_8 (int reg)
{
    mraa_i2c_address(m_i2c_ctx, m_addr);
    return mraa_i2c_read_byte_data(m_i2c_ctx, reg);
}

