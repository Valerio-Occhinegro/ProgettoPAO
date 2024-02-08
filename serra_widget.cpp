#include "serra_widget.h"


#include <QString>
#include <QLineEdit>
#include <QMessageBox>

Serra_widget::Serra_widget(Serra* serra, QWidget *parent): QWidget(parent), serra(serra){
    layout_serra= new QVBoxLayout(this);
    layout_serra->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    listaNomi=new QStringList;
    completer=new QCompleter;

    ////////////////////////////////
    for(std::vector< Sensore *>::const_iterator it = serra->getSensori().begin(); it!= serra->getSensori().end(); ++it){
        listaNomi->push_back(QString::fromStdString((*it)->getName()));
    }

    completer=new QCompleter(*listaNomi);
    /// //////////////////////////////


    search= new QLineEdit;
    search->setCompleter(completer);
    search->setMaxLength(18);
    connect(search,&QLineEdit::returnPressed,this,&Serra_widget::generate);

    name= new QLabel();
    name->setText("Serra");
    layout_serra-> addWidget(name);

    layout_serra->addWidget(search);

    send=new QPushButton;
    send->setText("Ricerca");
    connect(send, &QPushButton::pressed, this, &Serra_widget::generate);

    layout_serra->addWidget(send);

}

void Serra_widget::populate(){
    /*if(!listaNomi->isEmpty()) listaNomi->clear();

    for(std::vector< Sensore *>::const_iterator it = serra->getSensori().begin(); it!= serra->getSensori().end(); ++it){
        listaNomi->push_back(QString::fromStdString((*it)->getName()));
    }
    */
    delete completer;

    completer=new QCompleter(*listaNomi);

    delete search;
    delete send;
    delete name;


    name= new QLabel();
    name->setText("Serra");
    layout_serra-> addWidget(name);

    search=new QLineEdit;
    search->setCompleter(completer);
    search->setMaxLength(18);
    connect(search,&QLineEdit::returnPressed,this,&Serra_widget::generate);

    layout_serra->addWidget(search);


    send=new QPushButton;
    send->setText("Ricerca");
    connect(send, &QPushButton::pressed, this, &Serra_widget::generate);

    layout_serra->addWidget(send);

}

void Serra_widget::generate(){

    QString input=search->text();

    sensore=serra->search(input.toStdString());

    if(sensore!=nullptr)
        emit visualizza(sensore);
}

void Serra_widget::cancel(Sensore * s){
    bool flag=false;
    for(auto it = listaNomi->begin(); it!= listaNomi->end() && flag==false; ++it){
        if(s->getName()==(*it).toStdString()){
            listaNomi->erase(it);
            flag=true;
        }
    }
    if(flag==true)
    populate();
}

void Serra_widget::modify(Sensore * s, QString n){
    for(auto it = listaNomi->begin(); it!= listaNomi->end(); ++it){
        if(s->getName()==(*it).toStdString()){
            (*it).clear();
            (*it)=n;
        }
    }
    populate();
}

void Serra_widget::add(Sensore * s){
    listaNomi->push_back(QString::fromStdString(s->getName()));
    populate();
}
