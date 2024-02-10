#ifndef SENSORVISITORINTERFACE_H
#define SENSORVISITORINTERFACE_H

class Termometro;
class Igrometro;
class Luxometro;

class SensorVisitorInterface
{
public:

    virtual ~SensorVisitorInterface() = default;
    virtual void visitTermometro(Termometro & termometro) = 0;
    virtual void visitIgrometro(Igrometro & igrometro) = 0;
    virtual void visitLuxometro(Luxometro & luxometro) = 0;
};

#endif // SENSORVISITORINTERFACE_H
