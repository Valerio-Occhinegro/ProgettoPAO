#include <cmath>
#include <iostream>

#include "igrometro.h"
#define pi 3.1415

Igrometro::Igrometro(std::string n)  : Sensore(n, 5.0, 27.0, 30.0, 75.0) {
    setMeasure();
    setMin();
    setMax();
}

void Igrometro::printMeasure() const{
    std::cout<<"\n nome del sensore: "<<getName()<<std::endl;
    std::cout << "umidita registrate: "<< std::endl;
    for (unsigned short i = 0; i < 24; ++i)
        std::cout << "Ora " << i<< ": " << getMeasure()[i] << " %"<< std::endl;
    std::cout << "Min: "<<getMin()<< " %"<<" Max: "<<getMax()<< " %"<< std::endl;
}

std::vector<double> Igrometro::calcMeasure(){
    //imposto ore di una giornata
    const unsigned short ore = 24;

    double ampiezza = randomizer(getAmpMin(), getAmpMax()); // Ampiezza della variazione di umidità

    double umidita_media = randomizer(getMeanMin(), getMeanMax()); // umidità media

    // vettore contenente le misurazioni
    std::vector<double> m;

    for (unsigned short i = 0; i < ore; ++i){
        //variabile che aggiungerà ulteriori varizioni pseudoprobabilistiche
        double random = randomizer(-1.0,1.0);

        // Simulo le misurazioni di una giornata tramite una funzione periodica
        m.push_back(umidita_media + ampiezza * (std::sin((i - ore) * pi / ore))+random);
    }
    return m;
}

void Igrometro::accept(SensorVisitorInterface &visitor){
    visitor.visitIgrometro(*this);
}

