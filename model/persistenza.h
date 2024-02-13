#ifndef PERSISTENZA_H
#define PERSISTENZA_H

#include"serra.h"

class Persistenza{
private:
    Serra* serra;
public:
    Persistenza(Serra *);
    void scrivi();
    void leggi();
};

#endif // PERSISTENZA_H
