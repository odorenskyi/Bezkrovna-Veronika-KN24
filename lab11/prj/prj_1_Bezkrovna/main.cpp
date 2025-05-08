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

     cout << "����������� ����� ��������� ������������ ��������� ������ ��� ������" << endl;

    while (true)
    {
        cout << "\n������ ������:" << endl;
        cout << "1. ������� ����� �� �����;\n2. ������� ����� � ��������� ����;\n3. ������ ����� ����� �� ������;\n4. ����� ������ � ����� �� ��������� �������;\n5. ��������� ������ � ������ �� ��������� �������;\n6. ���������� ������;\nq. ����� �� ��������.\n" << endl;
        cout << "������ ����� ������� ��� �� ������ � �������� Enter: " << endl;
        cin >> option;

        switch(option)
        {
        case '1':
            printRegister(list);
            break;
        case '2':
            cout << "������ ����� ���������� ����� ��� ��������� (�� �������� ������� ��� �����): " << endl;
            cin >> filename;
            printRegistryToFile(list, filename);
            break;
        case '3':
            addNewCarRecord(list);
            break;
        case '4':
            cout << "������ ��������� �����: " << endl;
            cin >> state_number;
            search_by_state_number("Register.txt", state_number);
            break;
        case '5':
            cout << "������ ��������� �����: " << endl;
            cin >> state_number;
            if (removeByStateNumber(*list, state_number))
            {
                cout << "����� ������ ��������." << endl;
            }
            else
            {
                cout << "����� � ����� ������� �� ��������" << endl;
            }
            break;
        case '6':
            save_to_file(list, "Register.txt");
            cout << "���� ���������." << endl;
            break;
        case 'q':
            save_to_file(list, "Register.txt");
            deleteRegistry(list);
            return 0;
        default:
            cout << "���� ������� �� ����!" << endl;
        }
    }
}
