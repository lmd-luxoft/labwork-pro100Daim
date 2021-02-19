#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <QObject>
#include <QString>

class BankAccount : public QObject
{
    Q_OBJECT
    // TODO: declare QString holderName property that's represents account holder name
    //       this property must have getter and setter
    Q_PROPERTY(
        QString holderName READ holderName
                           WRITE setHolderName
    );

    // TODO: declare long balance property
    //       this property should be read-only and associated with variable m_balance

    Q_PROPERTY(
        qint64 balance MEMBER m_balance READ balance CONSTANT
    );

public:
    explicit BankAccount(QObject *parent = 0);

    void deposit(long amount);
    void withdraw(long amount);

    // TODO: declare and implement holderName getter/setter
    QString holderName();
    void setHolderName(QString var);


    // TODO: decalre and implement balance getter
    qint64 balance() const;
private:
    // TODO: declare holderName
    QString holderName_;
    long m_balance;
};

#endif // BANKACCOUNT_H
