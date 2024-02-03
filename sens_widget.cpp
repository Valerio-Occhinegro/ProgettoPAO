#include "sens_widget.h"
#include "sens_info.h"


#include <QInputDialog>
#include <QMessageBox>

sens_widget::sens_widget(const Sensore * sensore,Serra* serra, QWidget *parent/*, const Sens_info* display*/): QWidget(parent), sensore(sensore), serra(serra){

    layout_sens= new QHBoxLayout(this);
    layout_sens->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    bVisualizza = new QPushButton();
    bVisualizza->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    bVisualizza->setText(QString::fromStdString(sensore->getName()));
    layout_sens-> addWidget(bVisualizza);
    //connect(bVisualizza, &QPushButton::pressed, this, &sens_widget::visualizza);

    /*connect(visualizza, &QPushButton::pressed,/////////
            [&display,this](){
        display->setInfo(this->serra, this->sensore);
            }*/


    bModifica = new QPushButton("modifica");
    bModifica->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    layout_sens-> addWidget(bModifica);
    connect(bModifica, &QPushButton::pressed, this, &sens_widget::modifica);

    bElimina = new QPushButton("elimina");
    bElimina->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    layout_sens-> addWidget(bElimina);
    connect(bElimina, &QPushButton::pressed, this, &sens_widget::elimina);

}

void sens_widget::elimina(){
    QMessageBox conferma;

    conferma.setText("procedere all'eliminazione?");
    conferma.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    conferma.setDefaultButton(QMessageBox::Ok);
    int ret = conferma.exec();
    if(ret==QMessageBox::Ok){
        serra->remove(this->sensore);
        delete this;
    }
}



const Sensore * sens_widget::getSens()const{
    return sensore;
}

void sens_widget::modifica(){
    QString nome = QInputDialog::getText(this, tr("modifica sensore"),tr("cambia il nome:"), QLineEdit::Normal);
    std::string conversion=nome.toStdString();
    if(nome!="" && conversion.size()<=18){//se non do un nome al sensore, il sens widget non viene creato
        const_cast<Sensore*>(sensore)->setName(conversion);
        bVisualizza->setText(QString::fromStdString(sensore->getName()));
    }
    else if(conversion.size()>18)
        QMessageBox::warning(this, tr("Problema in input"), tr("il nome deve avere una dimensione inferiore a 19 caratteri"));
    else if(nome=="")
        QMessageBox::warning(this, tr("Problema in input"), tr("il nome non può essere vuoto"));
}




