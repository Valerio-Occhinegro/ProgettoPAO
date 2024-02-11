#ifndef SENS_BLOCCO_H
#define SENS_BLOCCO_H

#include <QWidget>
#include <QLabel>
#include <QVector>
#include <QString>
#include <QVBoxLayout>

#include "../model/sensore.h"
#include "../model/serra.h"
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
    Sens_blocco(Serra *serra, QWidget *parent = nullptr);
    virtual  ~Sens_blocco()=default;
    void addLayoutSens();
    Sensore * getSensore();
    bool controllaNomi(std::string);

signals:
    void nuovo();

    void visualizza(Sensore*);

    void elimina(Sensore *);

    void modify(Sensore *, QString);

    void add(Sensore*);

public slots:
    virtual void aggiungi()=0;



};

#endif // SENS_BLOCCO_H
