#ifndef SENSOROBSERVERINTERFACE_H
#define SENSOROBSERVERINTERFACE_H

class Sensore;

class SensorObserverInterface{

public:
    virtual ~SensorObserverInterface()= default;
    virtual void notify(Sensore &sensore)=0;
};

#endif // SENSOROBSERVERINTERFACE_H
