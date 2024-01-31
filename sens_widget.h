#ifndef SENS_WIDGET_H
#define SENS_WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include "sensore.h"
#include "serra.h"
#include "sens_info.h"


class sens_widget : public QWidget{
    Q_OBJECT

private:
    const Sensore* sensore;
    Serra* serra;
    QHBoxLayout* layout_sens;

public:
    sens_widget(const Sensore * , Serra* , QWidget *parent = nullptr);
    void elimina();
    const Sensore* getSens()const;

signals:
    void modifica();// modifica il nome del sens_widget
    //fallita, probabilmente da ristudiare in toto
    void visualizza();// fa visualizzare il sensore in sens_info, creo un oggetto sens_info nella funzione e lo passo di copia a vista
        // vista dovrà avere una funzione set_info

};

#endif // SENS_WIDGET_H
