#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <windows.h>
#include "ModulesBezkrovna.h"

using namespace std;

void test_ECTS_rating()
{
    cout << "Завдання 9.1" << endl;
    int rating[] = {3, 38, 65, 70, 79, 84, 99, 101};
    string result_1[] = {"Оцінка: FX, Пояснення: з обов'язковим повторним курсом." , "Оцінка: F, Пояснення: з можливістю повторного складання.", "Оцінка: E, Пояснення: відповідає мінімальним критеріям.", "Оцінка: D, Пояснення: непогано, але зі значною кількістю недоліків.", "Оцінка: C, Пояснення: загалом правильне виконання із певною значною кількістю помилок.", "Оцінка: B, Пояснення: вище середнього, деякі помилки.", "Оцінка: A, Пояснення: відмінне виконання з незначною кількістю помилок.", "Помилка..."};
    for(int i = 0; i < 8; i++)
    {
        cout << "Вхідні дані:" << endl;
        cout << "Бал: "<<rating[i] << endl;
        cout << "Очікуваний результат:" << endl;
        cout << result_1[i] << endl;
        if(result_1[i] == string(ECTS_rating(rating[i])))
        {
            cout << "Test case "+ to_string(i+1) +" PASSED.\n" << endl;
        }
        else
        {
            cout << "Test case "+ to_string(i+1) +" FAILED.\n" << endl;
        }
    }
}

void test_week_temperature()
{
    cout << "Завдання 9.2" << endl;
    float mon[] = {13, 5, -3, 30, 1};
    float tue[] = {13, 5, -2, 31, 0};
    float wed[] = {12, 7, -1, 32, 3};
    float thu[] = {14, 11, -3, 27, 2};
    float fri[] = {18, 9, -4, 26, 3};
    float sat[] = {18, 10, -4, 26, 5};
    float sun[] = {9, 12, -1, 22, 4};
    float week_celsius, week_fahrenheit;
    string result_2_3[] = {"Середньотижнева температура за Цельсієм: 13.86\nСередньотижнева температура за Фаренгейтом: 56.94", "Середньотижнева температура за Цельсієм: 8.43\nСередньотижнева температура за Фаренгейтом: 47.17", "Середньотижнева температура за Цельсієм: -2.57\nСередньотижнева температура за Фаренгейтом: 27.37", "Середньотижнева температура за Цельсієм: 27.71\nСередньотижнева температура за Фаренгейтом: 81.89", "Середньотижнева температура за Цельсієм: 2.57\nСередньотижнева температура за Фаренгейтом: 36.63"};
    for(int i = 0; i < 5; i++)
    {
        cout << "Вхідні дані:" << endl;
        cout << "ПН: " << mon[i] << endl;
        cout << "ВТ: " << tue[i] << endl;
        cout << "СР: " << wed[i] << endl;
        cout << "ЧТ: " << thu[i] << endl;
        cout << "ПТ: " << fri[i] << endl;
        cout << "СБ: " << sat[i] << endl;
        cout << "НД: " << sun[i] << endl;
        cout << "Очікуваний результат:" << endl;
        cout << result_2_3[i] << endl;
        if(result_2_3[i] == string(week_temperature(mon[i], tue[i], wed[i], thu[i], fri[i], sat[i], sun[i], week_celsius, week_fahrenheit)))
        {
            cout << "Test case "+ to_string(i+1) +" PASSED.\n" << endl;
        }
        else
        {
            cout << "Test case "+ to_string(i+1) +" FAILED.\n" << endl;
        }
    }
}

void test_bits_analysis()
{
    cout << "Завдання 9.3" << endl;
    int N[] = {1948360, 25, 17948360, 25635, 1234567890};
    int result_3[] = {12, 29, 12, 26, 0};
    for(int i = 0; i < 5; i++)
    {
        cout << "Вхідні дані:" << endl;
        cout << N[i] << endl;
        cout << "Очікуваний результат:" << endl;
        cout << result_3[i] << endl;
        if(result_3[i] == bits_analysis(N[i]))
        {
            cout << "Test case "+ to_string(i+1) +" PASSED.\n" << endl;
        }
        else
        {
            cout << "Test case "+ to_string(i+1) +" FAILED.\n" << endl;
        }
    }
}

int main()
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    test_ECTS_rating();
    test_week_temperature();
    test_bits_analysis();
    return 0;
}
