#ifndef PERSISTENZA_H
#define PERSISTENZA_H

#include"serra.h"

class Persistenza{
private:
    Serra* serra;
public:
    Persistenza(Serra *);
    void scrivi();
};

#endif // PERSISTENZA_H
