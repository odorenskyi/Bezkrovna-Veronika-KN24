#include "ModulesSereda.h"
#include "struct_type_project_1.h"

#include <iostream>
#include <fstream>

void search_by_state_number(const std::string& filename, const std::string& search_number) {
    std::ifstream file(filename, std::ios::binary);
    if (!file) {
        std::cerr << "�� ������� ������� ����: " << filename << std::endl;
        return;
    }

    auto read_string = [&](std::ifstream& f) {
        size_t size;
        f.read(reinterpret_cast<char*>(&size), sizeof(size));
        std::string str(size, '\0');
        f.read(&str[0], size);
        return str;
    };

    bool found = false;
    while (file.peek() != EOF) {
        CarRegister record;
        record.last_name = read_string(file);
        record.first_name = read_string(file);
        record.middle_name = read_string(file);
        record.car_brand = read_string(file);
        file.read(reinterpret_cast<char*>(&record.year_of_manufacture), sizeof(int));
        record.date_of_registration = read_string(file);
        record.state_number = read_string(file);
        record.notes = read_string(file);

        if (record.state_number == search_number) {
            std::cout << "�������� �����:\n";
            std::cout << "�������: " << record.last_name << "\n";
            std::cout << "���: " << record.first_name << "\n";
            std::cout << "�� �������: " << record.middle_name << "\n";
            std::cout << "����� ����: " << record.car_brand << "\n";
            std::cout << "г� �������: " << record.year_of_manufacture << "\n";
            std::cout << "���� ���������: " << record.date_of_registration << "\n";
            std::cout << "����. �����: " << record.state_number << "\n";
            std::cout << "�������: " << record.notes << "\n";
            found = true;
            break;
        }
    }

    if (!found) {
        std::cout << "����� �� ��������� ������� '" << search_number << "' �� ��������.\n";
    }

    file.close();
}

bool removeByStateNumber(List& list, const std::string& state_number) {
    Node* current = list.head;

    while (current != nullptr) {
        if (current->data.state_number == state_number) {
            if (current->previous)
                current->previous->next = current->next;
            else
                list.head = current->next;

            if (current->next)
                current->next->previous = current->previous;
            else
                list.tail = current->previous;

            delete current;
            return true; // ������ ���������
        }

        current = current->next;
    }

    return false; // ����� � ����� ������� �� ��������
}

void clearList(List& list) {
    Node* current = list.head;
    while (current != nullptr) {
        Node* toDelete = current;
        current = current->next;
        delete toDelete;
    }
    list.head = list.tail = nullptr;
}
