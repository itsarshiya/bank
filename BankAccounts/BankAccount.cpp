#include "BankAccount.h"
#include <iostream>
#include <random>
#include <sstream>
#include <iomanip>

BankAccount::BankAccount(const Person *accountHolder, double balance)
    : accountHolder(accountHolder), balance(balance)
{
    accountNumber = generateAccountNumber();
}

BankAccount::~BankAccount() {}

void BankAccount::deposit(double amount)
{
    balance += amount;
}

void BankAccount::display() const
{
    std::cout << "account number: " << accountNumber << std::endl;
    std::cout << "account owner: " << accountHolder->getName() << std::endl;
    std::cout << "balance: " << std::fixed << std::setprecision(2) << balance << std::endl;
}

const std::string &BankAccount::getAccountNumber() const
{
    return accountNumber;
}

double BankAccount::getBalance() const
{
    return balance;
}

std::string BankAccount::generateAccountNumber()
{
    const std::string characters = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    std::random_device rd;
    std::mt19937 generator(rd());

    std::uniform_int_distribution<int> distribution(0, characters.length() - 1);

    std::stringstream accountNumber;
    for (int i = 0; i < 12; ++i)
    {
        int randomIndex = distribution(generator);
        accountNumber << characters[randomIndex];
    }

    return accountNumber.str();
}