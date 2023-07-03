#include <iostream>
#include <string>   
#include <vector>
#include "BankAccounts/BankAccount.h"
#include "BankAccounts/Savings/Savings.h"
#include "BankAccounts/Checking/Checking.h"
#include "Person/Person.h"
#include <unordered_map>
#include "cli/cli.h"
#include <list>
#include "cli/ie/Import.h"

int main() {
    CLI cli;
    std::string filePath = "../data/data.json";

    cli.runCLI(filePath);
    return 0;


    // Person person1("Arshiya Sharifi", "arshiya", "test");
    // BankAccount* account1 = new Savings(person1, 1000.0, 0.05);
    // BankAccount* account2 = new Checking(person1, 5000.0, 1000.0);
    // person1.addBankAccount(account1);
    // person1.addBankAccount(account2);
    // account2->display(); 
    // persons.push_back(&person1);

    // Person person2("developer", "admin", "test");
    // BankAccount* account3 = new Savings(person2, 1000000.0, 0.05);
    // person2.addBankAccount(account3);
    // account2->display(); 
    // persons.push_back(&person2);
    
    // Person person2("Micheal Jackson", "jackson", "test");
    // Person person3("developer", "admin", "test");
    // Person person4("Niska Mota", "niska", "1234");

    // BankAccount* account1 = new Savings("123456789", person1, 1000.0, 0.05);
    // BankAccount* account2 = new Checking("987654321", person2, 5000.0, 1000.0);

    // person1.addBankAccount(account1);
    // person2.addBankAccount(account2);

    // persons.push_back(person1);
    // persons.push_back(person2);
    // persons.push_back(person3);

}