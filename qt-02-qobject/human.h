#ifndef HUMAN_H
#define HUMAN_H

#include <QObject>

class Human : public QObject
{
    Q_OBJECT
public:
    Human(QObject *parent = Q_NULLPTR);

    int age();
    int age() const;
    void setAge(int age);

    char sexSymbol();
    char sexSymbol() const;
    void setSexSymbol(char symb);
private:
    int     m_age;
    char    m_sexSymbol;
};

#endif // HUMAN_H
