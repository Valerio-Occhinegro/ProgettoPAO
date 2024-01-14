#ifndef IDRO_BLOCCO_H
#define IDRO_BLOCCO_H

#include "sens_blocco.h"

class Idro_blocco : public Sens_blocco{
public:
    Idro_blocco(Serra* sensori, QWidget *parent= nullptr);
};

#endif // IDRO_BLOCCO_H
