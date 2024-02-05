#include "sens_info.h"
#include "sensorinfovisitor.h"





Sens_info::Sens_info( QWidget *parent): QWidget(parent){
    layout= new QVBoxLayout(this);
    layout->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    name_label= new QLabel();
    layout-> addWidget(name_label);

    max=new QLabel();
    layout-> addWidget(max);

    min=new QLabel();
    layout-> addWidget(min);

}

void Sens_info::notify(Sensore &sensore){
    name_label->setText(QString::fromStdString(sensore.getName()));
}

void Sens_info::visualizza(Sensore* s){
    name_label->setText(QString::fromStdString(s->getName()));

    SensorInfoVisitor visitor;
    s->accept(visitor);

    //layout->addWidget(visitor.getWidget());
    //modifico il visitor in maniera tale che mi riporti i nomi invece del widget intero
    min->setText(visitor.getMin());
    max->setText(visitor.getMax());
    s->registerObserver(this);


}


