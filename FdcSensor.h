#ifndef _FDC_SENSOR
  #define _FDC_SENSOR
  
#include <Arduino.h>

#include <FDC1004.h>

#include "FdcController.h"
#include <Sensor.h>
#include <Value.h>

class FdcController;

class FdcSensor : public Sensor<unsigned long> {
  protected:
    FdcController* _controller;
    byte _sensorNum;
    Value<unsigned int>* _triggerMin;
    Value<unsigned int>* _triggerMax;

  public:
    FdcSensor(FdcController* controller, byte sensorNum, Value<unsigned int>* triggerMin, Value<unsigned int>* triggerMax) : _controller(controller), _sensorNum(sensorNum), _triggerMin(triggerMin), _triggerMax(triggerMax), Sensor() {}
    
    inline unsigned int requestSingleRead() { return 0; }
    
    void getSingleReadAsync(unsigned int* capValue);
    void getSingleReadSync(unsigned int* capValue);
    virtual unsigned long requestValue();
    virtual void refreshValue();
    bool isTouched();
};
  
#endif //_FDC_SENSOR
