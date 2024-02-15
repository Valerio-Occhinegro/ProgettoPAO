#include <cmath>
#include <iostream>


#include "termometro.h"
#define pi 3.1415

Termometro::Termometro(std::string n, std::vector<double> v) : Sensore(n, 5.0, 10.0, 5.0, 30.0), vect(v){
    setMeasure();
    setMin();
    setMax();
}
std::string Termometro::printMeasure() const{
    std::string stampa;
    stampa+="Termometro";
    stampa.push_back('/');
    stampa+=getName();
    stampa.push_back('/');
    for (unsigned short i = 0; i < 24; ++i){
        stampa+=std::to_string(getMeasure()[i]);
        stampa.push_back('/');
    }
    return stampa;
}


std::vector<double> Termometro::calcMeasure(){
    // vettore contenente le misurazioni
    std::vector<double> m;

    if(vect.size()!=0){
        m=vect;
    }

    else{
    //imposto ore di una giornata
    const unsigned short ore = 24;

    double ampiezza = randomizer(getAmpMin(), getAmpMax()); // Ampiezza della variazione di temperatura

    double temperatura_media = randomizer(getMeanMin(), getMeanMax()); // Temperatura media



    for (unsigned short i = 0; i < ore; ++i){
        //variabile che aggiungerà ulteriori varizioni pseudoprobabilistiche
        double random = randomizer(-1.0,1.0);

        // Simulo le misurazioni di una giornata tramite una funzione periodica
        m.push_back(temperatura_media + ampiezza * (-std::sin((i - ore) * pi / ore))+random);
    }
    }
    vect.clear();
    return m;

}

void Termometro::accept(SensorVisitorInterface & visitor) {
    visitor.visitTermometro(*this);
}

