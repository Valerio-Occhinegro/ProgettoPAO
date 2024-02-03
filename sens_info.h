#ifndef SENS_INFO_H
#define SENS_INFO_H

#include <QWidget>
#include <QLabel>

#include "sensore.h"
#include "sensorinfovisitor.h"



class Sens_info : public QWidget{
    Q_OBJECT
private:
    const Sensore* InfoSensore;

public:
    Sens_info( Sensore* =0, QWidget *parent = nullptr);


    /*void setInfo(char * serra, char* test, char* max, char *min);/////////*/
public slots:

};

#endif // SENS_INFO_H
