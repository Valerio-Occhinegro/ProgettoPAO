#include "sens_blocco.h"

#include <QPushButton>
#include <QString>

#include "sens_widget.h"


Sens_blocco::Sens_blocco(Serra* serra, QWidget *parent): QWidget{parent}{
    //layout che conterrà tutto il blocco
    layout_blocco= new QVBoxLayout(this);
    layout_blocco->setAlignment(Qt::AlignCenter | Qt::AlignTop);

    //layout per i sens_widget a cui aggiungerò anche una barra per lo scroll laterale
    layout_sens= new QVBoxLayout(this);
    layout_sens->setAlignment(Qt::AlignCenter | Qt::AlignTop);

    titolo= new QLabel();
    layout_blocco-> addWidget(titolo);



    /*for(ogni elemento presente nel contenitore serra)
    creo un sens_widget*/
    for(std::vector<const Sensore *>::const_iterator it = serra->getSensori().begin(); it!= serra->getSensori().end(); ++it){
        sens_widget *elemento=new sens_widget(*it, this);
        layout_sens->addWidget(elemento);//non ne ho idea ;)
    }

    layout_blocco-> addLayout(layout_sens);

    QPushButton* nuovo = new QPushButton("nuovo");
    layout_blocco-> addWidget(nuovo);

}

void Sens_blocco::setTitolo(QString & tipo){
    titolo->setText(tipo);
}



