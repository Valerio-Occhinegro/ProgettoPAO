#include <QHBoxLayout>
#include <QMenuBar>
#include <QPushButton>
#include <QFile>

#include "mainwindow.h"
#include "vista.h"
#include "../model/persistenza.h"


MainWindow::MainWindow(Serra *serra,QWidget *parent):  QMainWindow(parent), serra(serra){
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

    QAction* apri=new QAction(
        QIcon(QPixmap((":/icone/import.svg"))),"Apri");

    QAction* salva = new QAction(QIcon(QPixmap((":/icone/save.svg"))),"Salva");
    connect(salva, &QAction::triggered, this, &MainWindow::salvataggio);
    salva->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_S));

    QAction* save_as = new QAction("Salva con nome");
    save_as->setShortcut(QKeySequence(Qt::CTRL | Qt::SHIFT | Qt::Key_S));


    menu->addAction(save_as);

    menubar->addMenu(menu);

    menubar->addAction(salva);

    menubar->addAction(apri);

    this->setMenuBar(menubar);
}

void MainWindow::salvataggio(){
    Persistenza lercio(serra);
    lercio.scrivi();
}


