#ifndef MODULESSEREDA_H_INCLUDED
#define MODULESSEREDA_H_INCLUDED

#include <string>

#include "struct_type_project_1.h"

void search_by_state_number(const std::string& filename, const std::string& state_number);

bool removeByStateNumber(List& list, const std::string& state_number);

void clearList(List& list);

#endif // MODULESSEREDA_H_INCLUDED
