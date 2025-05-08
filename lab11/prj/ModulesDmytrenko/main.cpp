#include <iostream>
#include <fstream>
#include <string>
#include <locale>
#include <windows.h>
#include "struct_type_project_1.h"


void addNewCarRecord(List* list) {
    Node* newNode = new Node;
    newNode->previous = nullptr;
    newNode->next = nullptr;

    CarRegister& car = newNode->data;

    std::cin.ignore();

    do {
        std::cout << "Введіть прізвище: ";
        std::getline(std::cin, car.last_name);
        if (car.last_name.empty()) {
            std::cout << "Помилка! Прізвище не може бути порожнім.\n";
        }
    } while (car.last_name.empty());

    do {
        std::cout << "Введіть ім'я: ";
        std::getline(std::cin, car.first_name);
        if (car.first_name.empty()) {
            std::cout << "Помилка! Ім'я не може бути порожнім.\n";
        }
    } while (car.first_name.empty());

    do {
        std::cout << "Введіть по батькові: ";
        std::getline(std::cin, car.middle_name);
        if (car.middle_name.empty()) {
            std::cout << "Помилка! По батькові не може бути порожнім.\n";
        }
    } while (car.middle_name.empty());

    do {
        std::cout << "Введіть марку автомобіля: ";
        std::getline(std::cin, car.car_brand);
        if (car.car_brand.empty()) {
            std::cout << "Помилка! Марка авто не може бути порожньою.\n";
        }
    } while (car.car_brand.empty());

    do {
        std::cout << "Введіть рік випуску: ";
        std::string input;
        std::getline(std::cin, input);
        try {
            car.year_of_manufacture = std::stoi(input);
            if (car.year_of_manufacture < 1886 || car.year_of_manufacture > 2025) {
                std::cout << "Помилка! Некоректний рік випуску.\n";
                car.year_of_manufacture = 0;
            }
        } catch (...) {
            std::cout << "Помилка! Рік має бути числом.\n";
            car.year_of_manufacture = 0;
        }
    } while (car.year_of_manufacture == 0);

    do {
        std::cout << "Введіть дату реєстрації: ";
        std::getline(std::cin, car.date_of_registration);
        if (car.date_of_registration.empty()) {
            std::cout << "Помилка! Дата не може бути порожньою.\n";
        }
    } while (car.date_of_registration.empty());

    do {
        std::cout << "Введіть державний номер: ";
        std::getline(std::cin, car.state_number);
        if (car.state_number.empty()) {
            std::cout << "Помилка! Номер не може бути порожнім.\n";
        }
    } while (car.state_number.empty());

    do {
        std::cout << "Введіть примітки: ";
        std::getline(std::cin, car.notes);
        if (car.notes.empty()) {
            std::cout << "Помилка! Примітки не можуть бути порожніми (введіть хоча б '-')\n";
        }
    } while (car.notes.empty());

    // Додавання у список
    if (list->head == nullptr) {
        list->head = list->tail = newNode;
    } else {
        newNode->previous = list->tail;
        list->tail->next = newNode;
        list->tail = newNode;
    }

    std::cout << "Новий запис успішно додано!\n";
}

void printRegister(const List* list) // Виведення реєстру на екран
{
    Node* current = list->head;
    if (!current)
    {
        std::cout << "Список порожній.\n";
        return;
    }

    while (current)
        {
        const CarRegister& car = current->data;
        std::cout << "---------------------------\n";
        std::cout << "Прізвище: " << car.last_name << "\n";
        std::cout << "Ім'я: " << car.first_name << "\n";
        std::cout << "По батькові: " << car.middle_name << "\n";
        std::cout << "Марка авто: " << car.car_brand << "\n";
        std::cout << "Рік випуску: " << car.year_of_manufacture << "\n";
        std::cout << "Дата реєстрації: " << car.date_of_registration << "\n";
        std::cout << "Державний номер: " << car.state_number << "\n";
        std::cout << "Примітки: " << car.notes << "\n";
        current = current->next;
    }
}


void printRegistryToFile(const List* list, const std::string& filename) //Виведення всього реєстру у заданий текстовий файл
{
    std::ofstream outFile(filename);
    if (!outFile)
    {
        std::cerr << "Помилка відкриття файлу для запису.\n";
        return;
    }

    Node* current = list->head;
    while (current)
    {
        const CarRegister& car = current->data;
        outFile << "---------------------------\n";
        outFile << "Прізвище: " << car.last_name << "\n";
        outFile << "Ім'я: " << car.first_name << "\n";
        outFile << "По батькові: " << car.middle_name << "\n";
        outFile << "Марка авто: " << car.car_brand << "\n";
        outFile << "Рік випуску: " << car.year_of_manufacture << "\n";
        outFile << "Дата реєстрації: " << car.date_of_registration << "\n";
        outFile << "Державний номер: " << car.state_number << "\n";
        outFile << "Примітки: " << car.notes << "\n";
        current = current->next;
    }

    outFile.close();
    std::cout << "Реєстр збережено в файл: " << filename << "\n";
}

// Звільнення пам'яті
void deleteRegistry(List* list)
{
    Node* current = list->head;
    while (current)
    {
        Node* next = current->next;
        delete current;
        current = next;
    }
    list->head = list->tail = nullptr;
}


