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

#include "serra.h"
#include "sens_widget.h"
#include "sensore.h"

class Serra_widget : public QWidget{
    Q_OBJECT
private:
    Sensore *sensore;
    Serra * serra;
    QLabel* name;
    QVBoxLayout*layout_serra;
    QPushButton *send;
    QCompleter *completer;

    QStringList * listaNomi;
    QVector<sens_widget *> bVettore;


    QLineEdit * search;
    QVBoxLayout * results;

public:
    Serra_widget(Serra *, QWidget *parent = nullptr);
    void populate();
    void generate();

signals:
    void visualizza(Sensore *);
};

#endif // SERRA_WIDGET_H
