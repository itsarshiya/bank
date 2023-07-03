#include <gtest/gtest.h>
#include <fstream>
#include "../cli/ie/Export.h"
#include "../cli/ie/Import.h"
#include "../Person/Person.h"
#include "../BankAccounts/BankAccount.h"
#include "../BankAccounts/Savings/Savings.h"
#include "../BankAccounts/Checking/Checking.h"
#include "../cli/cli.h"

#include <nlohmann/json.hpp>

using json = nlohmann::json;

TEST(ExportDataTest, ExportToFile) {
    std::list<Person*> persons;
    Person* person1 = new Person("Arshiya Sharifi", "arshiya", "test");
    Person* person2 = new Person("Micheal Jackson", "jackson", "test");

    Savings* savings1 = new Savings(person1, 5000.0, 0.05);
    Checking* checking1 = new Checking(person1, 1000.0, 100.0);
    person1->addBankAccount(savings1);
    person1->addBankAccount(checking1);

    persons.push_back(person1);
    persons.push_back(person2);

    std::string filePath = "test_data.json";

    exportData(persons, filePath);

    std::ifstream inputFile(filePath);
    if (!inputFile.is_open()) {
        FAIL() << "Failed to open file: " << filePath;
    }

    json data;
    inputFile >> data;
    inputFile.close();

    ASSERT_TRUE(data.is_array());
    ASSERT_EQ(data.size(), 2); // check if 2 persons are in data

    const auto& personData1 = data[0];
    ASSERT_EQ(personData1["name"], "Arshiya Sharifi");
    ASSERT_EQ(personData1["username"], "arshiya");
    ASSERT_EQ(personData1["password"], "test");

    ASSERT_TRUE(personData1["accounts"].is_array());
    ASSERT_EQ(personData1["accounts"].size(), 2); // check if two accounts are made 

    // savings
    const auto& accountData1 = personData1["accounts"][0];
    ASSERT_EQ(accountData1["accountNumber"], savings1->getAccountNumber());
    ASSERT_EQ(accountData1["balance"], savings1->getBalance());
    ASSERT_EQ(accountData1["type"], static_cast<int>(Type::Savings));

    // checking
    const auto& accountData2 = personData1["accounts"][1];
    ASSERT_EQ(accountData2["accountNumber"], checking1->getAccountNumber());
    ASSERT_EQ(accountData2["balance"], checking1->getBalance());
    ASSERT_EQ(accountData2["type"], static_cast<int>(Type::Checking));
}

TEST(ImportDataTest, ImportFromFile) {
    std::list<Person*> persons;

    std::string filePath = "test_data.json";

    importData(persons, filePath);

    // check the details of arshiya
    Person* person1 = *persons.begin();
    ASSERT_EQ(person1->getName(), "Arshiya Sharifi");
    ASSERT_EQ(person1->getUsername(), "arshiya");
    ASSERT_EQ(person1->getPassword(), "test");

    // check the bankaccounts of arshiya
    ASSERT_EQ(person1->getBankAccounts().size(), 2);

    // check the details of the first bank account of arshiya which is savings
    BankAccount* account1 = person1->getBankAccounts().front();
    ASSERT_DOUBLE_EQ(account1->getBalance(), 5000.0);
    ASSERT_EQ(account1->getType(), Type::Savings);

    std::remove(filePath.c_str());
    for (auto person : persons) {
        delete person;
    }
}


int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}