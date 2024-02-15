#include <fstream>
#include <iostream>
#include <sstream>

#include "persistenza.h"
#include "termometro.h"
#include "igrometro.h"
#include "luxometro.h"


Persistenza::Persistenza(Serra* serra): serra(serra) {}

void Persistenza::scrivi(std::string s) {
    std::fstream file;
    std::string nome;

    if(!s.empty())
        nome=s;

    else
        nome="persistenza.csv";


    file.open(nome,std::ios_base::out);
    if (file.is_open()) {
        file << serra->print();
        }
    file.close();
}

void Persistenza::leggi(std::string s){
    std::ifstream file;
    std::string line;
    std::string nome;

    if(!s.empty())
        nome=s;

    else
        nome="persistenza.csv";

    //if(serra->isEmpty()==false)
    serra->destroy();


    file.open(nome,std::ios_base::in);
    if(file.is_open()){
    while(std::getline(file,line)){
        std::string tipo, nome, misure;
        std::vector<double> measure;
        std::istringstream iss(line);

        std::getline(iss, tipo, ','); //get line (iss assegna alla stringa "tipo" le cose scritte prima della virgola)
        std::getline(iss, nome, ',');

        while (getline(iss, misure, ',')) {
            measure.push_back(stod(misure));
        }

        if(tipo=="Termometro"){
            serra->addSensore(new Termometro(nome,measure));//Termometro(nome,measure) cambiare sensore per accettare una stringa alla costruzione
        }
        if(tipo=="Igrometro")
            serra->addSensore(new Igrometro(nome,measure));
        else if(tipo=="Luxometro")
            serra->addSensore(new Luxometro(nome,measure));
    }
    }

    file.close();
}
