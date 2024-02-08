#include "sens_widget.h"



#include <QInputDialog>
#include <QMessageBox>

sens_widget::sens_widget(Sensore * sensore,Serra* serra, QWidget *parent): QWidget(parent), sensore(sensore), serra(serra){

    layout_sens= new QHBoxLayout(this);
    layout_sens->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    bVisualizza = new QPushButton();
    bVisualizza->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    bVisualizza->setText(QString::fromStdString(sensore->getName()));
    layout_sens-> addWidget(bVisualizza);

    connect(bVisualizza, &QPushButton::pressed, std::bind(&sens_widget::mostra, this,sensore));


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
        emit eliminaInfo(sensore);
        serra->remove(this->sensore);
        delete this;
    }
}



Sensore * sens_widget::getSens()const{
    return sensore;
}

void sens_widget::modifica(){
    QInputDialog dialog;
    dialog.setCancelButtonText("annulla");
    QString nome = dialog.getText(this, tr("modifica sensore"),tr("cambia il nome:"), QLineEdit::Normal);
    std::string conversion=nome.toStdString();
    if(nome!="" && conversion.size()<=18 && controllaNomi(conversion)==false){//se non do un nome al sensore, il sens widget non viene creato
        emit modify(sensore, nome);
        sensore->setName(conversion);
        bVisualizza->setText(QString::fromStdString(sensore->getName()));

    }
    else if(conversion.size()>18)
        QMessageBox::warning(this, tr("Problema in input"), tr("il nome deve avere una dimensione inferiore a 19 caratteri"));
    else if(controllaNomi(conversion)==true)
        QMessageBox::warning(this, tr("Problema in input"), tr("i sensori devono avere nomi differenti"));

}

bool sens_widget::controllaNomi(std::string str){
    if(serra->controlla(str)==true)
        return true;
    else
        return false;
}




