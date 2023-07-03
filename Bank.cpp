#include <string>   
#include "cli/cli.h"

int main() {
    CLI cli;
    std::string filePath = "../data/data.json";

    cli.run(filePath);
    return 0;
}


// testdata

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

// BankAccount* account1 = new Savings(person1, 1000.0, 0.05);
// BankAccount* account2 = new Checking(person2, 5000.0, 1000.0);

// person1.addBankAccount(account1);
// person2.addBankAccount(account2);

// persons.push_back(person1);
// persons.push_back(person2);
// persons.push_back(person3);