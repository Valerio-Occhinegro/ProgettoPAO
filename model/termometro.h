#ifndef TERMOMETRO_H
#define TERMOMETRO_H

#include "sensore.h"

class Termometro : public Sensore{
public:
    Termometro(std::string);
    std::string printMeasure() const override;
    std::vector<double> calcMeasure() override;
    void accept(SensorVisitorInterface & visitor) override;
};

#endif // TERMOMETRO_H
