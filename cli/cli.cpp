#include <iostream>
#include <string>
#include <list>
#include "../Person/Person.h"
#include "../BankAccounts/BankAccount.h"
#include "../BankAccounts/Checking/Checking.h"
#include "../BankAccounts/Savings/Savings.h"
#include "ie/Export.h"
#include "ie/Import.h"
#include "cli.h"

void CLI::displayAccountInfo(const Person *person)
{
    std::cout << "═════════════════════════════════════════════" << std::endl;
    std::cout << "account info for " << person->getName() << std::endl;
    std::cout << "═════════════════════════════════════════════" << std::endl;
    std::cout << "total balance: " << person->getTotalBalance() << std::endl;
    std::cout << "═════════════════════════════════════════════" << std::endl;
    for (const auto &account : person->getBankAccounts())
    {
        account->display();
    }
    std::cout << "═════════════════════════════════════════════" << std::endl;
}

void CLI::printBankLogo()
{
    std::string logo = R"(
╔═══════════════════════════════════════════╗
║            welcome to moneybank           ║
╚═══════════════════════════════════════════╝
)";
    std::cout << logo << std::endl;
}

void CLI::createAccount()
{
    std::string name, username, password;
    std::cout << "enter your name: ";
    std::cin >> name;
    std::cout << "enter your username: ";
    std::cin >> username;
    std::cout << "enter your password: ";
    std::cin >> password;

    Person *person = new Person(name, username, password);
    BankAccount *account = new Checking(person, 0.0, 0.05);
    person->addBankAccount(account);
    persons.push_back(person);
    std::cout << "═════════════════════════════════════════════" << std::endl;
    std::cout << "account created successfully!" << std::endl;
    std::cout << "═════════════════════════════════════════════" << std::endl;
}

void CLI::deposit(const Person *person)
{  
    double amount;
    std::cout << "enter the amount to deposit: ";
    std::cin >> amount;
        
    for (BankAccount* account : person->getBankAccounts()) {
        if (account->getType() == Type::Checking) {
            account->deposit(amount);
            return;
        }
    }
    std::cout << "deposit failed" << std::endl;
}

void CLI::withdraw(const Person *person)
{  
    double amount;
    std::cout << "enter the amount to withdraw: ";
    std::cin >> amount;
        
    for (BankAccount* account : person->getBankAccounts()) {
        if (account->getType() == Type::Checking) {
            account->withdraw(amount);
            return;
        }
    }
    std::cout << "withdraw failed" << std::endl;
}

std::string CLI::login()
{
    std::string username, password;
    std::cout << "enter your username: ";
    std::cin >> username;
    std::cout << "enter your password: ";
    std::cin >> password;

    auto current = std::find_if(persons.begin(), persons.end(), [&](const Person *p)
                           { return p->getUsername() == username && p->getPassword() == password; });

    if (current != persons.end())
    {
        const Person *person = *current;
        displayAccountInfo(person);
        return username;
    }
    else
    {
        std::cout << "invalid username or password. please try again." << std::endl;
        return "";
    }
}

void CLI::run(const std::string &filePath)
{
    importData(persons, filePath);

    printBankLogo();

    std::string option;
    std::string loggedInUsername;
    while (true)
    {
        std::cout << "please select an option:" << std::endl;
        std::cout << "1. create an account" << std::endl;
        std::cout << "2. log in" << std::endl;
        std::cout << "0. exit" << std::endl;
        std::cout << "option: ";
        std::cin >> option;

        if (option == "1")
        {
            createAccount();
        }
        else if (option == "2")
        {
            loggedInUsername = login();
            if (!loggedInUsername.empty())
                break;
        }
        else if (option == "0")
        {
            exportData(persons, filePath);
            std::string logo = R"(
╔═══════════════════════════════════════════╗
║                 goodbye!                  ║
╚═══════════════════════════════════════════╝
)";
            std::cout << logo << std::endl;
            return;
        }
        else
        {
            std::cout << "invalid option. please try again." << std::endl;
        }
    }

    const Person *person = *std::find_if(persons.begin(), persons.end(), [&](const Person *p)
                                         { return p->getUsername() == loggedInUsername; });

    std::string accountOption;
    while (true)
    {
        std::cout << "please select an option:" << std::endl;
        std::cout << "1. check balance" << std::endl;
        std::cout << "2. deposit" << std::endl;
        std::cout << "3. withdraw" << std::endl;
        std::cout << "4. add savings account" << std::endl;

        if (person->getUsername() == "admin")
        {
            std::cout << "5. import data" << std::endl;
            std::cout << "6. export data" << std::endl;
        }
        std::cout << "0. log out" << std::endl;
        std::cout << "Option: ";
        std::cin >> accountOption;

        if (accountOption == "1")
        {
            displayAccountInfo(person);
        }
        else if (accountOption == "2")
        {
            deposit(person);
        }
        else if (accountOption == "3")
        {
            withdraw(person);
        }
        else if (accountOption == "4")
        {
            addSavingsAccount(person);
        }
        else if (option == "5" && person->getUsername() == "admin")
        {
        }
        else if (option == "6" && person->getUsername() == "admin")
        {
            exportData(persons, filePath);
        }
        else if (accountOption == "0")
        {
            exportData(persons, filePath);
            std::string logo = R"(
╔═══════════════════════════════════════════╗
║                 goodbye!                  ║
╚═══════════════════════════════════════════╝
)";
            std::cout << logo << std::endl;
            return;
        }
        else
        {
            std::cout << "invalid option. please try again." << std::endl;
        }
    }
}

void CLI::addSavingsAccount(const Person *person)
{
    // Savings* savingsAccount = new Savings(person, 0, 0.05);
    // person->addBankAccount(savingsAccount);
    // std::cout << "Savings account added successfully!" << std::endl;
}