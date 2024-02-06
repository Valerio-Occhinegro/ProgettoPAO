#include "vista.h"
#include "serra_widget.h"


#include <QMenuBar>



Vista::Vista(Serra *serra, QWidget *parent): QWidget(parent) {
    mainLayout= new QVBoxLayout(this);

    //creo due layout orizzontali
    upLayout= new QHBoxLayout(this);

    downLayout= new QHBoxLayout(this);

    addUpLayout();

    addDownLayout(serra);

    setLayout(mainLayout);

    connect(termometri, &term_blocco::visualizza, this, &Vista::visualizza);
    connect(igrometri, &Igro_blocco::visualizza, this, &Vista::visualizza);
    connect(luxometri, &Lux_blocco::visualizza, this, &Vista::visualizza);
    //connetto il tasto elimina allo slot elimina di info
    connect(termometri, &term_blocco::elimina, this, &Vista::eliminaSI);
    connect(igrometri, &Igro_blocco::elimina, this, &Vista::eliminaSI);
    connect(luxometri, &Lux_blocco::elimina, this, &Vista::eliminaSI);
}

void Vista::visualizza(Sensore* s) {
    info->visualizza(s);
}

void Vista::eliminaSI(Sensore *s){
    info->cancel(s);
}


void Vista::addUpLayout(){
    Serra_widget *serra= new Serra_widget();
    upLayout->addWidget(serra);

    info= new Sens_info();///////////il sens test viene passato qui
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
