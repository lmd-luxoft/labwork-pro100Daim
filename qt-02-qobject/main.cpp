#include <QCoreApplication>
#include <QDebug>

#include "human.h"

void printTreeInfo(QObject *parent)
{
    // TODO: print here info about all nodes
    Human* human = qobject_cast<Human*>(parent);

    qDebug() << human->objectName()
             << human->age()
             << human->sexSymbol();

    for(int i = 0; i < parent->children().length(); ++i)
    {
        printTreeInfo(parent->children().at(i));
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Human* parent;
    // TODO: create here required hierarchy
    parent = new Human();
    parent->setObjectName("Lucas Grey");
    parent->setAge(54);
    parent->setSexSymbol('M');

    Human* maryGrey = new Human(parent);
    maryGrey->setObjectName("Mary Grey");
    maryGrey->setAge(28);
    maryGrey->setSexSymbol('F');

    // TODO: dump tree info using standard Qt method
    parent->dumpObjectTree();

    printTreeInfo(parent);

    // TODO: delete here what need only
    delete parent;

    return a.exec();
}
