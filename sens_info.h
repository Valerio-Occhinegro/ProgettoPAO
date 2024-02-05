#ifndef SENS_INFO_H
#define SENS_INFO_H

#include <QWidget>
#include <QLabel>
#include <QObject>

#include "sensore.h"
#include "sensorinfovisitor.h"


class term_blocco;

class Sens_info : public QWidget, public SensorObserverInterface{
    Q_OBJECT
private:
    Sensore* InfoSensore;
    term_blocco* tBlocco;
    QLabel* name_label;

public:
    Sens_info( Sensore* =0, QWidget *parent = nullptr);
    void notify ( Sensore & sensore ) override ;


    /*void setInfo(char * serra, char* test, char* max, char *min);/////////*/
public slots:
    void visualizza(Sensore *);

};

#endif // SENS_INFO_H
