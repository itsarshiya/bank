#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <string>
#include "../Person/Person.h"

class BankAccount {
protected:
    std::string accountNumber;
    Person accountHolder;
    double balance;

public:
    BankAccount(const std::string& accountNumber, const Person& accountHolder, double balance);
    virtual ~BankAccount();

    virtual void deposit(double amount);
    virtual void withdraw(double amount) = 0;
    virtual void display() const;

    const std::string& getAccountNumber() const;
    double getBalance() const;
};

#endif