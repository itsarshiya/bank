#include <iostream>
#include <string>
#include <list>
#include "../Person/Person.h"
#include "../BankAccounts/BankAccount.h"
#include "ie/Export.h"
#include "ie/Import.h"
#include "cli.h"

void CLI::displayAccountInfo(const Person &person)
{
    std::cout << "═════════════════════════════════════════════" << std::endl;
    std::cout << "account info for " << person.getName() << std::endl;
    std::cout << "═════════════════════════════════════════════" << std::endl;
    std::cout << "total balance: " << person.getTotalBalance() << std::endl;
    std::cout << "═════════════════════════════════════════════" << std::endl;
    for (const auto &account : person.getBankAccounts())
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

void CLI::runCLI(const std::string &filePath)
{

    importData(persons, filePath);

    printBankLogo();

    std::string username, password;

    while (true)
    {
        std::cout << "Please enter your username: ";
        std::cin >> username;
        std::cout << "Please enter your password: ";
        std::cin >> password;

        auto it = std::find_if(persons.begin(), persons.end(), [&](const Person *p)
                               { return p->getUsername() == username && p->getPassword() == password; });

        if (it != persons.end())
        {
            break;
        }
        else
        {
            std::cout << "Invalid username or password. Please try again." << std::endl;
        }
    }

    const Person *person = *std::find_if(persons.begin(), persons.end(), [&](const Person *p)
                                         { return p->getUsername() == username; });

    // displayAccountInfo(person);

    std::string option;
    while (true)
    {
        std::cout << "Please select an option:" << std::endl;
        std::cout << "1. Check balance" << std::endl;
        std::cout << "2. Make a deposit" << std::endl;
        std::cout << "3. Make a withdrawal" << std::endl;

        if (person->getUsername() == "admin")
        {
            std::cout << "4. Import data" << std::endl;
            std::cout << "5. Export data" << std::endl;
        }
        std::cout << "0. Exit" << std::endl;
        std::cout << "Option: ";
        std::cin >> option;

        if (option == "1")
        {
            // displayAccountInfo(person);
        }
        else if (option == "2")
        {
            // Implement the deposit functionality
        }
        else if (option == "3")
        {
            // Implement the withdrawal functionality
        }
        else if (option == "4" && person->getUsername() == "admin")
        {
        }
        else if (option == "5" && person->getUsername() == "admin")
        {
            std::string filePath = "data.json"; // Specify the desired file path
            exportData(persons, filePath);
        }
        else if (option == "0")
        {
            std::string logo = R"(
╔═══════════════════════════════════════════╗
║                 goodbye :)                ║
╚═══════════════════════════════════════════╝
)";
            std::cout << logo << std::endl;
            break;
        }
        else
        {
            std::cout << "Invalid option. Please try again." << std::endl;
        }
    }
}
