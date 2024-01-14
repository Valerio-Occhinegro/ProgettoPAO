#ifndef TERM_BLOCCO_H
#define TERM_BLOCCO_H

#include "sens_blocco.h"
#include "serra.h"

class term_blocco : public Sens_blocco{
public:
    term_blocco(Serra * serra, QWidget *parent= nullptr);
};

#endif // TERM_BLOCCO_H
