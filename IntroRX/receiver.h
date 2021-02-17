#ifndef RECEIVER_H
#define RECEIVER_H

#include <QObject>

class Receiver : public QObject
{
    Q_OBJECT
public:
    explicit Receiver(QObject *parent = nullptr);

signals:

public slots:
    void onNextHandler(int value);
    void onErrorHandler(int value);
    void onCompleteHandler();
};

#endif // RECEIVER_H
