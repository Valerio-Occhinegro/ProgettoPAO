#include<algorithm>
#include <iostream>

#include "serra.h"

Serra::Serra(std::string n): name(n){}

Serra::~Serra(){
    destroy();
}

std::vector<Sensore *> &Serra::getSensori() {
    return sensori;
}


Sensore * Serra::search(std::string inserita){
    Sensore * ritorno;

    if(sensori.size()!=0){
        ritorno=nullptr;
        return ritorno;
    }

    bool find=false;
    for(std::vector<Sensore *>::const_iterator it = sensori.begin(); it!= sensori.end() && find==false; ++it){
        if(inserita == (*it)->getName()){
            ritorno=(*it);
            find=true;
        }
        else
            ritorno= nullptr;
    }
    return ritorno;
}

unsigned short Serra::getSize() const{
    return sensori.size();
}

void Serra::insert(Sensore* s){
    sensori.push_back(s);
}

void Serra::print()const{
    std::cout<<"nome della serra: "<< name<<std::endl;
    for(std::vector<Sensore *>::const_iterator it = sensori.begin(); it!= sensori.end(); ++it){
        (*it)->printMeasure();
    }

}

bool Serra::controlla(std::string inserita){
    bool find=false;
    for(std::vector<Sensore *>::const_iterator it = sensori.begin(); it!= sensori.end() && find==false; ++it){
        if(inserita == (*it)->getName()){
            find=true;
        }
        else
            find=false;
    }
    return find;

}

void Serra::remove( Sensore* s){
    std::vector<Sensore*>::iterator it = std::find(sensori.begin(), sensori.end(), s);
    if (it != sensori.end()){
        delete *it;
        sensori.erase(it);
    }

}

void Serra::destroy(){
    for(std::vector<Sensore *>::const_iterator it = sensori.begin(); it!= sensori.end(); ++it){
        delete *it;
        sensori.erase(it);
    }
}


void Serra::addSensore(Sensore *s){
    sensori.push_back(s);
    std::cout<<"inserito"<<std::endl;
}
