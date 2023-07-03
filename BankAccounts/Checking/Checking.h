#ifndef CHECKING_H
#define CHECKING_H

#include "../BankAccount.h"

class Checking : public BankAccount {
    double overdraftLimit;

public:
    Checking(const Person* accountHolder, double balance, double overdraftLimit);
    void withdraw(double amount) override;
    void display() const override;

    Type getType() const override {
        return Type::Checking;
    }
};

#endif