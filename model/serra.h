#ifndef SERRA_H
#define SERRA_H

#include<vector>
#include<string>
#include "sensore.h"


class Serra{
private:
    std::string name;
    std::vector<Sensore*> sensori;
    unsigned short size;
public:
    Serra(std::string);
    ~Serra();
    std::vector<Sensore*>& getSensori();
    Sensore * search(std::string);
    std::string print() const;

    bool controlla(std::string);

    unsigned short getSize() const;
    void insert(Sensore*);
    void remove(Sensore*);
    void destroy();

    //per verificare inserimento da terminale
    void addSensore(Sensore *);

};

#endif // SERRA_H
