#include "serra_widget.h"


#include <QString>
#include <QLineEdit>
#include <QMessageBox>

Serra_widget::Serra_widget(Serra* serra, QWidget *parent): QWidget(parent), serra(serra){
    listaNomi=new QStringList;
    completer=new QCompleter;
    populate();

    layout_serra= new QVBoxLayout(this);
    layout_serra->setAlignment(Qt::AlignLeft | Qt::AlignTop);


    name= new QLabel();
    name->setText("Serra");
    layout_serra-> addWidget(name);

    search= new QLineEdit;
    search->setCompleter(completer);
    search->setMaxLength(18);
    connect(search,&QLineEdit::returnPressed,this,&Serra_widget::generate);

    send=new QPushButton;
    send->setText("Ricerca");
    connect(send, &QPushButton::pressed, this, &Serra_widget::generate);

    results=new QVBoxLayout;


    //////////////////////////////////

    /*
    for(std::vector< Sensore *>::const_iterator it = serra->getSensori().begin(); it!= serra->getSensori().end(); ++it){
        sens_widget *elemento=new sens_widget(*it,serra,this);
        bVettore.push_back(elemento);
        elemento->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
        elemento->hide();
        results->addWidget(elemento);

        //connect(elemento, &sens_widget::mostra, this, &Sens_blocco::visualizza)
    }
*/
    /////////////////////////////////

    layout_serra->addWidget(search);
    layout_serra->addWidget(send);
    layout_serra->addLayout(results);


}

void Serra_widget::populate(){
    if(!listaNomi->isEmpty()) listaNomi->clear();

    for(std::vector< Sensore *>::const_iterator it = serra->getSensori().begin(); it!= serra->getSensori().end(); ++it){
        listaNomi->push_back(QString::fromStdString((*it)->getName()));
    }


    delete completer;

    completer=new QCompleter(*listaNomi);

}

void Serra_widget::generate(){

    QString input=search->text();

    sensore=serra->search(input.toStdString());

    if(sensore!=nullptr)
    emit visualizza(sensore);





    /*
    delete results;
    results=new QVBoxLayout;

    for(std::vector< Sensore *>::const_iterator it = serra->getSensori().begin(); it!= serra->getSensori().end(); ++it){
        sens_widget *elemento=new sens_widget(*it,serra,this);
        bVettore.push_back(elemento);
        elemento->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
        elemento->hide();
        results->addWidget(elemento);

        //connect(elemento, &sens_widget::mostra, this, &Sens_blocco::visualizza)
    }

    for(QVector< sens_widget *>::iterator it = bVettore.begin(); it!= bVettore.end(); ++it) {
        auto a=(*it)->getSens();
        if(input == QString::fromStdString(a->getName())){
            (*it)->show();

            //connect(elemento, &sens_widget::mostra, this, &Sens_blocco::visualizza);
            //connect(elemento, &sens_widget::eliminaInfo, this, &Sens_blocco::elimina);
        }

    }

    delete layout_serra;
    layout_serra=new QVBoxLayout;
    layout_serra->addWidget(search);
    layout_serra->addWidget(send);
    layout_serra->addLayout(results);
*/

}
