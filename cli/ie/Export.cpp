#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>
#include "Export.h"

using json = nlohmann::json;

void exportData(const std::list<Person>& persons) {
    json data = json::array();

    for (const Person& person : persons) {
        json personData;
        personData["name"] = person.getName();
        personData["username"] = person.getUsername();
        personData["password"] = person.getPassword();

        json accountsData = json::array();

        // for (const BankAccount* account : person.getBankAccounts()) {
        //     // Create a JSON object for each account
        //     json accountData;
        //     accountData["accountNumber"] = account->getAccountNumber();
        //     accountData["balance"] = account->getBalance();

        //     accountsData.push_back(accountData);
        // }

        personData["accounts"] = accountsData;

        data.push_back(personData);
    }

    std::ofstream outputFile("data.json");
    if (outputFile.is_open()) {
        outputFile << data.dump(4);  // Indentation of 4 spaces
        outputFile.close();
        std::cout << "Data exported to data.json successfully." << std::endl;
    } else {
        std::cerr << "Error opening data.json for writing." << std::endl;
    }
}
