#include "sens_blocco.h"

#include <QPushButton>
#include <QString>
#include <QInputDialog>
#include <QMessageBox>
#include <QScrollArea>
#include <QObject>


Sens_blocco::Sens_blocco(Serra* serra, QWidget *parent): QWidget(parent), serra(serra){

/*
    //layout che conterrà tutto il blocco
    layout_blocco= new QVBoxLayout(this);
    layout_blocco->setAlignment(Qt::AlignCenter | Qt::AlignTop);


    //layout per i sens_widget a cui aggiungerò anche una barra per lo scroll laterale
    layout_sens= new QVBoxLayout(this);
    layout_sens->setAlignment(Qt::AlignCenter | Qt::AlignTop);

    titolo= new QLabel();
    layout_blocco-> addWidget(titolo);

*/

    /*for(ogni elemento presente nel contenitore serra)
    creo un sens_widget*/
/*
for(std::vector< Sensore *>::const_iterator it = serra->getSensori().begin(); it!= serra->getSensori().end(); ++it){
        sens_widget *elemento=new sens_widget(*it,serra,this);
        elemento->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
        layout_sens->addWidget(elemento);


        connect(elemento, &sens_widget::mostra, this, &Sens_blocco::visualizza);

    }

    //serve un modo per fare il refresh ogni volta che aggiungo un sens_widget(observer???)
    QScrollArea *scrollArea = new QScrollArea;
    QWidget *scrollLayout= new QWidget;
    scrollLayout->setLayout(layout_sens);
    scrollLayout->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    scrollArea->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    scrollArea->setWidget(scrollLayout);

    layout_blocco->addWidget(scrollArea);


    QPushButton* nuovo = new QPushButton("nuovo");
    layout_blocco-> addWidget(nuovo);
    connect(nuovo, &QPushButton::pressed, this, &Sens_blocco::aggiungi);

*/
}



Sensore *Sens_blocco::getSensore(){
    return sensore;
}

bool Sens_blocco::controllaNomi(std::string str){
        if(serra->controlla(str)==true)
            return true;
        else
            return false;
}






