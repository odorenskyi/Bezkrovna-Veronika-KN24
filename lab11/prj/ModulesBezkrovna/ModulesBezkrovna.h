#ifndef MODULESBEZKROVNA_H_INCLUDED
#define MODULESBEZKROVNA_H_INCLUDED

#include <string>
#include "struct_type_project_1.h"

List* load_register(std::string filename);

void save_to_file(List* list, std::string filename);

#endif // MODULESBEZKROVNA_H_INCLUDED
