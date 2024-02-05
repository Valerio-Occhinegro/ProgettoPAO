#ifndef SENSORINFOVISITOR_H
#define SENSORINFOVISITOR_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "sensorvisitorinterface.h"

class SensorInfoVisitor : public SensorVisitorInterface{
private:
    QWidget * widget;
    QString minima;
    QString massima;

public:

    QWidget* getWidget();
    QString  getMin();
    QString  getMax();

    void visitTermometro(Termometro & termometro) override;
    void visitIgrometro(Igrometro & igrometro) override;
    void visitLuxometro(Luxometro & luxometro) override;
};

#endif // SENSORINFOVISITOR_H
