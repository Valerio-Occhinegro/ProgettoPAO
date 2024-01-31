#include "sens_widget.h"
#include "sens_info.h"

#include <QPushButton>

sens_widget::sens_widget(const Sensore * sensore,Serra* serra, QWidget *parent, const Sens_info* display): QWidget(parent), sensore(sensore), serra(serra){
    layout_sens= new QHBoxLayout(this);
    layout_sens->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    QPushButton* visualizza = new QPushButton();
    visualizza->setText(QString::fromStdString(sensore->getName()));
    layout_sens-> addWidget(visualizza);
    connect(visualizza, &QPushButton::pressed,/////////
            [&display,this](){
        display->setInfo(this->serra, this->sensore);
            }
);

    QPushButton* modifica = new QPushButton("modifica");
    layout_sens-> addWidget(modifica);
    connect(modifica, &QPushButton::pressed, this, &sens_widget::modifica);

    QPushButton* elimina = new QPushButton("elimina");
    layout_sens-> addWidget(elimina);
    connect(elimina, &QPushButton::pressed, this, &sens_widget::elimina);

}

void sens_widget::elimina(){
    //aggiungo distruzione profonda del sensore
    serra->remove(this->sensore);
    delete this;
}

const Sensore * sens_widget::getSens()const{
    return sensore;
}


