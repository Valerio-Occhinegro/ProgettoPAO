#include "sens_info.h"
#include "sensorinfovisitor.h"








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

    mainLayout->addLayout(layout);

    //////////////////////////////
    series = new QSplineSeries;
    series->setName("Spline");
    series->append(dati);


    chart = new QChart;
    chart->legend()->hide();
    chart->addSeries(series);
    chart->setTitle("Misurazioni");
    chart->createDefaultAxes();



    chartView = new QChartView(chart);
    chartView->hide();

    mainLayout->addWidget(chartView);
    /// ///////////////////////////


}

void Sens_info::notify(Sensore &sensore){
    name_label->setText(QString::fromStdString(sensore.getName()));
}

void Sens_info::visualizza(Sensore* s){
    name_label->setText(QString::fromStdString(s->getName()));

    SensorInfoVisitor visitor;
    s->accept(visitor);

    //layout->addWidget(visitor.getWidget());
    //modifico il visitor in maniera tale che mi riporti i nomi invece del widget intero
    min->setText(visitor.getMin());
    max->setText(visitor.getMax());

    delete series; delete chart; delete chartView;
    dati=visitor.getValori();

    series = new QSplineSeries;
    series->setName("Spline");

    series->append(dati);

    chart = new QChart;
    chart->legend()->hide();
    chart->addSeries(series);
    chart->setTitle("Misurazioni");

    chart->createDefaultAxes();
    QValueAxis *axisX=new QValueAxis;
    axisX->setRange(0,23);
    axisX->setTickCount(23);
    chart->addAxis(axisX,Qt::AlignBottom);



    chartView = new QChartView(chart);

    mainLayout->addWidget(chartView);

    s->registerObserver(this);

}


