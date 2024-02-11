#ifndef SENSORINFOVISITOR_H
#define SENSORINFOVISITOR_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QList>
#include <QPixmap>
#include "sensorvisitorinterface.h"

class SensorInfoVisitor : public SensorVisitorInterface{
private:
    QPixmap  pix;
    QString minima;
    QString massima;
    QList<QPointF> valori;

public:
    QList<QPointF> getValori();
    QString  getMin();
    QString  getMax();
    QPixmap getPix();

    void visitTermometro(Termometro & termometro) override;
    void visitIgrometro(Igrometro & igrometro) override;
    void visitLuxometro(Luxometro & luxometro) override;
};

#endif // SENSORINFOVISITOR_H
