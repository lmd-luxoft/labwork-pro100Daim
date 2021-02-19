#include "generator.h"

Generator::Generator(int start, int step, int stop, QObject* parent)
    : QObject(parent)
    , currentValue(start)
    , stepValue(step)
    , stopValue(stop)
{
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Generator::timerHandler);
}

void Generator::run(int period)
{
    timer->start(period);
}

void Generator::timerHandler()
{
    emit onNext(currentValue);

    if(currentValue >= stopValue)
    {
        emit onComplete();
    }
    else
    {
        currentValue += stepValue;
    }
}
