#ifndef SERRA_H
#define SERRA_H

#include<vector>
#include<string>
#include "sensore.h"


class Serra{
private:
    std::string name;
    std::vector<Sensore*> sensori;
    unsigned short size;    // vettore che conterrà tutti i sensori presenti in una serra
public:
    Serra(std::string);
    ~Serra();
    std::vector<Sensore*>& getSensori();
    void addSensore(Sensore *);
    Sensore * search(std::string);
    void print() const;

    bool controlla(std::string);

    unsigned short getSize() const;
    void insert(Sensore*);
    void remove(Sensore*);
    void destroy();

};

#endif // SERRA_H
