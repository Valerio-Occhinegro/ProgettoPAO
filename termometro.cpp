#include "termometro.h"
#include <cmath>
#include <iostream>
#define pi 3.1415

Termometro::Termometro(std::string n) : Sensore(n, 5.0, 10.0, 5.0, 30.0){
    setMeasure();
    setMin();
    setMax();
}
void Termometro::printMeasure() const{
    std::cout<<"\n nome del sensore: "<<getName()<<std::endl;
    std::cout << "tempertaure registrate: "<< std::endl;
    for (unsigned short i = 0; i < 24; ++i)
        std::cout << "Ora " << i<< ": " << getMeasure()[i] << " C"<< std::endl;

    std::cout << "Min: "<<getMin()<< " C"<<" Max: "<<getMax()<< " C"<< std::endl;
}

std::vector<double> Termometro::calcMeasure(){
    //imposto ore di una giornata
    const unsigned short ore = 24;

    double ampiezza = randomizer(getAmpMin(), getAmpMax()); // Ampiezza della variazione di temperatura

    double temperatura_media = randomizer(getMeanMin(), getMeanMax()); // Temperatura media

    // vettore contenente le misurazioni
    std::vector<double> m;

    for (unsigned short i = 0; i < ore; ++i){
        //variabile che aggiungerà ulteriori varizioni pseudoprobabilistiche
        double random = randomizer(-1.0,1.0);

        // Simulo le misurazioni di una giornata tramite una funzione periodica
        m.push_back(temperatura_media + ampiezza * (-std::sin((i - ore) * pi / ore))+random);
    }
    return m;

}

