#include "sens_info.h"

#include <QVBoxLayout>



Sens_info::Sens_info( Sensore *sensore,QWidget *parent): QWidget(parent), InfoSensore(sensore){

    QVBoxLayout* layout= new QVBoxLayout(this);
    layout->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    name_label= new QLabel();
    name_label->setText(QString::fromStdString(sensore->getName()));
    layout-> addWidget(name_label);

    SensorInfoVisitor visitor;
    sensore->accept(visitor);
    layout->addWidget(visitor.getWidget());

    sensore->registerObserver(this);
}

void Sens_info::notify(Sensore &sensore){
    name_label->setText(QString::fromStdString(sensore.getName()));
}

