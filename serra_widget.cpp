#include "serra_widget.h"

#include <QString>

Serra_widget::Serra_widget(QWidget *parent): QWidget{parent}{
    layout_serra= new QVBoxLayout(this);
    layout_serra->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    QString n="Serra";
    name= new QLabel();
    name->setText(n);
    layout_serra-> addWidget(name);
}
