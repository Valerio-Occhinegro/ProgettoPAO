#include <QPointF>

#include "sensorinfovisitor.h"
#include "termometro.h"
#include "igrometro.h"
#include "luxometro.h"


QList<QPointF> SensorInfoVisitor::getValori(){
    return valori;
}

QString SensorInfoVisitor::getMin(){
    return minima;
}

QString SensorInfoVisitor::getMax(){
    return massima;
}

QPixmap SensorInfoVisitor::getPix(){
    return pix;
}

void SensorInfoVisitor::visitTermometro(Termometro & termometro){
    pix.load("://icone/termometro.svg");


    minima=("Temperatura minima: " + QString::number(termometro.getMin()) + " C°");

    massima=("Temperatura massima: " + QString::number(termometro.getMax()) + " C°" );


    std::vector<double> measure= termometro.getMeasure();
    int i=0;
    for (double d : measure) {
        QPointF f(i,d);
        valori.push_back(f);
        i++;
    }

}

void SensorInfoVisitor::visitIgrometro(Igrometro &igrometro){
    pix.load("://icone/mist.svg");

    minima=("Umidità minima: " + QString::number(igrometro.getMin()) + " %");

    massima=("Umidità massima: " + QString::number(igrometro.getMax()) + " %");

    std::vector<double> measure= igrometro.getMeasure();
    int i=0;
    for (double d : measure) {
        QPointF f(i,d);
        valori.push_back(f);
        i++;
    }

}

void SensorInfoVisitor::visitLuxometro(Luxometro &luxometro){
    pix.load("://icone/sun.svg");

    minima=("Illuminamento minimo: " + QString::number(luxometro.getMin()) + " LUX");

    massima=("Illuminamento massimo: " + QString::number(luxometro.getMax()) + " LUX");

    std::vector<double> measure= luxometro.getMeasure();
    int i=0;
    for (double d : measure) {
        QPointF f(i,d);
        valori.push_back(f);
        i++;
    }

}
