#include "igro_blocco.h"
#include <QInputDialog>
#include <QMessageBox>
#include <QScrollArea>

#include "igrometro.h"
#include "sensorinfovisitor.h"

Igro_blocco::Igro_blocco(Serra* serra, QWidget *parent) : Sens_blocco(serra, parent) {
    QString t="Igrometri";
    //layout che conterrà tutto il blocco
    layout_blocco= new QVBoxLayout(this);
    layout_blocco->setAlignment(Qt::AlignCenter | Qt::AlignTop);

    QLabel *titolo= new QLabel();
    titolo->setText(t);
    titolo->setAlignment(Qt::AlignCenter);
    layout_blocco-> addWidget(titolo);


    //layout per i sens_widget a cui aggiungerò anche una barra per lo scroll laterale
    layout_sens= new QVBoxLayout(this);
    layout_sens->setAlignment(Qt::AlignCenter | Qt::AlignTop);



    std::vector<Sensore*>& vettoreSensori = serra->getSensori();
    for (Sensore* sensore : vettoreSensori) {
        if(dynamic_cast<Igrometro*>(sensore)){

            sens_widget *elemento=new sens_widget(sensore,serra,this);
            elemento->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
            layout_sens->addWidget(elemento);

            connect(elemento, &sens_widget::mostra, this, &Sens_blocco::visualizza);
        }
    }

    //serve un modo per fare il refresh ogni volta che aggiungo un sens_widget(observer???)
    QScrollArea *scrollArea = new QScrollArea;
    QWidget *scrollLayout= new QWidget;

    scrollLayout->setLayout(layout_sens);

    scrollArea->setWidgetResizable(true);

    scrollArea->setWidget(scrollLayout);

    layout_blocco->addWidget(scrollArea);


    QPushButton* nuovo = new QPushButton("nuovo");
    layout_blocco-> addWidget(nuovo);
    connect(nuovo, &QPushButton::pressed, this, &Sens_blocco::aggiungi);
}

void Igro_blocco::aggiungi(){
    QInputDialog dialog;
    dialog.setCancelButtonText("annulla");
    QString nome = dialog.getText(this, tr("Creazione igrometro"),tr("Nome igrometro:"), QLineEdit::Normal);
    Sensore *nuovo;
    sens_widget *el;
    if(nome!="" && nome.size()<=18){//se non do un nome al sensore, il sens widget non viene creato
        nuovo=new Igrometro(nome.toStdString());
        el=new sens_widget(nuovo,serra,this);

        connect(el, &sens_widget::mostra, this, &Sens_blocco::visualizza);


        serra->insert(nuovo);
        layout_sens->addWidget(el);
    }
    else if(nome.size()>18)
        QMessageBox::warning(this, tr("Problema in input"), tr("il nome deve avere una dimensione inferiore a 19 caratteri"));



}
