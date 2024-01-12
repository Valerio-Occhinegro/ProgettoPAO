#ifndef TERM_BLOCCO_H
#define TERM_BLOCCO_H

#include "sens_blocco.h"

class term_blocco : public Sens_blocco{
public:
    term_blocco(std::vector<const Sensore*>& sensori, QWidget *parent);
};

#endif // TERM_BLOCCO_H
