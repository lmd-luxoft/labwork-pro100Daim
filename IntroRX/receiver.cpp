#include "receiver.h"
#include <QDebug>

Receiver::Receiver(QObject *parent) : QObject(parent)
{

}

void Receiver::onNextHandler(int value)
{
    qDebug() << "onNextHandler " << value;
}

void Receiver::onErrorHandler(int value)
{
    qDebug() << "onErrorHandler " << value;
}

void Receiver::onCompleteHandler()
{
    qDebug() << "onCompleteHandler ";
}
