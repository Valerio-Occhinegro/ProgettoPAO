#ifndef TERMOMETRO_H
#define TERMOMETRO_H

#include "sensore.h"

class Termometro : public Sensore{
private:
    std::vector<double> vect;
public:
    Termometro(std::string , std::vector<double> v = std::vector<double>() );
    std::string printMeasure() const override;
    std::vector<double> calcMeasure() override;
    void accept(SensorVisitorInterface & visitor) override;
};

#endif // TERMOMETRO_H
