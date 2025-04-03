#include <cmath>
#include <iostream>
#include <iomanip>
#include <bitset>
#include <string>
#include <sstream>
#include <locale>
#include <windows.h>
#define _USE_MATH_DEFINES

using namespace std;

float s_calculation (float x, float y)
{
    if ((pow(y,x) - M_PI) < 0)
    {
        cout << "Помилка: вираз під квадратним коренем від'ємний" << endl;
    }
    float S = pow(x,2) - pow(y, 3) + sqrt(pow(y,x) - M_PI);

    return S;
}

string ECTS_rating (int rating)
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    if (rating<1 || rating>100)
    {
        return "Помилка...";
    }
    if (rating>=1 && rating<=34)
    {
        return "Оцінка: FX, Пояснення: з обов'язковим повторним курсом.";
    }
    if (rating>=35 && rating<=59)
    {
        return "Оцінка: F, Пояснення: з можливістю повторного складання.";
    }
    if (rating>=60 && rating<=66)
    {
        return "Оцінка: E, Пояснення: відповідає мінімальним критеріям.";
    }
    if (rating>=67 && rating<=74)
    {
        return "Оцінка: D, Пояснення: непогано, але зі значною кількістю недоліків.";
    }
    if (rating>=75 && rating<=81)
    {
        return "Оцінка: C, Пояснення: загалом правильне виконання із певною значною кількістю помилок.";
    }
    if (rating>=82 && rating<=89)
    {
        return "Оцінка: B, Пояснення: вище середнього, деякі помилки.";
    }
    if (rating>=90 && rating<=100)
    {
        return "Оцінка: A, Пояснення: відмінне виконання з незначною кількістю помилок.";
    }
}

string format_float(float value) {
    ostringstream oss;
    oss << fixed << setprecision(2) << value;
    return oss.str();
}

string week_temperature(float mon, float tue, float wed, float thu, float fri, float sat, float sun, float &week_celsius, float &week_fahrenheit)
{
    week_celsius = (mon+tue+wed+thu+fri+sat+sun)/7;
    week_fahrenheit = 32+((9.0/5)*week_celsius);
    string result = "Середньотижнева температура за Цельсієм: " + format_float(week_celsius) + "\nСередньотижнева температура за Фаренгейтом: " + format_float(week_fahrenheit);
    return result;
}

int bits_analysis(int N)
{
    if (N < 0 || N > 17948360)
    {
        return nan("");
    }
    bitset<32> bit_N(N);
    int check = bit_N[12] == 0 ? 32 - bit_N.count() : bit_N.count();
    return check;
}

