#ifndef SENS_INFO_H
#define SENS_INFO_H

#include <QWidget>
#include <QLabel>
#include "sensore.h"
#include "sens_widget.h"


class Sens_info : public QWidget{
    Q_OBJECT
private:
    const Sensore* InfoSensore;
    const sens_widget* sWidget;
    QLabel* name_label;
    QLabel* min_label;
    QLabel* max_label;
public:
    Sens_info(const sens_widget* =0, QWidget *parent = nullptr);
    void show();

    /*void setInfo(char * serra, char* test, char* max, char *min);/////////*/
public slots:

    void mostra(){
    };
};

#endif // SENS_INFO_H
