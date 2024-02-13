#include <fstream>
#include <iostream>
#include <sstream>
#include "persistenza.h"
#include "termometro.h"
#include "igrometro.h"
#include "luxometro.h"


Persistenza::Persistenza(Serra* serra): serra(serra) {}

void Persistenza::scrivi() {
    std::fstream file;
    std::string nome="persistenza.csv";
    //std::string nome="../Gestione_serre/persistenza.csv";

    file.open(nome,std::ios_base::out);
    if (file.is_open()) {
        file << serra->print();
        }
    file.close();
}

void Persistenza::leggi(){
    std::cout<<"-1"<<std::endl;
    std::string nome="persistenza.csv";
    std::ifstream file(nome, std::ios_base::app);
    std::string line;

    file.open(nome,std::ios_base::out);
    /*    if(file.is_open()){
        std::cout<<"0"<<std::endl;
            std::cout<<"ciao"<<file.rdbuf();
    }*/
    //std::cout << std::getline(file, line)<<std::endl;
    while(std::getline(file,line)){
        std::cout<<"1"<<std::endl;
        std::string tipo, nome, misure;
        std::vector<double> measure;
        std::istringstream iss(line);

        std::getline(iss, tipo, ','); //get line (iss assegna alla stringa "tipo" le cose scritte prima della virgola)
        std::getline(iss, nome, ',');

        while (getline(iss, misure, ',')) {
            measure.push_back(stod(misure));
        }

        if(tipo=="Termometro"){
            std::cout<<"2"<<std::endl;
            serra->addSensore(new Termometro(nome,measure));//Termometro(nome,measure) cambiare sensore per accettare una stringa alla costruzione
        }
        if(tipo=="Igrometro")
            serra->addSensore(new Igrometro(nome,measure));
        else
            serra->addSensore(new Luxometro(nome,measure));
    }

    file.close();
}
