#include "vista.h"
#include "serra_widget.h"
#include "term_blocco.h"
#include "igro_blocco.h"
#include "lux_blocco.h"


#include <QMenuBar>



Vista::Vista(Serra *serra, QWidget *parent): QWidget(parent) {
    mainLayout= new QVBoxLayout(this);

    //creo due layout orizzontali
    upLayout= new QHBoxLayout(this);

    downLayout= new QHBoxLayout(this);

    addMenu();//aggiungo il menu

    addUpLayout();

    addDownLayout(serra);

    setLayout(mainLayout);
}


void Vista::addMenu(){
    QMenuBar* menubar= new QMenuBar(this);
    QMenu* menu= new QMenu("File",menubar);
    QAction* exit= new QAction("Exit",menu);

    menu->addAction(exit);

    menubar->addMenu(menu);

    mainLayout->addWidget(menubar);
}

void Vista::addUpLayout(){
    Serra_widget *serra= new Serra_widget();
    upLayout->addWidget(serra);

    Sens_info* info= new Sens_info(sensTest);///////////il sens test viene passato qui
    upLayout->addWidget(info);

    mainLayout->addLayout(upLayout);
}

void Vista::addDownLayout(Serra *serra){
    term_blocco *termometri=new term_blocco(serra);
    downLayout->addWidget(termometri);

    Igro_blocco *igrometri= new Igro_blocco(serra);
    downLayout->addWidget(igrometri);

    Lux_blocco *luxometri= new Lux_blocco(serra);
    downLayout->addWidget(luxometri);

    mainLayout->addLayout(downLayout);
}
