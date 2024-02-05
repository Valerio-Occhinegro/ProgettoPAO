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
    //connect(termometri, &term_blocco::mostra_sensore, info, &Sens_info::visualizza);
    //connect(bVisualizza, &QPushButton::pressed, std::bind(&Sens_info::visualizza, this, sensore));
    // connetto il segnale di sens blocco allo slot di sens_info
    connect(termometri, &term_blocco::visualizza, this, &Vista::visualizza);
}

void Vista::visualizza(Sensore* s) {
    info->visualizza(s);
}


void Vista::addUpLayout(){
    Serra_widget *serra= new Serra_widget();
    upLayout->addWidget(serra);

    info= new Sens_info(sensTest);///////////il sens test viene passato qui
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
