#include "BankAccount.h"
#include <iostream>

BankAccount::BankAccount(const std::string& accountNumber, const Person& accountHolder, double balance)
    : accountNumber(accountNumber), accountHolder(accountHolder), balance(balance) {}

BankAccount::~BankAccount() {}

void BankAccount::deposit(double amount) {
    balance += amount;
}

void BankAccount::display() const {
    std::cout << "account number: " << accountNumber << std::endl;
    // std::cout << "BankAccount Holder: " << accountHolder << std::endl;
    std::cout << "balance: " << balance << std::endl;
}

const std::string& BankAccount::getAccountNumber() const {
    return accountNumber;
}

double BankAccount::getBalance() const {
    return balance;
}