#include "sens_info.h"
#include "sensorinfovisitor.h"

#include <QPushButton>


Sens_info::Sens_info( QWidget *parent): QWidget(parent){
    mainLayout=new QHBoxLayout(this);

    layout= new QVBoxLayout();
    layout->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    name_label= new QLabel();
    layout-> addWidget(name_label);

    max=new QLabel();
    layout-> addWidget(max);

    min=new QLabel();
    layout-> addWidget(min);

    bRicalcola = new QPushButton();
    bRicalcola->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    bRicalcola->setText("Ricalcola");
    bRicalcola->hide();
    connect(bRicalcola, &QPushButton::pressed, this, &Sens_info::ricalcola);

    /*
    bModifica=new QPushButton();
    bModifica->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    bModifica->setText("Modifica");
    bModifica->hide();
    connect(bModifica, &QPushButton::pressed, this, &Sens_info::ricalcola);
    */
    /*
    bElimina=new QPushButton();
    bElimina->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    bElimina->setText("Elimina");
    bElimina->hide();
    connect(bElimina, &QPushButton::pressed, this, &Sens_info::ricalcola);
    */

    layout->addWidget(bRicalcola);
    //layout->addWidget(bModifica);
    //layout->addWidget(bElimina);


    mainLayout->addLayout(layout);

    ///////////////GRAFICO///////////////
    series = new QLineSeries;
    series->setName("Line");
    series->append(dati);


    chart = new QChart;
    chart->legend()->hide();
    chart->addSeries(series);
    chart->setTitle("Misurazioni");
    chart->createDefaultAxes();




    chartView = new QChartView(chart);
    chartView->setRenderHints(QPainter::Antialiasing |QPainter::SmoothPixmapTransform);
    chartView->hide();

    mainLayout->addWidget(chartView);
    /// ///////////////////////////


}

void Sens_info::notify(Sensore &sensore){
    name_label->setText(QString::fromStdString(sensore.getName()));
}

void Sens_info::visualizza(Sensore* s){

    name_label->show();
    min->show();
    max->show();

    sensore=s;
    name_label->setText(QString::fromStdString(s->getName()));

    bRicalcola->show();
    //bModifica->show();
    //bElimina->show();

    SensorInfoVisitor visitor;
    s->accept(visitor);


    //modifico il visitor in maniera tale che mi riporti i nomi invece del widget intero
    min->setText(visitor.getMin());
    max->setText(visitor.getMax());

    delete series; delete chart; delete chartView;
    dati=visitor.getValori();

    series = new QLineSeries;
    series->setName("Line");

    series->append(dati);

    chart = new QChart;
    chart->legend()->hide();
    chart->addSeries(series);
    chart->setTitle("Misurazioni");

    chart->createDefaultAxes();
    QValueAxis *axisX=new QValueAxis;
    axisX->setRange(0,23);
    axisX->setTickCount(24);
    chart->addAxis(axisX,Qt::AlignBottom);



    chartView = new QChartView(chart);
    chartView->setMinimumHeight(200);
    chartView->setMinimumWidth(500);
    chartView->setRenderHints(QPainter::Antialiasing |QPainter::SmoothPixmapTransform);

    mainLayout->addWidget(chartView);

    s->registerObserver(this);

}

void Sens_info::ricalcola(){

    sensore->sensRicalcola();

    name_label->setText(QString::fromStdString(sensore->getName()));

    bRicalcola->show();

    SensorInfoVisitor visitor;
    sensore->accept(visitor);

    min->setText(visitor.getMin());
    max->setText(visitor.getMax());

    delete series; delete chart; delete chartView;
    dati=visitor.getValori();

    series = new QLineSeries;
    series->setName("Line");

    series->append(dati);

    chart = new QChart;
    chart->legend()->hide();
    chart->addSeries(series);
    chart->setTitle("Misurazioni");

    chart->createDefaultAxes();
    QValueAxis *axisX=new QValueAxis;
    axisX->setRange(0,23);
    axisX->setTickCount(24);
    chart->addAxis(axisX,Qt::AlignBottom);

    chartView = new QChartView(chart);
    chartView->setMinimumHeight(200);
    chartView->setMinimumWidth(500);
    chartView->setRenderHints(QPainter::Antialiasing |QPainter::SmoothPixmapTransform);


    mainLayout->addWidget(chartView);

    sensore->registerObserver(this);

}

void Sens_info::cancel(Sensore *s){
    if(sensore==s){
    chartView->hide();
    name_label->hide();
    min->hide();
    max->hide();
    bRicalcola->hide();
    }
}


