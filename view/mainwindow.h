#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "../model/serra.h"
#include "vista.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow{
    Q_OBJECT
private:
    Serra* serra;
    Vista* vista_principale;
public:
    MainWindow(Serra *serra,QWidget *parent = nullptr);
    void addMenu();
    void salvataggio();
    void esporta();
    void importa();
    void refresh();

};
#endif // MAINWINDOW_H

