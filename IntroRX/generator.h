#ifndef GENERATOR_H
#define GENERATOR_H

#include <QObject>
#include <QTimer>

class Generator : public QObject
{
    Q_OBJECT
public:
    Generator(int start, int stop, int step, QObject* parent = nullptr);
    void run(int period);
signals:
    void onNext(int value);
    void onError(int error_code);
    void onComplete();
private slots:
    void timerHandler();
private:
    int currentValue;
    int stepValue;
    int stopValue;
    QTimer *timer;
};

#endif // GENERATOR_H
