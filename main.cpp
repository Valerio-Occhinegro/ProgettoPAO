#include "mainwindow.h"

#include <QApplication>
#include "termometro.h"
#include "igrometro.h"
#include "luxometro.h"
#include "serra.h"
#include <iostream>//////////////////////////////


int main(int argc, char *argv[]){
    QApplication a(argc, argv);
     /*
    MainWindow w;
    w.show();
    return a.exec();*/
    Sensore * primo=new Termometro("Togliatti");
    Sensore * secondo=new Igrometro("Giolitti");
    Sensore * terzo=new Luxometro("dux");

    Serra quinto("fattoria Piave");
    quinto.addSensore(primo);
    quinto.addSensore(secondo);
    quinto.addSensore(terzo);
    std::cout<<"stampa pre eliminazione"<<std::endl;
    quinto.print();
    quinto.remove(secondo);
    std::cout<<"stampa post eliminazione"<<std::endl;
    quinto.print();
    std::cout<<"se dio esiste me lo deve dimostrare ora"<<std::endl;
    secondo->printMeasure();




    return 0;
}
