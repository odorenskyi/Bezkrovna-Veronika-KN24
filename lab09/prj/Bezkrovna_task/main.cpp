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
        cout << "Введіть символ: " << endl;
        cin >> symbol;
        if(symbol == 'h')
        {
            cout << "Введіть x" << endl;
            cin >> x;
            cout << "Введіть y" << endl;
            cin >> y;
            cout << "Результат виконання функції: \n" << s_calculation(x, y) << endl;
        }
        if(symbol == 'f')
        {
            cout << "Введіть набрану студентом кількість балів: " << endl;
            cin >> rating;
            cout << "Результат виконання функції: \n" << ECTS_rating(rating) << endl;
        }
        if(symbol == 'd')
        {
            cout << "Введіть середню температуру в понеділок: " << endl;
            cin >> mon;
            cout << "Введіть середню температуру в вівторок: " << endl;
            cin >> tue;
            cout << "Введіть середню температуру в середу: " << endl;
            cin >> wed;
            cout << "Введіть середню температуру в четвер: " << endl;
            cin >> thu;
            cout << "Введіть середню температуру в п'ятницю: " << endl;
            cin >> fri;
            cout << "Введіть середню температуру в суботу: " << endl;
            cin >> sat;
            cout << "Введіть середню температуру в неділю: " << endl;
            cin >> sun;
            cout << "Результат виконання функції: \n" << week_temperature(mon, tue, wed, thu, fri, sat, sun, week_celsius, week_fahrenheit) << endl;
        }
        if(symbol == 's')
        {
            cout << "Введіть число від 0 до 17948360: " << endl;
            cin >> N;
            cout << "Результат виконання функції: \n" << bits_analysis(N) << endl;
        }
        else if(symbol != 'a' && symbol != 'A' && symbol != 'p')
        {
            cout << '\a' << endl;
        }
    }while(symbol != 'a' && symbol != 'A' && symbol != 'p');
    return 0;
}
