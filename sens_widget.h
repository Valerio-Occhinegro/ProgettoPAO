#ifndef SENS_WIDGET_H
#define SENS_WIDGET_H

#include <QWidget>
#include <QLabel>
#include "sensore.h"

class sens_widget : public QWidget{
    Q_OBJECT

private:
    const Sensore* sensore;
    QLabel* name_label;
public:
    sens_widget(const Sensore * sensore, QWidget *parent = nullptr);

signals:
    void modifica();
    void elimina();
};

#endif // SENS_WIDGET_H
