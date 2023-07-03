#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>
#include "Export.h"
#include "../../BankAccounts/BankAccount.h"

using json = nlohmann::json;

void exportData(const std::list<Person*>& persons, const std::string& filePath) {
    json data = json::array();

    for (const Person* person : persons) {
        json personData;

        json accountsData = json::array();

        for (const BankAccount* account : person->getBankAccounts()) {
            json accountData;
            accountData["accountNumber"] = account->getAccountNumber();
            accountData["balance"] = account->getBalance();
            accountData["type"] = static_cast<int>(account->getType());
            accountsData.push_back(accountData);
        }

        personData["name"] = person->getName();
        personData["username"] = person->getUsername();
        personData["password"] = person->getPassword();
        personData["accounts"] = accountsData;

        data.push_back(personData);
    }

    std::ofstream outputFile(filePath);
    if (outputFile.is_open()) {
        outputFile << data.dump(4);  // Indentation of 4 spaces
        outputFile.close();
        std::cout << "data exported to " << filePath << std::endl;
    } else {
        std::cerr << "error opening " << filePath << std::endl;
    }
}