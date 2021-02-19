#include "widget.h"
#include "ui_widget.h"
#include <QMouseEvent>
#include <QString>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("Mouse Position");
    this->setMouseTracking(true);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    if(event)
    {
        int xPos = event->pos().x();
        int yPos = event->pos().y();
        ui->xLineEdit->setText(QString::number(xPos));
        ui->yLineEdit->setText(QString::number(yPos));
    }
}
