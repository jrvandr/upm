/*
 *
 */
#pragma once

#include <sys/types.h>
#include <stdint.h>
#include <mraa/common.h>

namespace upm
{

class Accelerometer
{
public:
    Accelerometer(){};
    ~Accelerometer(){};
    virtual uint8_t getDeviceID(){};//Get device id-pure virtual?? why?? Allow user to instantiate Accelerometer?
    virtual void resetDevice(){}; //Reset hardware 
    virtual mraa_result_t calibrate(){}; //Calibrate the device
    virtual bool setSampleRate(uint8_t rate){}; //Set sampling rate of sensor(MMA7660_AUTOSLEEP_T sr)
    virtual float getHeading(){}; //Get heading
    
    //Axis
    virtual float* getAcceleration(); //Get the acceleration values
    virtual int16_t* getRawAccelValues(); //Get the raw acceleration values
    virtual int getVerifiedAxis(uint8_t axis){}; //Read axis and verify validity(MMA7660_REG_T axis)
    virtual uint8_t getScale(){}; //Get scale values from device
    virtual float setAccelScale(int16_t curData){}; //Scale acceleration data by tolerance values
    virtual int16_t getAccelX(){}; //Get X acceleration
    virtual int16_t getAccelY(){}; //Get Y acceleration
    virtual int16_t getAccelZ(){}; //Get Z acceleration
    virtual void setZeroX(float zeroX){}; //Set zero'd value on x axis
    virtual void setZeroY(float zeroY){}; //Set zero'd value on y axis
    virtual void setZeroZ(float zeroZ){}; //Set zero'd value on z axis

    //Coordinates
    virtual mraa_result_t getCoordinates(){}; //Get coordinates(return mraa_result_t?)
    virtual int16_t* getRawCoorData(){}; //Get raw coordinate data
    virtual int16_t getCoorX(){}; //Get X coordinate
    virtual int16_t getCoorY(){}; //Get Y coordinate
    virtual int16_t getCoorZ(){}; //Get Z coordinate

    //Modes
    virtual void setModeActive(){}; //Set the mode to active
    virtual void setModeStandby(){}; //Set the mode to standby(power saving mode)
    
    //Tilts
    virtual uint8_t getVerifiedTilt(){}; //Read tilt reg and verify validity
    virtual uint8_t tiltBackFront(){}; //Read tilt back/front bits 
    virtual uint8_t tiltLandscapePortrait(){}; //Read tilt landscape/portrait bits
    virtual bool tiltTap(){}; //Read tilt tap bits
    virtual bool tiltShake(){}; //Read tilt shake bits

    //Interrupt Service Routine
    virtual void installISR(int pin, void (*isr)(void *), void *arg){}; //Install ISR for when interrupts are called
    virtual void uninstallISR(){}; //Uninstall ISR
    virtual bool setInterruptBits(uint8_t ibits){}; //Enable interrupt generation based on bits passed in

protected:
    float m_accel[3];
    float m_offsets[3];
    int16_t m_rawaccel[3];
private:
    // Moved local variables to protected section to avoid having to make get
    // and set functions in derived classes
};

}
