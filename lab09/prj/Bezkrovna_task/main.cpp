#include <iostream>
#include <locale>
#include <windows.h>
#include "ModulesBezkrovna.h"

using namespace std;

int main()
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    float x, y;
    int rating;
    float mon, tue, wed, thu, fri, sat, sun;
    float week_celsius, week_fahrenheit;
    int N;
    char symbol;
    do
    {
        cout << "������ ������: " << endl;
        cin >> symbol;
        if(symbol == 'h')
        {
            cout << "������ x" << endl;
            cin >> x;
            cout << "������ y" << endl;
            cin >> y;
            cout << "��������� ��������� �������: \n" << s_calculation(x, y) << endl;
        }
        if(symbol == 'f')
        {
            cout << "������ ������� ��������� ������� ����: " << endl;
            cin >> rating;
            cout << "��������� ��������� �������: \n" << ECTS_rating(rating) << endl;
        }
        if(symbol == 'd')
        {
            cout << "������ ������� ����������� � ��������: " << endl;
            cin >> mon;
            cout << "������ ������� ����������� � �������: " << endl;
            cin >> tue;
            cout << "������ ������� ����������� � ������: " << endl;
            cin >> wed;
            cout << "������ ������� ����������� � ������: " << endl;
            cin >> thu;
            cout << "������ ������� ����������� � �'������: " << endl;
            cin >> fri;
            cout << "������ ������� ����������� � ������: " << endl;
            cin >> sat;
            cout << "������ ������� ����������� � �����: " << endl;
            cin >> sun;
            cout << "��������� ��������� �������: \n" << week_temperature(mon, tue, wed, thu, fri, sat, sun, week_celsius, week_fahrenheit) << endl;
        }
        if(symbol == 's')
        {
            cout << "������ ����� �� 0 �� 17948360: " << endl;
            cin >> N;
            cout << "��������� ��������� �������: \n" << bits_analysis(N) << endl;
        }
        else if(symbol != 'a' && symbol != 'A' && symbol != 'p')
        {
            cout << '\a' << endl;
        }
    }while(symbol != 'a' && symbol != 'A' && symbol != 'p');
    return 0;
}
