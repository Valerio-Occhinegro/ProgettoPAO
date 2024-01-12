#include "sens_widget.h"
#include <QHBoxLayout>
#include <QPushButton>

sens_widget::sens_widget(const Sensore * sensore, QWidget *parent): QWidget(parent), sensore(sensore){
    QHBoxLayout* layout= new QHBoxLayout(this);
    layout->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    name_label= new QLabel();
    layout-> addWidget(name_label);

    QPushButton* modifica = new QPushButton("modifica");
    layout-> addWidget(modifica);
    connect(modifica, &QPushButton::pressed, this, &sens_widget::modifica);

    QPushButton* elimina = new QPushButton("elimina");
    layout-> addWidget(elimina);
     connect(elimina, &QPushButton::pressed, this, &sens_widget::elimina);

}
