#include <fstream>
#include <iostream>
#include "Import.h"
#include "../../Person/Person.h"
#include "../../BankAccounts/BankAccount.h"
#include "../../BankAccounts/Savings/Savings.h"
#include "../../BankAccounts/Checking/Checking.h"
#include <nlohmann/json.hpp>

using json = nlohmann::json;

void importData(std::list<Person*>& persons, const std::string& filePath) {
    std::ifstream inputFile(filePath);
    if (!inputFile.is_open()) {
        std::cerr << "failed to open file: " << filePath << std::endl;
        return;
    }

    json data;
    inputFile >> data;
    inputFile.close();

    for (const auto& personData : data) {
        std::string name = personData["name"];
        std::string username = personData["username"];
        std::string password = personData["password"];

        Person* person = new Person(name, username, password);

        for (const auto& accountData : personData["accounts"]) {
            std::string accountNumber = accountData["accountNumber"];
            double balance = accountData["balance"];
            Type type = static_cast<Type>(accountData["type"]);

            BankAccount* account = nullptr;
            if (type == Type::Savings) {
                account = new Savings(*person, balance, 0.05);
            } else if (type == Type::Checking) {
                account = new Checking(*person, balance, 1000.0);
            }

            if (account) {
                person->addBankAccount(account);
            }
        }

        persons.push_back(person);
    }
}
