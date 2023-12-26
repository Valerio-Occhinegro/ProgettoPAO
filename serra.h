#ifndef SERRA_H
#define SERRA_H

#include<vector>
#include<string>
#include<sensore.h>
#include<termometro.h>

class Serra{
private:
    std::string name;
    std::vector<const Sensore*> sensori;
    unsigned short size;    // vettore che conterrà tutti i sensori presenti in una serra
public:
    Serra(std::string);
    const std::vector<const Sensore*>& getSensori()const;
    void addSensore(const Sensore *);
    void print() const;


    unsigned short getSize() const;
    Serra& insert(const Sensore*);
    Serra& remove(const Sensore*);
    Serra& destroy();

};

#endif // SERRA_H
