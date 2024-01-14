#include "sens_widget.h"

#include <QPushButton>

sens_widget::sens_widget(const Sensore * sensore, QWidget *parent): QWidget(parent), sensore(sensore){
    layout_sens= new QHBoxLayout(this);
    layout_sens->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    //successivamente sarà un bottone con il nome del sensore che una volta premuto mostrerà il grafico e le info
    QLabel*name_label= new QLabel();
    name_label->setText(QString::fromStdString(sensore->getName()));
    layout_sens-> addWidget(name_label);

    QPushButton* modifica = new QPushButton("modifica");
    layout_sens-> addWidget(modifica);
    connect(modifica, &QPushButton::pressed, this, &sens_widget::modifica);

    QPushButton* elimina = new QPushButton("elimina");
    layout_sens-> addWidget(elimina);
     connect(elimina, &QPushButton::pressed, this, &sens_widget::elimina);

}
