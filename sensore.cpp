#include "sensore.h"
#include <random>
#include <algorithm>

Sensore::Sensore(std::string n,  double aMin, double aMax, double mMin, double mMax) : name(n), ampMin(aMin), ampMax(aMax), meanMin(mMin), meanMax(mMax) {}

Sensore::~Sensore(){}

double Sensore::randomizer(double min, double max){
    std::random_device rd;
    std::default_random_engine re(rd());

    std::uniform_real_distribution<double> dist(min, max);

    return dist(re);

}

std::string Sensore::getName() const{
    return name;
}

double Sensore::getMin() const{
    return min;
}

double Sensore::getMax() const{
    return max;
}

double Sensore::getAmpMin() const{
    return ampMin;
}

double Sensore::getAmpMax() const{
    return ampMax;
}

double Sensore::getMeanMin() const{
    return meanMin;
}

double Sensore::getMeanMax() const{
    return meanMax;
}

std::vector<double> Sensore::getMeasure() const{
    return measure;
}

void Sensore::setMin(){
    min=*(std::min_element(measure.begin(), measure.end()));
}

void Sensore::setMax(){
    max=*(std::max_element(measure.begin(), measure.end()));
}

void Sensore::setMeasure(){
    measure=calcMeasure();
}
