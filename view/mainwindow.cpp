#include <QHBoxLayout>
#include <QMenuBar>
#include <QPushButton>
#include <QFile>
#include <QFileDialog>

#include "mainwindow.h"
//#include "vista.h"
#include "../model/persistenza.h"


MainWindow::MainWindow(Serra *serra,QWidget *parent):  QMainWindow(parent), serra(serra){
    addMenu();//aggiungo il menu
    //Vista* vista_principale= new Vista(serra);
    vista_principale= new Vista(serra);
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
    connect(apri, &QAction::triggered, this, &MainWindow::importa);

    QAction* salva = new QAction(QIcon(QPixmap((":/icone/save.svg"))),"Salva");
    connect(salva, &QAction::triggered, this, &MainWindow::salvataggio);
    salva->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_S));

    QAction* esporta = new QAction("Esporta");
    connect(esporta, &QAction::triggered, this, &MainWindow::esporta);
    esporta->setShortcut(QKeySequence(Qt::CTRL | Qt::SHIFT | Qt::Key_S));


    menu->addAction(esporta);

    menubar->addMenu(menu);

    menubar->addAction(salva);

    menubar->addAction(apri);

    this->setMenuBar(menubar);
}

void MainWindow::salvataggio(){
    Persistenza salva(serra);
    salva.scrivi();
}

void MainWindow::esporta(){
    QString fileName;
    fileName = QFileDialog::getSaveFileName(this,tr("Esporta"), "serra", tr("Text files (*.csv)"));

    std::string nome=fileName.toStdString();

    Persistenza exp(serra);
    exp.scrivi(nome);
}

void MainWindow::importa(){
    QString fileName;
    fileName = QFileDialog::getOpenFileName(this,tr("importa"), "", tr("Text files (*.csv)"));

    std::string nome=fileName.toStdString();

    Persistenza imp(serra);
    imp.leggi(nome);

    refresh();
}

void MainWindow::refresh(){
    delete vista_principale;
    vista_principale=new Vista(serra);
    setCentralWidget(vista_principale);
}


