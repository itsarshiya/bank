#ifndef EXPORT_H
#define EXPORT_H

#include <list>
#include "../../Person/Person.h"

void exportData(const std::list<Person *> &persons, const std::string &filePath);

#endif
