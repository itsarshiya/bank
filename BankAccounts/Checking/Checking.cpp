#include "Checking.h"
#include <iostream>

Checking::Checking(const Person* accountHolder, double balance, double overdraftLimit)
    : BankAccount(accountHolder, balance), overdraftLimit(overdraftLimit) {}

void Checking::withdraw(double amount) {
    if (amount <= balance + overdraftLimit) {
        balance -= amount;
    } else {
        std::cout << "insufficient funds for withdrawal" << std::endl;
    }
}

void Checking::display() const {
    std::cout << "account type: checking account" << std::endl;
    BankAccount::display();
}