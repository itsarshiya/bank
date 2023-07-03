#ifndef IMPORT_H
#define IMPORT_H

#include <string>
#include <list>

class Person;

void importData(std::list<Person *> &persons, const std::string &filePath);

#endif
