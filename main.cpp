#include <QApplication>
#include <iostream>//////////////////////////////
#include <string>

#include "./view/mainwindow.h"
#include "./model/termometro.h"
#include "./model/igrometro.h"
#include "./model/luxometro.h"
#include "./model/persistenza.h"
#include "./model/serra.h"



int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/icone/progetto_serra.svg"));

    Serra *serra=new Serra("serra");

    Persistenza pers(serra);
    pers.leggi();

    /*
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
*/


    //vista
    MainWindow w(serra);
    w.show();
    return a.exec();

    return 0;
}
