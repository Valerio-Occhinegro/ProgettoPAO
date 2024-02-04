#include "sensorinfovisitor.h"
#include "termometro.h"
#include "igrometro.h"
#include "luxometro.h"

QWidget *SensorInfoVisitor::getWidget(){
    return widget;
}

void SensorInfoVisitor::visitTermometro(Termometro & termometro){
    QVBoxLayout* layout= new QVBoxLayout();
    layout->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    QLabel* min_label= new QLabel();
    min_label->setText("Temperatura minima: " + QString::number(termometro.getMin())); //cercare come approssimare a 2 dopo la virgola
    layout-> addWidget(min_label);

    QLabel* max_label= new QLabel();
    max_label->setText("Temperatura massima: " + QString::number(termometro.getMax())); //cercare come approssimare a 2 dopo la virgola
    layout-> addWidget(max_label);

    widget=new QWidget;
    widget->setLayout(layout);
}

void SensorInfoVisitor::visitIgrometro(Igrometro &igrometro){
    QVBoxLayout* layout= new QVBoxLayout();
    layout->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    QLabel* min_label= new QLabel();
    min_label->setText("Umidità minima: " + QString::number(igrometro.getMin())); //cercare come approssimare a 2 dopo la virgola
    layout-> addWidget(min_label);

    QLabel* max_label= new QLabel();
    max_label->setText("Umidità massima: " + QString::number(igrometro.getMax())); //cercare come approssimare a 2 dopo la virgola
    layout-> addWidget(max_label);

    widget=new QWidget;
    widget->setLayout(layout);

}

void SensorInfoVisitor::visitLuxometro(Luxometro &luxometro){
    QVBoxLayout* layout= new QVBoxLayout();
    layout->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    QLabel* min_label= new QLabel();
    min_label->setText("Illuminamento massimo: " + QString::number(luxometro.getMin())); //cercare come approssimare a 2 dopo la virgola
    layout-> addWidget(min_label);

    QLabel* max_label= new QLabel();
    max_label->setText("Illuminamento minimo: " + QString::number(luxometro.getMax())); //cercare come approssimare a 2 dopo la virgola
    layout-> addWidget(max_label);

    widget=new QWidget;
    widget->setLayout(layout);
}
