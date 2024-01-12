#ifndef SENS_INFO_H
#define SENS_INFO_H

#include <QWidget>
#include <QLabel>
#include "sensore.h"

class Sens_info : public QWidget{
    Q_OBJECT
private:
    const Sensore* sensore;
    QLabel* name_label;
    QLabel* min_label;
    QLabel* max_label;
public:
    Sens_info(const Sensore *sensore, QWidget *parent = nullptr);
    void show();
signals:
};

#endif // SENS_INFO_H
