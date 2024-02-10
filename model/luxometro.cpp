#include <cmath>
#include <iostream>

#include "luxometro.h"
#define pi 3.1415

Luxometro::Luxometro(std::string n) : Sensore(n, 5.0, 20.0, 40.0, 50.0){
    setMeasure();
    setMin();
    setMax();
}

void Luxometro::printMeasure() const{
    std::cout<<"\n nome del sensore: "<<getName()<<std::endl;
    std::cout << "illuminazioni registrate: "<< std::endl;
    for (unsigned short i = 0; i < 24; ++i)
        std::cout << "Ora " << i<< ": " << getMeasure()[i] << " LUX"<< std::endl;
    std::cout << "Min: "<<getMin()<< " LUX"<<" Max: "<<getMax()<< " LUX"<< std::endl;
}

std::vector<double> Luxometro::calcMeasure(){
    //imposto ore di una giornata
    const unsigned short ore = 24;

    double ampiezza = randomizer(getAmpMin(), getAmpMax()); // Ampiezza della variazione di illuminazione

    double illuminazione_media = randomizer(getMeanMin(), getMeanMax()); // Illuminazione media

    // vettore contenente le misurazioni
    std::vector<double> m;

    for (unsigned short i = 0; i < ore; ++i){
        //variabile che aggiungerà ulteriori varizioni pseudoprobabilistiche
        double random = randomizer(-1.0,1.0);

        if(i<7 || i>18){
            m.push_back((illuminazione_media + ampiezza * (-std::sin((i - ore) * pi / ore))+random)*100);
        }

        else
        // Simulo le misurazioni di una giornata tramite una funzione periodica
        m.push_back((illuminazione_media + ampiezza * (-std::sin((i - ore) * pi / ore))+random)*1000);
    }
    return m;
}

void Luxometro::accept(SensorVisitorInterface &visitor){
    visitor.visitLuxometro(*this);
}

