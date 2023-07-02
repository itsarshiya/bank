#include <iostream>
#include <string>
#include <list>
#include "../Person/Person.h"
#include "../BankAccounts/BankAccount.h"
#include "ie/Export.h"
#include "cli.h"

void displayAccountInfo(const Person &person)
{
    // std::cout << "Account Information for " << person.getName() << std::endl;
    std::cout << "------------------------------" << std::endl;
    // for (const auto& account : person.getBankAccounts()) {
    //     std::cout << "Account Number: " << account->getAccountNumber() << std::endl;
    //     std::cout << "Balance: " << account->getBalance() << std::endl;
    //     std::cout << std::endl;
    // }
}

void printBankLogo()
{
    std::string logo = R"(
╔═══════════════════════════════════╗
║        welcome to moneybank       ║
╚═══════════════════════════════════╝
)";
    std::cout << logo << std::endl;
}

void runCLI(const std::list<Person> &persons)
{
    printBankLogo();

    std::string username, password;

    while (true)
    {
        std::cout << "please enter your username: ";
        std::cin >> username;
        std::cout << "please enter your password: ";
        std::cin >> password;

        auto it = std::find_if(persons.begin(), persons.end(), [&](const Person &p)
                               { return p.getUsername() == username && p.getPassword() == password; });

        if (it != persons.end())
        {
            break;
        }
        else
        {
            std::cout << "invalid username or password. please try again." << std::endl;
        }
    }

    const Person &person = *std::find_if(persons.begin(), persons.end(), [&](const Person &p)
                                         { return p.getUsername() == username; });

    displayAccountInfo(person);

    std::string option;
    while (true)
    {
        std::cout << "please select an option:" << std::endl;
        std::cout << "1. check balance" << std::endl;
        std::cout << "2. make a deposit" << std::endl;
        std::cout << "3. make a withdrawal" << std::endl;
        
        if (person.getUsername() == "admin") {
            std::cout << "4. import data" << std::endl;
            std::cout << "5. export data" << std::endl;
        }
        std::cout << "0. exit" << std::endl;
        std::cout << "option: ";
        std::cin >> option;

        if (option == "1")
        {
            displayAccountInfo(person);
        }
        else if (option == "2")
        {
            // Implement the deposit functionality
        }
        else if (option == "3")
        {
            // Implement the withdrawal functionality
        }
        else if (option == "4" && person.getUsername() == "admin")
        {
            
        }
        else if (option == "5" && person.getUsername() == "admin")
        {
            exportData(persons);
        }
        else if (option == "0")
        {
            std::string logo = R"(
╔═══════════════════════════════════╗
║             goodbye :)            ║
╚═══════════════════════════════════╝
)";
            std::cout << logo << std::endl;
            break;
        }
        else
        {
            std::cout << "invalid option. please try again." << std::endl;
        }
    }
}