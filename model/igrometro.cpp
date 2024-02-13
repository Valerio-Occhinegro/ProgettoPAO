#include <cmath>


#include "igrometro.h"
#define pi 3.1415

Igrometro::Igrometro(std::string n)  : Sensore(n, 5.0, 27.0, 30.0, 75.0) {
    setMeasure();
    setMin();
    setMax();
}

std::string Igrometro::printMeasure() const{
    std::string stampa;
    stampa+="Igrometro";
    stampa.push_back(',');
    stampa.push_back('\n');
    stampa+=getName();
    stampa.push_back(',');
    stampa.push_back('\n');
    for (unsigned short i = 0; i < 24; ++i){
        stampa+=getMeasure()[i];
        stampa.push_back(',');
        stampa.push_back('\n');

    }
    return stampa;
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

