#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <vector>

class BankAccount;

class Person
{
private:
    std::string name;
    std::string username;
    std::string password;
    std::vector<BankAccount*> bankAccounts;

public:
    Person(const std::string &name, const std::string &username, const std::string &password);
    ~Person();

    void addBankAccount(BankAccount *account);
    const std::vector<BankAccount*>& getBankAccounts() const;

    void deposit(const std::string &accountNumber, double amount);
    void withdraw(const std::string &accountNumber, double amount);
    void displayAccounts() const;

    double getTotalBalance() const;


    const std::string &getUsername() const
    {
        return username;
    }

    const std::string &getPassword() const
    {
        return password;
    }

    const std::string &getName() const
    {
        return name;
    }
};

#endif