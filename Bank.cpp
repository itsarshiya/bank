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


// int main() {
//     Person person1("John Doe", "john", "password123");
//     Person person2("Jane Smith", "jane", "pass123");

//     BankAccount* account1 = new Savings("123456789", person1, 1000.0, 0.05);
//     BankAccount* account2 = new Checking("987654321", person2, 5000.0, 1000.0);

//     // person1.addBankAccount(account1);
//     // person2.addBankAccount(account2);

//     person1.deposit("123456789", 500.0);
//     person1.withdraw("123456789", 200.0);
//     person2.withdraw("987654321", 4000.0);

//     std::cout << "Person 1's Account Details:" << std::endl;
//     person1.displayAccounts();

//     std::cout << "\nPerson 2's Account Details:" << std::endl;
//     person2.displayAccounts();

//     delete account1;
//     delete account2;

//     return 0;
// }

int main() {

    std::list<Person> persons;


    Person person1("Arshiya Sharifi", "arshiya", "test");
    Person person2("Micheal Jackson", "jackson", "test");
    Person person3("developer", "admin", "test");

    BankAccount* account1 = new Savings("123456789", person1, 1000.0, 0.05);
    BankAccount* account2 = new Checking("987654321", person2, 5000.0, 1000.0);

    // persons["john"].addBankAccount(account1);
    // persons["jane"].addBankAccount(account2);

    persons.push_back(person1);
    persons.push_back(person2);
    persons.push_back(person3);

    // Run the CLI
    runCLI(persons);


    delete account1;
    delete account2;

    return 0;
}