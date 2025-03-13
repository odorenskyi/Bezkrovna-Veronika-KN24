#include <iostream>
#include <iomanip>
#include <locale>
#include <windows.h>
#include <cmath>
#include "ModulesBezkrovna.h"

using namespace std;

void author()
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    cout << "\n┌────────────────────────┐\n"
         << "│   Bezkrovna Veronika   │\n"
         << "│   Безкровна Вероніка   │\n"
         << "│ © All Rights Reserved  │\n"
         << "└────────────────────────┘\n";
}

void bool_expression()
{
    cout << "Введіть a, b" << endl;
    float a,b;
    cin >> a >> b;
    bool logical_expression = a<=b-32;
    cout << a << "≤" << b << "-32 \n"
    << "Це є " << boolalpha << logical_expression <<"\n" << endl;
}

string decimal_to_hex(int decimal)
{
    stringstream stream;
    stream << hex << decimal;
    return stream.str();
}

int main()
{
    author();
    bool_expression();
    cout << "Введіть x, y, z" << endl;
    float x, y, z, decimal;
    cin >> x >> y >> z;
    decimal = x;
    cout << "x – в десятковій системі числення " << x <<", в шістнадцятковій " << decimal_to_hex(decimal) << endl;
    decimal = y;
    cout << "y – в десятковій системі числення " << y <<", в шістнадцятковій " << decimal_to_hex(decimal) << endl;
    decimal = z;
    cout << "z – в десятковій системі числення " << z <<", в шістнадцятковій " << decimal_to_hex(decimal) << endl;
    cout << "S = " << round((s_calculation(x, y)*100.0) / 100.0);
    return 0;
}
