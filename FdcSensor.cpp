#include "FdcSensor.h"

void FdcSensor::getSingleReadAsync(unsigned int* capValue) {
  *capValue = _controller->getCapacitance(_channelNum);
}

void FdcSensor::getSingleReadSync(unsigned int* capValue) {
  delay(requestSingleRead());
  getSingleReadAsync(capValue);
}

unsigned long FdcSensor::requestValue() { return requestSingleRead(); }

void FdcSensor::refreshValue() {
  unsigned int capValue;
  
  getSingleReadAsync(&capValue);
  value->setValue(capValue);    
}

bool FdcSensor::isTouched() {
  refreshValue();
  
  return ( (value->getValue() >= _triggerMin->getValue()) && (value->getValue() <= _triggerMax->getValue()) ); 
}