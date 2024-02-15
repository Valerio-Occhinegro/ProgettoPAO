#include <QHBoxLayout>
#include <QMenuBar>
#include <QPushButton>
#include <QFile>
#include <QFileDialog>

#include "mainwindow.h"

#include "../model/persistenza.h"


MainWindow::MainWindow(Serra *serra,QWidget *parent):  QMainWindow(parent), serra(serra){
    addMenu();//aggiungo il menu

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

    QAction* apri=new QAction(QIcon(QPixmap((":/icone/import_1.svg"))),"Apri");
    connect(apri, &QAction::triggered, this, &MainWindow::importa);
    apri->setShortcut(QKeySequence(Qt::CTRL | Qt::SHIFT | Qt::Key_O));

    QAction* salva = new QAction(QIcon(QPixmap((":/icone/save.svg"))),"Salva");
    connect(salva, &QAction::triggered, this, &MainWindow::salvataggio);
    salva->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_S));

    QAction* esporta = new QAction(QIcon(QPixmap((":/icone/export_1.svg"))),"Esporta");
    connect(esporta, &QAction::triggered, this, &MainWindow::esporta);
    esporta->setShortcut(QKeySequence(Qt::CTRL | Qt::SHIFT | Qt::Key_S));

    menu->addAction(apri);

    menu->addAction(esporta);

    menubar->addMenu(menu);

    menubar->addAction(salva);

    menubar->addAction(apri);

    menubar->addAction(esporta);

    this->setMenuBar(menubar);
}

void MainWindow::salvataggio(){
    Persistenza salva(serra);
    salva.scrivi();
}

void MainWindow::esporta(){
    QString fileName;
    fileName = QFileDialog::getSaveFileName(this,tr("Esporta"), "serra", tr("Text files (*.csv)"));

    if(fileName!=""){
    std::string nome=fileName.toStdString();

    Persistenza exp(serra);
    exp.scrivi(nome);
    }
}

void MainWindow::importa(){
    QString fileName;
    fileName = QFileDialog::getOpenFileName(this,tr("importa"), "", tr("Text files (*.csv)"));

    if(fileName!=""){
    std::string nome=fileName.toStdString();

    Persistenza imp(serra);
    imp.leggi(nome);

    refresh();
    }
}

void MainWindow::refresh(){
    delete vista_principale;
    vista_principale=new Vista(serra);
    setCentralWidget(vista_principale);
}


