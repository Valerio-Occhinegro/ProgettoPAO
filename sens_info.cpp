#include "sens_info.h"
#include "term_blocco.h"

#include <QVBoxLayout>



Sens_info::Sens_info( Sensore *sensore,QWidget *parent): QWidget(parent), InfoSensore(sensore){

}

void Sens_info::notify(Sensore &sensore){
    name_label->setText(QString::fromStdString(sensore.getName()));
}

void Sens_info::visualizza(Sensore* s){

    QVBoxLayout* layout= new QVBoxLayout(this);
    layout->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    name_label= new QLabel();
    name_label->setText(QString::fromStdString(s->getName()));
    layout-> addWidget(name_label);

    SensorInfoVisitor visitor;
    s->accept(visitor);
    layout->addWidget(visitor.getWidget());

    InfoSensore->registerObserver(this);
}

