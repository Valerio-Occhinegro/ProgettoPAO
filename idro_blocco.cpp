#include "idro_blocco.h"

Idro_blocco::Idro_blocco(Serra* serra, QWidget *parent) : Sens_blocco(serra, parent) {
    QString i="Idrometri";
    setTitolo(i);
}
