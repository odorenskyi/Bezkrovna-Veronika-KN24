#include <iostream>
#include <string>
#include <fstream>

#include "struct_type_project_1.h"

using namespace std;

List* load_register(string filename)
{
    ifstream in(filename, ios::binary|ios::in);

    if (!in)
    {
        cout << "Не вдалося відкрити файл: " << filename << endl;
        return nullptr;
    }

    List* list = new List;
    list->head = nullptr;
    list->tail = nullptr;
    Node *current = list->head;

    in.seekg(0, ios::end);
    streamsize size_of_file = in.tellg();
    in.seekg(0, ios::beg);

    size_t size_of_string;

    while(in.tellg() < size_of_file)
    {
        if (current != nullptr)
        {
            current->next = new Node;
            current->next->previous = current;
            current = current->next;
        }
        else
        {
            list->head = new Node;
            list->head->previous = nullptr;
            current = list->head;
        }

        CarRegister data;

        in.read((char*) &size_of_string, sizeof(size_t));
        data.last_name.resize(size_of_string);
        in.read((char*) &data.last_name[0], size_of_string);

        in.read((char*) &size_of_string, sizeof(size_t));
        data.first_name.resize(size_of_string);
        in.read((char*) &data.first_name[0], size_of_string);

        in.read((char*) &size_of_string, sizeof(size_t));
        data.middle_name.resize(size_of_string);
        in.read((char*) &data.middle_name[0], size_of_string);

        in.read((char*) &size_of_string, sizeof(size_t));
        data.car_brand.resize(size_of_string);
        in.read((char*) &data.car_brand[0], size_of_string);

        in.read((char*) &data.year_of_manufacture, sizeof(int));

        in.read((char*) &size_of_string, sizeof(size_t));
        data.date_of_registration.resize(size_of_string);
        in.read((char*) &data.date_of_registration[0], size_of_string);

        in.read((char*) &size_of_string, sizeof(size_t));
        data.state_number.resize(size_of_string);
        in.read((char*) &data.state_number[0], size_of_string);

        in.read((char*) &size_of_string, sizeof(size_t));
        data.notes.resize(size_of_string);
        in.read((char*) &data.notes[0], size_of_string);

        current->data = data;
    }
    in.close();

    if (list->head != nullptr)
    {
        current->next = nullptr;
        list->tail = current;
    }

    return list;
}

void save_to_file(List* list, string filename)
{
    ofstream out(filename, ios::binary|ios::out);

    if (!out)
    {
        cout << "Не вдалося відкрити файл: " << filename << endl;  // якщо не відкрилось
        return;
    }

    Node *current = list->head;

    size_t size_of_string;

    while(current != nullptr)
    {
        size_of_string = current->data.last_name.size();
        out.write((char*) &size_of_string, sizeof(size_t));
        out.write((char*) &current->data.last_name[0], size_of_string);

        size_of_string = current->data.first_name.size();
        out.write((char*) &size_of_string, sizeof(size_t));
        out.write((char*) &current->data.first_name[0], size_of_string);

        size_of_string = current->data.middle_name.size();
        out.write((char*) &size_of_string, sizeof(size_t));
        out.write((char*) &current->data.middle_name[0], size_of_string);

        size_of_string = current->data.car_brand.size();
        out.write((char*) &size_of_string, sizeof(size_t));
        out.write((char*) &current->data.car_brand[0], size_of_string);

        out.write((char*) &current->data.year_of_manufacture, sizeof(int));

        size_of_string = current->data.date_of_registration.size();
        out.write((char*) &size_of_string, sizeof(size_t));
        out.write((char*) &current->data.date_of_registration[0], size_of_string);

        size_of_string = current->data.state_number.size();
        out.write((char*) &size_of_string, sizeof(size_t));
        out.write((char*) &current->data.state_number[0], size_of_string);

        size_of_string = current->data.notes.size();
        out.write((char*) &size_of_string, sizeof(size_t));
        out.write((char*) &current->data.notes[0], size_of_string);

        current = current->next;
    }

    out.close();
}
