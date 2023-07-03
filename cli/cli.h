#ifndef CLI_H
#define CLI_H

#include <list>
#include "../Person/Person.h"

class CLI
{
private:
    std::list<Person *> persons;

public:
    void displayAccountInfo(const Person &person);
    void runCLI(const std::string& filePath);
    void printBankLogo();
};

#endif