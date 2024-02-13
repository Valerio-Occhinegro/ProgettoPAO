#ifndef IGROMETRO_H
#define IGROMETRO_H

#include "sensore.h"

class Igrometro : public Sensore{
public:
    Igrometro(std::string);
    std::string printMeasure() const override;
    std::vector<double> calcMeasure() override;
    void accept(SensorVisitorInterface &visitor) override;
};

#endif // IGROMETRO_H

