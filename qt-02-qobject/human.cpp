#include "human.h"

Human::Human(QObject *parent)
    : m_age(0),
      m_sexSymbol('\0')
{
    this->setParent(parent);
}

int Human::age()
{
    return m_age;
}

int Human::age() const
{
    return m_age;
}

void Human::setAge(int age)
{
    m_age = age;
}

char Human::sexSymbol()
{
    return m_sexSymbol;
}

char Human::sexSymbol() const
{
    return m_sexSymbol;
}

void Human::setSexSymbol(char symb)
{
    m_sexSymbol = symb;
}
