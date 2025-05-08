#ifndef MODULESDMYTRENKO_H_INCLUDED
#define MODULESDMYTRENKO_H_INCLUDED

#include "struct_type_project_1.h"

void addNewCarRecord(List* list);

void printRegister(const List* list);

void printRegistryToFile(const List* list, const std::string& filename);

void deleteRegistry(List* list);

#endif // MODULESDMYTRENKO_H_INCLUDED
