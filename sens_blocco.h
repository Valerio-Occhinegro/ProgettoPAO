#ifndef SENS_BLOCCO_H
#define SENS_BLOCCO_H

#include <QWidget>
#include <QLabel>
#include <QVector>
#include <QString>
#include <QVBoxLayout>
#include "sensore.h"
#include "serra.h"
#include "sens_widget.h"

class Sens_blocco : public QWidget{
    Q_OBJECT
protected:
    QVBoxLayout* layout_blocco;
    QVBoxLayout* layout_sens;
    sens_widget* sWidget;
    Sensore *sensore;
    Serra * serra;
public:
    Sens_blocco(Serra *serra, QWidget *parent = nullptr); //riferimento al container di sensori di serra
    void addLayoutSens();
    Sensore * getSensore();

signals:
    void nuovo();

    void visualizza(Sensore*);


public slots:
    virtual void aggiungi()=0;// aggiunge un nuovo sens_widget->forse è meglio farlo in ogni blocco specializzato



};

#endif // SENS_BLOCCO_H
