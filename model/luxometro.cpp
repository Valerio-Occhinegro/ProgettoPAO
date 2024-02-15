#include <cmath>
#include "luxometro.h"
#define pi 3.1415

Luxometro::Luxometro(std::string n, std::vector<double> v) : Sensore(n, 5.0, 20.0, 40.0, 50.0), vect(v){
    setMeasure();
    setMin();
    setMax();
}

std::string Luxometro::printMeasure() const{
    std::string stampa;
    stampa+="Luxometro";
    stampa.push_back('/');
    stampa+=getName();
    stampa.push_back('/');
    for (unsigned short i = 0; i < 24; ++i){
        stampa+=std::to_string(getMeasure()[i]);
        stampa.push_back('/');
    }
    return stampa;
}


std::vector<double> Luxometro::calcMeasure(){
    // vettore contenente le misurazioni
    std::vector<double> m;

    if(vect.size()!=0){
        m=vect;
    }
    else{
    //imposto ore di una giornata
    const unsigned short ore = 24;

    double ampiezza = randomizer(getAmpMin(), getAmpMax()); // Ampiezza della variazione di illuminazione

    double illuminazione_media = randomizer(getMeanMin(), getMeanMax()); // Illuminazione media

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
    }
    vect.clear();
    return m;
}

void Luxometro::accept(SensorVisitorInterface &visitor){
    visitor.visitLuxometro(*this);
}

