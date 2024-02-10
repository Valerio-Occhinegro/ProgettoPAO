#ifndef SERRA_WIDGET_H
#define SERRA_WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QVector>
#include <QStringList>
#include <QLabel>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QCompleter>

#include "../model/sensore.h"
#include "../model/serra.h"
#include "sens_widget.h"


class Serra_widget : public QWidget{
    Q_OBJECT
private:
    Sensore *sensore;
    Serra * serra;
    QLabel* name;
    QHBoxLayout*layout_serra;
    QPushButton *send;
    QCompleter *completer;

    QStringList * listaNomi;
    QVector<sens_widget *> bVettore;


    QLineEdit * search;


public:
    Serra_widget(Serra *, QWidget *parent = nullptr);
    void populate();
    void generate();
    void cancel(Sensore *);
    void modify(Sensore * , QString);
    void add(Sensore *);


signals:
    void visualizza(Sensore *);
};

#endif // SERRA_WIDGET_H
