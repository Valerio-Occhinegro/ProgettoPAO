#include "sens_blocco.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QString>

#include "sens_widget.h"


Sens_blocco::Sens_blocco(std::vector<const Sensore*>& sensori, QWidget *parent): QWidget{parent}{
    //layout che conterrà tutto il blocco
    QVBoxLayout* layout= new QVBoxLayout(this);
    layout->setAlignment(Qt::AlignCenter | Qt::AlignTop);

    //layout per i sens_widget a cui aggiungerò anche una barra per lo scroll laterale
    QVBoxLayout* layout_sens= new QVBoxLayout(this);
    layout_sens->setAlignment(Qt::AlignCenter | Qt::AlignTop);

    titolo= new QLabel();
    layout-> addWidget(titolo);



    /*for(ogni elemento presente nel contenitore serra)
    creo un sens_widget*/
    for(std::vector<const Sensore *>::const_iterator it = sensori.begin(); it!= sensori.end(); ++it){
        sens_widget *elemento=new sens_widget(*it, this);
        layout_sens->addWidget(elemento);//non ne ho idea ;)
    }

    QPushButton* nuovo = new QPushButton("nuovo");
    layout-> addWidget(nuovo);

}

void Sens_blocco::setTitolo(QString){
    titolo->setText(tipo);
}
