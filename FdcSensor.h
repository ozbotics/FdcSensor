/** @file FdcController.h 
  *  Copyright (c) 2016 Ozbotics 
  *  Distributed under the MIT license (see LICENSE)
  */ 
#ifndef _FDC_SENSOR
  #define _FDC_SENSOR
  
#include <Arduino.h>

#include <FDC1004.h>

#include "FdcController.h"
#include <Sensor.h>
#include <TouchableSensor.h>

#include <Value.h>


class FdcController;

/**
 * FdcSensor 
 *
 * Provides Sensor and TouchableSensor interfaces to the FDC1004
 */
class FdcSensor : public Sensor<unsigned long>, public TouchableSensor {
  protected:
    FdcController* _controller;        /**< protected variable  _controller Pointer to to the FdcController */ 
    byte _channelNum;                  /**< protected variable  _channelNum channel identifier */ 
    Value<unsigned int>* _triggerMin;  /**< protected variable  _triggerMin Minimum reading for isTouched range*/ 
    Value<unsigned int>* _triggerMax;  /**< protected variable  _triggerMax Maximum reading for isTouched range */ 

  public:
  
   /**
    * Constructor
    *
    * @param controller Pointer to the FdcController
    * @param channelNum The channel identifier
    * @param triggerMin Minimum reading for isTouched range
    * @param triggerMax Maximum reading for isTouched range
    */
    FdcSensor(FdcController* controller, byte channelNum, Value<unsigned int>* triggerMin, Value<unsigned int>* triggerMax) : _controller(controller), _channelNum(channelNum), _triggerMin(triggerMin), _triggerMax(triggerMax), Sensor() {}

   /**
    * request that a reading be made
    *
    * @return the Duruation until the reading will be available
    */
    inline unsigned int requestSingleRead() { return 0; }
    
   /**
    * get the value of the previously requested reading
    *
    * @return the value read by the sensor
    */
    void getSingleReadAsync(unsigned int* capValue);
    
    
   /**
    * requet a reading, then block until the requested reading is available
    * 
    * @param capValue Pointer to Capacitive Value 
    */
    void getSingleReadSync(unsigned int* capValue);
    
   /**
    * request that a value be generated
    *
    * @return the Duruation until the value will be available
    */
    virtual unsigned long requestValue();
    
   /**
    * update the Sensor value
    */
    virtual void refreshValue();
    
    
   /**
    * Implement TouchableSensor::isTouched()
    *
    * @return true if the sensor is touched (within triggerMin - triggerMax range)
    */
    bool isTouched();
};
  
#endif //_FDC_SENSOR
