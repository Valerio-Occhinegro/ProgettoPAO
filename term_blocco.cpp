#include "term_blocco.h"

term_blocco::term_blocco(Serra * serra, QWidget *parent) : Sens_blocco(serra, parent) {
    QString t="Termometri";
    setTitolo(t);
}
