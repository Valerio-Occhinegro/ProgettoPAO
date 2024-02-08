#ifndef SENS_WIDGET_H
#define SENS_WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QPushButton>
#include <QWindow>

#include "sensore.h"
#include "serra.h"





class sens_widget : public QWidget{
    Q_OBJECT

private:
    Sensore* sensore;
    Serra* serra;

    QHBoxLayout* layout_sens;
    QPushButton* bVisualizza;
    QPushButton* bModifica;
    QPushButton* bElimina;

public:
    sens_widget(Sensore * , Serra* , QWidget *parent = nullptr);
    Sensore* getSens()const;
    bool controllaNomi(std::string);




    void elimina();////////////////////////////////////////////
    void modifica();// modifica il nome del sens_widget e del sensore
    void visualizza();


signals:
    void mostra(Sensore* );
    void eliminaInfo(Sensore*);
    void modify(Sensore*, QString);

};

#endif // SENS_WIDGET_H
