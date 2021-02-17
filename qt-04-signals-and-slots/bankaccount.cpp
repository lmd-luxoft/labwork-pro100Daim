#include "bankaccount.h"

BankAccount::BankAccount(Bank *parentBank) : QObject(parentBank)
{
    m_balance = 0;
    connect(this, &BankAccount::balanceChanged, parentBank, &Bank::updateTotalBalance);
}

long BankAccount::balance() const
{
    return m_balance;
}

void BankAccount::setBalance(long newBalance)
{
    m_balance = newBalance;
    // TODO: add here signal emition
    emit balanceChanged(newBalance);
}

void BankAccount::deposit(long amount)
{
    // TODO: implement this function
    if(m_balance < LONG_MAX - amount)
    {
        setBalance(m_balance + amount);
    }
}

void BankAccount::withdraw(long amount)
{
    // TODO: implement this function
    if(m_balance >= amount)
    {
        setBalance(m_balance - amount);
    }
}
