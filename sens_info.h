#ifndef SENS_INFO_H
#define SENS_INFO_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>

#include "sensore.h"
#include "sensorinfovisitor.h"




class term_blocco;

class Sens_info : public QWidget, public SensorObserverInterface{
    Q_OBJECT
private:
    QLabel* name_label;
    QLabel* max;
    QLabel* min;
    QVBoxLayout *layout;

public:
    Sens_info( QWidget *parent = nullptr);
    void notify ( Sensore & sensore ) override ;
    void clear();

public slots:
    void visualizza(Sensore *);

};

#endif // SENS_INFO_H
