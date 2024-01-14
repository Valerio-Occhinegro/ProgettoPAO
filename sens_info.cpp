#include "sens_info.h"
#include <QVBoxLayout>


Sens_info::Sens_info(const Sensore *sensore,QWidget *parent): QWidget(parent), sensore(sensore){
    QVBoxLayout* layout= new QVBoxLayout(this);
    layout->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    name_label= new QLabel();
    layout-> addWidget(name_label);

    min_label= new QLabel();
    layout-> addWidget(min_label);

    max_label= new QLabel();
    layout-> addWidget(max_label);

    show();
}

void Sens_info::show(){
    name_label->setText(QString::fromStdString(sensore->getName()));

    min_label->setText("Min: " + QString::number(sensore->getMin())); //cercare come approssimare a 2 dopo la virgola

    max_label->setText("Max: " + QString::number(sensore->getMax())); //cercare come approssimare a 2 dopo la virgola

}
