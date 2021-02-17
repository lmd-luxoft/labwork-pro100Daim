#include <QCoreApplication>
#include "generator.h"
#include "receiver.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Generator gen(1, 2, 60);
    Receiver rec1;
    Receiver rec2;

    QObject::connect(&gen, &Generator::onNext, &rec1, &Receiver::onNextHandler);
    QObject::connect(&gen, &Generator::onComplete, &rec1, &Receiver::onCompleteHandler);
    QObject::connect(&gen, &Generator::onError, &rec1, &Receiver::onErrorHandler);

    QObject::connect(&gen, &Generator::onNext, &rec2, &Receiver::onNextHandler);
//    QObject::connect(&gen, &Generator::onComplete, &rec2, &Receiver::onCompleteHandler);
//    QObject::connect(&gen, &Generator::onError, &rec1, &Receiver::onErrorHandler);

    QObject::connect(&gen, &Generator::onComplete, &a, &QCoreApplication::quit);

    gen.run(1000);
    return a.exec();
}
