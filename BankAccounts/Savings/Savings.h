#ifndef SAVINGS_H
#define SAVINGS_H

#include "../BankAccount.h"

class Savings : public BankAccount
{
    double interestRate = 0.05;

public:
    Savings(const Person *accountHolder, double balance, double interestRate);
    void withdraw(double amount) override;
    void display() const override;

    Type getType() const override
    {
        return Type::Savings;
    }
};

#endif