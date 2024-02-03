#ifndef LUXOMETRO_H
#define LUXOMETRO_H

#include "sensore.h"

class Luxometro : public Sensore{
public:
    Luxometro(std::string);
    void printMeasure() const override;
    std::vector<double> calcMeasure() override;
    void accept(SensorVisitorInterface &visitor) override;
};

#endif // LUXOMETRO_H

