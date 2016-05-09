/** @file FdcController.h 
  *  Copyright (c) 2016 Ozbotics 
  *  Distributed under the MIT license (see LICENSE)
  */ 
#ifndef _FDC_CONTROLLER_H
  #define _FDC_CONTROLLER_H
  
#include <Arduino.h>
#include <LinkedList.h>
#include <FDC1004.h>

#include "FdcSensor.h"


class FdcSensor;

/**
 * FdcController 
 *
 * Provides interface to FDC1004 hardware. Shared by up to 4 FdcSensor(s)
 */
class FdcController {
  protected:
    FDC1004 _fdc;   /**< protected variable  _fdc FDC1004 Sensor driver */ 
    
  public:
  
   /**
    * Constructor
    */
    FdcController() {}
    
   /**
    * make a measurement on channelNum
    *
    * @return the measured capacitance value
    */    
    int32_t getCapacitance(byte channelNum) {
      return _fdc.getCapacitance(channelNum);
    }
};

#endif //_FDC_CONTROLLER_H
