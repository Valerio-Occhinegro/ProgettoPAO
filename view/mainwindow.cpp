#include <QHBoxLayout>
#include <QMenuBar>
#include <QPushButton>
#include <QFile>

#include "mainwindow.h"
#include "vista.h"

MainWindow::MainWindow(Serra *serra,QWidget *parent): QMainWindow(parent){
    addMenu();//aggiungo il menu
    Vista* vista_principale= new Vista(serra);
    setCentralWidget(vista_principale);

    //imposto qss
    QFile file("://icone/stylesheet.qss");
    file.open(QFile::ReadOnly);
    QString stylesheet=QLatin1String(file.readAll());
    setStyleSheet(stylesheet);

}

void MainWindow::addMenu(){
    QMenuBar* menubar= new QMenuBar(this);
    QMenu* menu= new QMenu("File",menubar);
    QAction* exit= new QAction("Exit",menu);

    menu->addAction(exit);

    menubar->addMenu(menu);

    this->setMenuBar(menubar);

}


