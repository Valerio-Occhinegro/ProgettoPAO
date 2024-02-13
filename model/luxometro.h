#ifndef LUXOMETRO_H
#define LUXOMETRO_H

#include "sensore.h"

class Luxometro : public Sensore{
private:
    std::vector<double> vect;
public:
    Luxometro(std::string, std::vector<double> v = std::vector<double>() );
    std::string printMeasure() const override;
    std::vector<double> calcMeasure() override;
    void accept(SensorVisitorInterface &visitor) override;
};

#endif // LUXOMETRO_H

