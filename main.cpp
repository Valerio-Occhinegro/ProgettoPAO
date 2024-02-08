#include "mainwindow.h"

#include <QApplication>
#include "termometro.h"
#include "igrometro.h"
#include "luxometro.h"
#include "serra.h"
#include <iostream>//////////////////////////////


int main(int argc, char *argv[]){
    QApplication a(argc, argv);

    Sensore * primo=new Termometro("Togliatti");
    Sensore * secondo=new Igrometro("Giolitti");
    Sensore * terzo=new Luxometro("De Gasperi");

    Sensore * quarto=new Termometro("Andreotti");
    Sensore * quinto=new Igrometro("Matteotti");
    Sensore * sesto=new Luxometro("Moro");

    Sensore * settimo=new Termometro("Craxi");
    Sensore * ottavo=new Igrometro("Mattarella");
    Sensore * nono=new Luxometro("Napolitano");

    Sensore * decimo=new Luxometro("Beppo");
    Sensore * undicesimo=new Igrometro("Levi");

    Serra *serra=new Serra("fattoria Piave");

    serra->addSensore(primo);
    serra->addSensore(secondo);
    serra->addSensore(terzo);

    serra->addSensore(quarto);
    serra->addSensore(quinto);
    serra->addSensore(sesto);

    serra->addSensore(settimo);
    serra->addSensore(ottavo);
    serra->addSensore(nono);

    serra->addSensore(decimo);
    serra->addSensore(undicesimo);

    //vista
    MainWindow w(serra);
    w.show();
    return a.exec();



    /*
    std::cout<<"stampa pre eliminazione"<<std::endl;
    quinto.print();
    quinto.remove(secondo);
    std::cout<<"stampa post eliminazione"<<std::endl;
    quinto.print();
    std::cout<<"test test"<<std::endl;
    secondo->printMeasure();
    */



    return 0;
}
