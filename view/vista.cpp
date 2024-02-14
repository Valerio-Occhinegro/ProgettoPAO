#include "vista.h"
#include "serra_widget.h"
#include "mainwindow.h"


#include <QMenuBar>



Vista::Vista(Serra *serra, QWidget *parent): QWidget(parent), serra(serra) {
    mainLayout= new QVBoxLayout(this);

    //creo due layout orizzontali
    upLayout= new QHBoxLayout();

    downLayout= new QHBoxLayout();

    addUpLayout(serra);

    addDownLayout(serra);

    setLayout(mainLayout);

    connect(termometri, &term_blocco::visualizza, this, &Vista::visualizza);
    connect(igrometri, &Igro_blocco::visualizza, this, &Vista::visualizza);
    connect(luxometri, &Lux_blocco::visualizza, this, &Vista::visualizza);

    //connetto la searchBar al sensInfo
    connect(serraW, &Serra_widget::visualizza,this,&Vista::visualizza);

    //connetto il tasto elimina allo slot elimina di info
    connect(termometri, &term_blocco::elimina, this, &Vista::eliminaSI);
    connect(igrometri, &Igro_blocco::elimina, this, &Vista::eliminaSI);
    connect(luxometri, &Lux_blocco::elimina, this, &Vista::eliminaSI);

    //Quando eseguo un'eliminazione il completer viene aggiornato

    connect(termometri, &Lux_blocco::modify, this, &Vista::modify);
    connect(igrometri, &Lux_blocco::modify, this, &Vista::modify);
    connect(luxometri, &Lux_blocco::modify, this, &Vista::modify);

    connect(termometri, &Lux_blocco::add, this, &Vista::add);
    connect(igrometri, &Lux_blocco::add, this, &Vista::add);
    connect(luxometri, &Lux_blocco::add, this, &Vista::add);

    //connect(parent, &MainWindow::refresh, this, &Vista::refresh);
}

void Vista::visualizza(Sensore* s) {
    info->visualizza(s);
}

void Vista::eliminaSI(Sensore *s){
    info->cancel(s);
    serraW->cancel(s);
}

void Vista::add(Sensore * s){
    serraW->add(s);
}

void Vista::modify(Sensore * s, QString n){
    serraW->modify(s,n);

}

/*void Vista::refresh(){
    delete termometri;delete igrometri; delete luxometri;
    termometri=new term_blocco(serra);
    igrometri=new Igro_blocco(serra);
    luxometri=new Lux_blocco(serra);
}*/


void Vista::addUpLayout(Serra *serra){
    serraW= new Serra_widget(serra);
    serraW->setMaximumWidth(200);
    upLayout->addWidget(serraW);

    info= new Sens_info();
    info->setMinimumWidth(800);
    upLayout->addWidget(info);

    mainLayout->addLayout(upLayout);
}

void Vista::addDownLayout(Serra *serra){
    termometri=new term_blocco(serra);
    downLayout->addWidget(termometri);

    igrometri= new Igro_blocco(serra);
    downLayout->addWidget(igrometri);

    luxometri= new Lux_blocco(serra);
    downLayout->addWidget(luxometri);

    mainLayout->addLayout(downLayout);
}
