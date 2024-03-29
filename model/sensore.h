#ifndef SENSORE_H
#define SENSORE_H

#include <string>
#include <vector>
#include "sensorvisitorinterface.h"
#include "sensorobserverinterface.h"

class Sensore{
private:
    std::string name;
    double min,max;
    double ampMin;
    double ampMax;
    double meanMin;
    double meanMax;
    std::vector<double> measure;
    std::vector <SensorObserverInterface * > observers ;
public:
    Sensore(std::string, double, double, double, double);
    virtual ~Sensore();
    //funzioni ausiliarie
    double randomizer(double , double );
    virtual std::string printMeasure() const=0;
    //funzioni get
    std::string getName() const;
    double getMin() const;
    double getMax() const;
    double getAmpMin() const;
    double getAmpMax() const;
    double getMeanMin() const;
    double getMeanMax() const;
    std::vector<double> getMeasure() const;
    //funzioni set
    void setMin();
    void setMax();
    void setMeasure();
    void setName(std::string &);

    void sensRicalcola();
    virtual std::vector<double> calcMeasure()=0;
    virtual void accept(SensorVisitorInterface & visitor) = 0;
    void registerObserver (SensorObserverInterface * obs);

};

#endif // SENSORE_H
