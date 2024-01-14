#ifndef SERRA_WIDGET_H
#define SERRA_WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>

class Serra_widget : public QWidget{
    Q_OBJECT
private:
    QLabel* name;
    QVBoxLayout*layout_serra;
public:
    Serra_widget(QWidget *parent = nullptr);

signals:
};

#endif // SERRA_WIDGET_H
