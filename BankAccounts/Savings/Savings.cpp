#include "Savings.h"
#include <iostream>

Savings::Savings(const Person& accountHolder, double balance, double interestRate)
    : BankAccount(accountHolder, balance), interestRate(interestRate) {}

void Savings::withdraw(double amount) {
    if (amount <= balance) {
        balance -= amount;
    } else {
        std::cout << "insufficient funds for withdrawal" << std::endl;
    }
}

void Savings::display() const {
    std::cout << "account type: savings account" << std::endl;
    BankAccount::display();
}