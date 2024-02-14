#ifndef PERSISTENZA_H
#define PERSISTENZA_H

#include"serra.h"

class Persistenza{
private:
    Serra* serra;
public:
    Persistenza(Serra *);
    void scrivi(std::string s= std::string());
    void leggi(std::string s= std::string());
};

#endif // PERSISTENZA_H
