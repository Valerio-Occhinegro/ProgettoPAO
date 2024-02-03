#include "sens_info.h"

#include <QHBoxLayout>



Sens_info::Sens_info( Sensore *sensore,QWidget *parent): QWidget(parent), InfoSensore(sensore){

    QHBoxLayout* layout= new QHBoxLayout(this);
    layout->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    SensorInfoVisitor visitor;
    sensore->accept(visitor);
    layout->addWidget(visitor.getWidget());
}

