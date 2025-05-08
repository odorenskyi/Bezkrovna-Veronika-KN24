#ifndef STRUCT_TYPE_PROJECT_1_H_INCLUDED
#define STRUCT_TYPE_PROJECT_1_H_INCLUDED

#include <string>

struct CarRegister {
  std::string last_name; //Прізвище
  std::string first_name; //Ім'я
  std::string middle_name; //По батькові
  std::string car_brand; // Марка автомобіля
  int year_of_manufacture; //Рік випуску
  std::string date_of_registration; //Дата реєстрації
  std::string state_number; // Виданий державний номер
  std::string notes; //Примітки
};

// Вузол списку
struct Node {
    CarRegister data;
    Node* previous;
    Node* next;
};

// Двобічний список
struct List {
    Node* head = nullptr;
    Node* tail = nullptr;
};

#endif // STRUCT_TYPE_PROJECT_1_H_INCLUDED

