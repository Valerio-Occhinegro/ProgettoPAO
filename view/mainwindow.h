#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "../model/serra.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow{
    Q_OBJECT
private:
    Serra* serra;
public:
    MainWindow(Serra *serra,QWidget *parent = nullptr);
    void addMenu();
    void salvataggio();

};
#endif // MAINWINDOW_H

