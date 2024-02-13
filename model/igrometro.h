#ifndef IGROMETRO_H
#define IGROMETRO_H

#include "sensore.h"

class Igrometro : public Sensore{
private:
    std::vector<double> vect;
public:
    Igrometro(std::string, std::vector<double> v = std::vector<double>() );
    std::string printMeasure() const override;
    std::vector<double> calcMeasure() override;
    void accept(SensorVisitorInterface &visitor) override;
};

#endif // IGROMETRO_H

