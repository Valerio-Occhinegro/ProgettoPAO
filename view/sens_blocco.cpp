#include <QPushButton>
#include <QString>
#include <QInputDialog>
#include <QMessageBox>
#include <QScrollArea>
#include <QObject>

#include "sens_blocco.h"

Sens_blocco::Sens_blocco(Serra* serra, QWidget *parent): QWidget(parent), serra(serra){

}



Sensore *Sens_blocco::getSensore(){
    return sensore;
}

bool Sens_blocco::controllaNomi(std::string str){
        if(serra->controlla(str)==true)
            return true;
        else
            return false;
}






