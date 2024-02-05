#include "sensorinfovisitor.h"
#include "termometro.h"
#include "igrometro.h"
#include "luxometro.h"

QWidget *SensorInfoVisitor::getWidget(){
    return widget;
}

QString SensorInfoVisitor::getMin(){
    return minima;
}

QString SensorInfoVisitor::getMax(){
    return massima;
}

void SensorInfoVisitor::visitTermometro(Termometro & termometro){
    /*QVBoxLayout* layout= new QVBoxLayout();
    layout->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    QLabel* min_label= new QLabel();
    QString min=QString::number(termometro.getMin());
    min.chop(2);
    min_label->setText("Temperatura minima: " + min + " C°"); //cercare come approssimare a 2 dopo la virgola
    layout-> addWidget(min_label);

    QLabel* max_label= new QLabel();
    QString max=QString::number(termometro.getMax());
    max.chop(2);
    max_label->setText("Temperatura massima: " + max + " C°" ); //cercare come approssimare a 2 dopo la virgola
    layout-> addWidget(max_label);

    widget=new QWidget;
    widget->setLayout(layout);
*/
    minima=("Temperatura minima: " + QString::number(termometro.getMin()) + " C°");

    massima=("Temperatura massima: " + QString::number(termometro.getMax()) + " C°" );
}

void SensorInfoVisitor::visitIgrometro(Igrometro &igrometro){
    /*QVBoxLayout* layout= new QVBoxLayout();
    layout->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    QLabel* min_label= new QLabel();
    QString min=QString::number(igrometro.getMin());
    min.chop(3);
    min_label->setText("Umidità minima: " + min + " %"); //cercare come approssimare a 2 dopo la virgola
    layout-> addWidget(min_label);

    QLabel* max_label= new QLabel();
    QString max=QString::number(igrometro.getMax());
    max.chop(3);
    max_label->setText("Umidità massima: " + max + " %"); //cercare come approssimare a 2 dopo la virgola
    layout-> addWidget(max_label);

    widget=new QWidget;
    widget->setLayout(layout);*/
    minima=("Umidità minima: " + QString::number(igrometro.getMin()) + " %");

    massima=("Umidità massima: " + QString::number(igrometro.getMax()) + " %");

}

void SensorInfoVisitor::visitLuxometro(Luxometro &luxometro){
    /*
    QVBoxLayout* layout= new QVBoxLayout();
    layout->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    QLabel* min_label= new QLabel();
    min_label->setText("Illuminamento minimo: " + QString::number(luxometro.getMin()) + " LUX"); //cercare come approssimare a 2 dopo la virgola
    layout-> addWidget(min_label);

    QLabel* max_label= new QLabel();
    max_label->setText("Illuminamento massimo: " + QString::number(luxometro.getMax()) + " LUX"); //cercare come approssimare a 2 dopo la virgola
    layout-> addWidget(max_label);

    widget=new QWidget;
    widget->setLayout(layout);
    */
    minima=("Illuminamento minimo: " + QString::number(luxometro.getMin()) + " LUX");

    massima=("Illuminamento massimo: " + QString::number(luxometro.getMax()) + " LUX");
}
