#include "bankaccount.h"

BankAccount::BankAccount(QObject *parent) : QObject(parent)
{
    m_balance = 5000;
}

void BankAccount::deposit(long amount)
{
    m_balance += amount;
}

void BankAccount::withdraw(long amount)
{
    m_balance -= amount;
}

QString BankAccount::holderName()
{
    return holderName_;
}
void BankAccount::setHolderName(QString var)
{
    holderName_ = var;
}

qint64 BankAccount::balance() const
{
    return m_balance;
}
