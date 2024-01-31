#include "sens_blocco.h"

#include <QPushButton>
#include <QString>
#include <QInputDialog>

#include "sens_widget.h"
#include "termometro.h"


Sens_blocco::Sens_blocco(Serra* serra, QWidget *parent): QWidget(parent), serra(serra){
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
        sens_widget *elemento=new sens_widget(*it,serra,this);
        layout_sens->addWidget(elemento);//non ne ho idea ;)
    }

    layout_blocco-> addLayout(layout_sens);

    QPushButton* nuovo = new QPushButton("nuovo");
    layout_blocco-> addWidget(nuovo);
    connect(nuovo, &QPushButton::pressed, this, &Sens_blocco::aggiungi);

}

void Sens_blocco::setTitolo(QString & tipo){
    titolo->setText(tipo);
}

//considerare di implementare la funzione in ogni tipo di blocco
void Sens_blocco::aggiungi(){
    QString nome = QInputDialog::getText(this, tr("Creazione sensore"),tr("Nome sensore:"), QLineEdit::Normal);
    const Sensore *nuovo;
    sens_widget *el;
    if(nome!="")
    nuovo=new Termometro(nome.toStdString());
    else
    nuovo=new Termometro("padre dovevi darmi un nome :(");

    el=new sens_widget(nuovo,serra,this);
    //el->getSens()->setName("boh");
    serra->insert(nuovo);
    layout_sens->addWidget(el);
}



