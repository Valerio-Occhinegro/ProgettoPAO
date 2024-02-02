#include "mainwindow.h"
#include "vista.h"


#include <QHBoxLayout>
#include <QMenuBar>
#include <QPushButton>


MainWindow::MainWindow(Serra *serra,QWidget *parent): QMainWindow(parent){
    addMenu();//aggiungo il menu
    Vista* vista_principale= new Vista(serra);
    setCentralWidget(vista_principale);
}

void MainWindow::addMenu(){
    QMenuBar* menubar= new QMenuBar(this);
    QMenu* menu= new QMenu("File",menubar);
    QAction* exit= new QAction("Exit",menu);

    menu->addAction(exit);

    menubar->addMenu(menu);

    this->setMenuBar(menubar);

}


