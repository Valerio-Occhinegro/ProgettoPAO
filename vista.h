#ifndef VISTA_H
#define VISTA_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QHBoxLayout>

#include "sensore.h"
#include "termometro.h"
#include "sens_info.h"
#include "serra.h"

class Vista: public QWidget{
    Q_OBJECT
private:
    //per vedere se funziona
    Sensore* sensTest= new Termometro("test");
    //std::vector<const Sensore*> *sensori;
    //
    Sens_info *info;
    QVBoxLayout *mainLayout;
    QHBoxLayout *upLayout;
    QHBoxLayout *downLayout;

public:
    Vista(Serra *serra,QWidget *parent = nullptr);

    void addUpLayout();
    void addDownLayout(Serra *serra);

    //private:
    //Ui::MainWindow *ui;

};

#endif // VISTA_H





