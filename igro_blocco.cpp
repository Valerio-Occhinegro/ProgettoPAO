#include "igro_blocco.h"

Igro_blocco::Igro_blocco(Serra* serra, QWidget *parent) : Sens_blocco(serra, parent) {
    QString i="Igrometri";
    setTitolo(i);
}
