#include <iostream>

#include "Person.h"
#include "../BankAccounts/BankAccount.h"

Person::Person(const std::string &name, const std::string &username, const std::string &password)
    : name(name), username(username), password(password) {}

Person::~Person()
{
    for (BankAccount *account : bankAccounts)
    {
        delete account;
    }
}

void Person::addBankAccount(BankAccount *account)
{
    bankAccounts.push_back(account);
}

const std::vector<BankAccount *> &Person::getBankAccounts() const
{
    return bankAccounts;
}

// void Person::deposit(const std::string& accountNumber, double amount) {
//     for (BankAccount* account : bankAccounts) {
//         if (account->getAccountNumber() == accountNumber) {
//             account->deposit(amount);
//             return;
//         }
//     }
//     std::cout << "Account not found!" << std::endl;
// }

// void Person::withdraw(const std::string& accountNumber, double amount) {
//     for (BankAccount* account : bankAccounts) {
//         if (account->getAccountNumber() == accountNumber) {
//             account->withdraw(amount);
//             return;
//         }
//     }
//     std::cout << "Account not found!" << std::endl;
// }

double Person::getTotalBalance() const {
    double totalBalance = 0.0;

    for (const BankAccount* account : bankAccounts) {
        totalBalance += account->getBalance();
    }

    return totalBalance;
}

void Person::displayAccounts() const
{
    for (BankAccount *account : bankAccounts)
    {
        account->display();
    }
}
