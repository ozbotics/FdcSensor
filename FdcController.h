#ifndef _FDC_CONTROLLER_H
  #define _FDC_CONTROLLER_H
  
#include <Arduino.h>
#include <LinkedList.h>
#include <FDC1004.h>

#include "FdcSensor.h"


class FdcSensor;

class FdcController {
  protected:
    FDC1004 _fdc;
    byte _maxSensors;

    LinkedList<FdcSensor*> _motors = LinkedList<FdcSensor*>();
    byte _numMotors = 0;
    
  public:
    FdcController(byte maxSensors) : _maxSensors(maxSensors) {}
    
    int32_t getCapacitance(byte sensorNum) {
      return _fdc.getCapacitance(sensorNum);
    }
};

#endif //_FDC_CONTROLLER_H
