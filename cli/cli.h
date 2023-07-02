#ifndef CLI_H
#define CLI_H

#include <list>
#include "../Person/Person.h"

void displayAccountInfo(const Person& person);
void runCLI(const std::list<Person>& persons);
void printBankLogo();

#endif