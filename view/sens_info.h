#ifndef SENS_INFO_H
#define SENS_INFO_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPointF>
#include <QList>
#include <QtCharts/QtCharts>
#include <QPixmap>

#include "../model/sensore.h"






class term_blocco;

class Sens_info : public QWidget, public SensorObserverInterface{
    Q_OBJECT
private:
    QLabel* name_label;
    QLabel* max;
    QLabel* min;
    QLabel *logo;
    QPushButton * bRicalcola;
    QPushButton * bElimina;
    QPushButton * bModifica;
    Sensore *sensore;
    QList<QPointF> dati;
    QLineSeries * series;
    QChart * chart;
    QChartView *chartView;
    QHBoxLayout *mainLayout;
    QVBoxLayout *layout;

public:
    Sens_info( QWidget *parent = nullptr);
    void notify ( Sensore & sensore ) override ;
    void clear();
public slots:
    void visualizza(Sensore *);
    void ricalcola();
    void cancel(Sensore *);

};

#endif // SENS_INFO_H
