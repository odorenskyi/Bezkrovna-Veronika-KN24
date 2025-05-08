#include <iostream>
#include <locale>
#include <string>
#include <fstream>
#include <windows.h>

#include "ModulesBezkrovna.h"
#include "ModulesDmytrenko.h"
#include "ModulesSereda.h"

using namespace std;

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    char option;
    string filename;
    string state_number;

    ofstream file("Register.txt", ios::binary|ios::app);
    file.close();

    List *list = load_register("Register.txt");
    if (list == nullptr)
    {
        list = new List;
        list->head = nullptr;
        list->tail = nullptr;
    }

     cout << "Електронний реєстр автомобілів регіонального сервісного центру МВС України" << endl;

    while (true)
    {
        cout << "\nСписок команд:" << endl;
        cout << "1. Вивести реєстр на екран;\n2. Вивести реєстр у текстовий файл;\n3. Додати новий запис до реєстру;\n4. Пошук запису у реєстрі за державним номером;\n5. Видалення запису з реєстра за державним номером;\n6. Збереження реєстру;\nq. Вихід із програми.\n" << endl;
        cout << "Введіть номер команди яку ви обрали і натисніть Enter: " << endl;
        cin >> option;

        switch(option)
        {
        case '1':
            printRegister(list);
            break;
        case '2':
            cout << "Введіть назву текстового файлу для виведення (не забудьте вказати тип файлу): " << endl;
            cin >> filename;
            printRegistryToFile(list, filename);
            break;
        case '3':
            addNewCarRecord(list);
            break;
        case '4':
            cout << "Введіть державний номер: " << endl;
            cin >> state_number;
            search_by_state_number("Register.txt", state_number);
            break;
        case '5':
            cout << "Введіть державний номер: " << endl;
            cin >> state_number;
            if (removeByStateNumber(*list, state_number))
            {
                cout << "Запис успішно вилучено." << endl;
            }
            else
            {
                cout << "Запис з таким номером не знайдено" << endl;
            }
            break;
        case '6':
            save_to_file(list, "Register.txt");
            cout << "Файл збережено." << endl;
            break;
        case 'q':
            save_to_file(list, "Register.txt");
            deleteRegistry(list);
            return 0;
        default:
            cout << "Такої команди не існує!" << endl;
        }
    }
}
