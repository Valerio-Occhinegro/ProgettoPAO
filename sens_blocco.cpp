#include "sens_blocco.h"

#include <QPushButton>
#include <QString>
#include <QInputDialog>
#include <QMessageBox>
#include <QScrollArea>
#include <QObject>



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


}

void Sens_blocco::setTitolo(QString & tipo){
    titolo->setText(tipo);
}

Sensore *Sens_blocco::getSensore(){
    return sensore;
}

//considerare di implementare la funzione in ogni tipo di blocco
void Sens_blocco::aggiungi(){
    QInputDialog dialog;
    dialog.setCancelButtonText("annulla");
    QString nome = dialog.getText(this, tr("Creazione sensore"),tr("Nome sensore:"), QLineEdit::Normal);
    Sensore *nuovo;
    sens_widget *el;
    if(nome!="" && nome.size()<=18){//se non do un nome al sensore, il sens widget non viene creato
        nuovo=new Termometro(nome.toStdString());
        el=new sens_widget(nuovo,serra,this);

        connect(el, &sens_widget::mostra, this, &Sens_blocco::visualizza);


        serra->insert(nuovo);
        layout_sens->addWidget(el);
    }
    else if(nome.size()>18)
        QMessageBox::warning(this, tr("Problema in input"), tr("il nome deve avere una dimensione inferiore a 19 caratteri"));


}






