#include "mainwindow.h"

#include <QApplication>
#include <termometro.h>
#include <igrometro.h>
#include <luxometro.h>
#include <serra.h>
#include <iostream>//////////////////////////////


int main(int argc, char *argv[]){
    QApplication a(argc, argv);
     /*
    MainWindow w;
    w.show();
    return a.exec();*/
    Termometro uno("Giolitti");
    Igrometro due ("Togliatti");
    Luxometro dux ("Benito");

    Serra quinto("fattoria Piave");
    quinto.addSensore(&uno);
    quinto.addSensore(&due);
    quinto.addSensore(&dux);
    quinto.print();
    quinto.remove(&dux);
    quinto.print();

    quinto.destroy();

    quinto.print();
    std::cout<<"heehe niente distruzione profonda"<<std::endl;

    dux.printMeasure();



    return 0;
}
