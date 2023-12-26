#ifndef IGROMETRO_H
#define IGROMETRO_H

#include "sensore.h"

class Igrometro : public Sensore{
public:
    Igrometro(std::string);
    void printMeasure() const override;
    std::vector<double> calcMeasure() override;
};

#endif // IGROMETRO_H

