#include "mainwindow.h"
#include "vista.h"


#include <QHBoxLayout>
#include <QMenuBar>
#include <QPushButton>


MainWindow::MainWindow(Serra *serra,QWidget *parent): QMainWindow(parent){
    Vista* vista_principale= new Vista(serra);
    setCentralWidget(vista_principale);
}

