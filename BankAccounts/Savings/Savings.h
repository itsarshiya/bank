#ifndef SAVINGS_H
#define SAVINGS_H

#include "../BankAccount.h"

class Savings : public BankAccount {
    double interestRate;

public:
    Savings(const std::string& accountNumber, const Person& accountHolder, double balance, double interestRate);
    void withdraw(double amount) override;
    void display() const override;
};

#endif