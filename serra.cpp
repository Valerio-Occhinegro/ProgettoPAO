#include "serra.h"
#include<algorithm>
#include <iostream>
Serra::Serra(std::string n): name(n){}

const std::vector<const Sensore *> &Serra::getSensori() const{
    return sensori;
}

void Serra::addSensore(const Sensore *s){
    sensori.push_back(s);
    std::cout<<"inserito"<<std::endl;
}

unsigned short Serra::getSize() const{
    return sensori.size();
}

Serra& Serra::insert(const Sensore* s){
    sensori.push_back(s);

    return *this;

}

void Serra::print()const{
    std::cout<<"nome della serra: "<< name<<std::endl;
    for(std::vector<const Sensore *>::const_iterator it = sensori.begin(); it!= sensori.end(); ++it){
        const Sensore* const & s = *it;
        s->printMeasure();
    }


}

Serra& Serra::remove(const Sensore* s){
    std::vector<const Sensore*>::iterator it = std::find(sensori.begin(), sensori.end(), s);
    if (it != sensori.end())
        sensori.erase(it);

    return *this;

}

Serra& Serra::destroy(){
    sensori.clear();
    return *this;
}


