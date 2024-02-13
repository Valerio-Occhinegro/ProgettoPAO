#include <fstream>
#include <iostream>

#include "persistenza.h"


Persistenza::Persistenza(Serra* serra): serra(serra) {}

void Persistenza::scrivi() {
    //std::ofstream file("../persistenza.csv", std::ios_base::app);
    std::fstream file;
    std::string nome="../Gestione_serre/persistenza.csv";
    file.open(nome,std::ios_base::out);
    //std::string yolo="giorgione orto e cucina";
    if (file.is_open()) {
        file << serra->print();
        //file << yolo;
        }
    /*std::fstream file;
    std::string nome="../Gestione_serre/persistenza.csv";
    file.open(nome,std::ios_base::out);
    std::string yolo="topare";
    if (file.is_open()) {
        //file << serra->print();
        file << yolo;
        std::cout<<"miaop"<<std::endl;

    }
    else
        std::cout<<"Barba e caffe soosso"<<std::endl;
*/
}
