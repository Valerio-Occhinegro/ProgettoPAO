#include "term_blocco.h"
#include "../model/termometro.h"


#include <QInputDialog>
#include <QMessageBox>
#include <QScrollArea>

term_blocco::term_blocco(Serra * serra, QWidget *parent) : Sens_blocco(serra, parent) {
    QString t="Termometri";

    //layout che conterrà tutto il blocco
    layout_blocco= new QVBoxLayout(this);
    layout_blocco->setAlignment(Qt::AlignCenter | Qt::AlignTop);


    QLabel *titolo= new QLabel();
    titolo->setObjectName("Termometri");
    titolo->setText(t);
    titolo->setAlignment(Qt::AlignCenter);
    layout_blocco-> addWidget(titolo);


    //layout per i sens_widget a cui aggiungerò anche una barra per lo scroll laterale
    layout_sens= new QVBoxLayout();
    layout_sens->setAlignment(Qt::AlignCenter | Qt::AlignTop);




    std::vector<Sensore*>& vettoreSensori = serra->getSensori();
    for (Sensore* sensore : vettoreSensori) {
        if(dynamic_cast<Termometro*>(sensore)){

        sens_widget *elemento=new sens_widget(sensore,serra,this);
        elemento->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
        layout_sens->addWidget(elemento);

        connect(elemento, &sens_widget::mostra, this, &Sens_blocco::visualizza);
        connect(elemento, &sens_widget::eliminaInfo, this, &Sens_blocco::elimina);

        connect(elemento,&sens_widget::modify,this,&Sens_blocco::modify);


        }

    }

    QScrollArea *scrollArea = new QScrollArea;
    QWidget *scrollLayout= new QWidget;

    scrollLayout->setLayout(layout_sens);

    scrollArea->setWidgetResizable(true);

    scrollArea->setWidget(scrollLayout);

    scrollArea->setMinimumHeight(100);

    scrollArea->setMinimumWidth(350);

    layout_blocco->addWidget(scrollArea);


    QPushButton* nuovo = new QPushButton();
    nuovo->setIcon(QIcon("://icone/add.svg"));
    nuovo->setObjectName("bNuovo");
    layout_blocco-> addWidget(nuovo);
    connect(nuovo, &QPushButton::pressed, this, &Sens_blocco::aggiungi);



}

void term_blocco::aggiungi(){
    QInputDialog dialog;
    dialog.setCancelButtonText("annulla");
    QString nome = dialog.getText(this, tr("Creazione termometro"),tr("Nome termometro:"), QLineEdit::Normal);
    Sensore *nuovo;
    sens_widget *el;
    if(nome!="" && nome.size()<=18 && controllaNomi(nome.toStdString())==false){//se non do un nome al sensore, il sens widget non viene creato
        nuovo=new Termometro(nome.toStdString());
        el=new sens_widget(nuovo,serra,this);

        connect(el, &sens_widget::mostra, this, &Sens_blocco::visualizza);
        connect(el, &sens_widget::eliminaInfo, this, &Sens_blocco::elimina);
        connect(el,&sens_widget::modify,this,&Sens_blocco::modify);

        serra->insert(nuovo);
        layout_sens->addWidget(el);
        emit add(nuovo);
    }
    else if(nome.size()>18)
        QMessageBox::warning(this, tr("Problema in input"), tr("il nome deve avere una dimensione inferiore a 19 caratteri"));
    else if(controllaNomi(nome.toStdString())==true)
        QMessageBox::warning(this, tr("Problema in input"), tr("i sensori devono avere nomi differenti"));


}

