#ifndef VISTA_H
#define VISTA_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QHBoxLayout>

#include "sensore.h"
#include "termometro.h"///////
#include "igrometro.h"////
#include "luxometro.h"/////
#include "term_blocco.h"
#include "igro_blocco.h"
#include "lux_blocco.h"


#include "sens_info.h"
#include "serra.h"
#include "serra_widget.h"

class Vista: public QWidget{
    Q_OBJECT
private:
    //per vedere se funziona
    //Sensore* sensTest= new Luxometro("test");
    //std::vector<const Sensore*> *sensori;
    //
    Serra_widget *serraW;
    Sens_info *info;
    term_blocco *termometri;
    Igro_blocco *igrometri;
    Lux_blocco *luxometri;
    QVBoxLayout *mainLayout;
    QHBoxLayout *upLayout;
    QHBoxLayout *downLayout;

public:
    Vista(Serra *serra,QWidget *parent = nullptr);

    void addUpLayout(Serra *serra);
    void addDownLayout(Serra *serra);

    //private:
    //Ui::MainWindow *ui;
public slots:
    void visualizza(Sensore *);
    void eliminaSI(Sensore *);
    void add(Sensore *);
    void modify(Sensore *, QString);
};

#endif // VISTA_H





