#ifndef IGRO_BLOCCO_H
#define IGRO_BLOCCO_H

#include "sens_blocco.h"

class Igro_blocco : public Sens_blocco{
public:
    Igro_blocco(Serra* sensori, QWidget *parent= nullptr);
    void aggiungi() override;
};

#endif // IGRO_BLOCCO_H
