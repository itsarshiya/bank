#include "Savings.h"
#include <iostream>

Savings::Savings(const std::string& accountNumber, const Person& accountHolder, double balance, double interestRate)
    : BankAccount(accountNumber, accountHolder, balance), interestRate(interestRate) {}

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