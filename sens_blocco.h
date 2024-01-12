#ifndef SENS_BLOCCO_H
#define SENS_BLOCCO_H

#include <QWidget>
#include <QLabel>
#include <QVector>
#include <QString>
#include "sensore.h"

class Sens_blocco : public QWidget{
    Q_OBJECT
private:
    QLabel* titolo;//il titolo del blocco rappresenta la tipologia di sensori contenuti al suo interno


public:
    Sens_blocco(std::vector<const Sensore*>& sensori, QWidget *parent = nullptr); //riferimento al container di sensori di serra
    void setTitolo(QString & );
signals:
};

#endif // SENS_BLOCCO_H
