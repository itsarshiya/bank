#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <string>
#include "../Person/Person.h"

enum class Type
{
    Checking,
    Savings
};

class BankAccount
{
protected:
    std::string accountNumber;
    const Person *accountHolder;
    double balance;

    std::string generateAccountNumber();

public:
    BankAccount(const Person *accountHolder, double balance);
    virtual ~BankAccount();

    virtual void deposit(double amount);
    virtual void withdraw(double amount) = 0;
    virtual void display() const;

    virtual Type getType() const = 0;
    virtual const std::string &getAccountNumber() const;
    virtual double getBalance() const;
};

#endif