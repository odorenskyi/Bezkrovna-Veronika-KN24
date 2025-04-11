#include <cmath>
#include <iostream>
#include <iomanip>
#include <bitset>
#include <string>
#include <sstream>
#include <locale>
#include <windows.h>
#include <fstream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
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

bool is_word(string text)
{
    for (char c : text)
    {
        if (!isalpha(c))
        {
            return false;
        }
    }
    return !text.empty();
}

int input_analysis(string file_input, string file_output)
{
    setlocale (LC_CTYPE, "ukr");
    ofstream output(file_output);
    if (!output)
	{
		cerr << "Помилка, файл не може бути відкритий для письма!" << endl;
		exit(1);
	}
    ifstream input(file_input);
    if (!input)
	{
		cerr << "Помилка, файл не може бути відкритий для читання!" << endl;
		exit(1);
	}
    output << "Безкровна Вероніка" << endl;
    output << "ЦНТУ" << endl;
    output << "Кропивницький" << endl;
    output << "Україна" << endl;
    output << "2025 рік" << endl;
    string text;
    string poem = "Хай щастить у Вашій хаті, мамо, "
                  "Всім, хто переступить Ваш поріг: "
                  "Добрим людям, і птахам так само, "
                  "І котові, що в теплі приліг; "
                  "Хай щастить кожненькій деревині, "
                  "Що до хати віти притуля, "
                  "Хай щастить малесенькій травині "
                  "Й вітерцю, що приліта здаля. ";
    vector<string> words;
    string word;
    bool found = false;
    for (char c : poem)
    {
        if (isalpha(c))
        {
            word += c;
        }
        else
        {
            if (!word.empty())
            {
                words.push_back(word);
                word.clear();
            }
        }
    }
    if (!word.empty())
    {
        words.push_back(word);
    }
    input >> text;
    input.close();
    if (text.length() == 1 && ispunct(text[0]))
    {
        output << "\nУ файлі знак пунктуації" << endl;
        output.close();
        ofstream input(file_input, ios::trunc);
        if (!input)
        {
            cerr << "Помилка, файл не може бути відкритий для письма!" << endl;
            exit(1);
        }
        input << "Хай щастить!" << endl;
        input.close();
        return 0;
    }
    else if (is_word(text))
    {
        output <<  "\nКількість літер у слові: " << text.length()<< endl;
    }
    else
    {
        output <<  "\nЛеонід Каденюк" << endl;
        output.close();
        return 0;
    }
    transform(text.begin(), text.end(), text.begin(), ::tolower);
    for (int i = 0; i < words.size(); ++i)
    {
        transform(words[i].begin(), words[i].end(), words[i].begin(), ::tolower);
        if (words[i] == text)
        {
            found = true;
            break;
        }
    }
    if (found)
    {
        output <<  "\nСлово міститься у наступній частині вірша Анатолія Тарана \"Хай щастить у Вашій хаті, мамо\":" << endl;
        output <<  "Хай щастить у Вашій хаті, мамо,\nВсім, хто переступить Ваш поріг:\nДобрим людям, і птахам так само,\nІ котові, що в теплі приліг;\nХай щастить кожненькій деревині,\nЩо до хати віти притуля,\nХай щастить малесенькій травині\nЙ вітерцю, що приліта здаля." << endl;
    }
    else
    {
        output <<  "\nСлово НЕ міститься у наступній частині вірша Анатолія Тарана \"Хай щастить у Вашій хаті, мамо\":" << endl;
        output <<  "Хай щастить у Вашій хаті, мамо,\nВсім, хто переступить Ваш поріг:\nДобрим людям, і птахам так само,\nІ котові, що в теплі приліг;\nХай щастить кожненькій деревині,\nЩо до хати віти притуля,\nХай щастить малесенькій травині\nЙ вітерцю, що приліта здаля." << endl;
    }
    output.close();
    return 0;
}

int add_poem_with_time(string file_input)
{
    ofstream input(file_input, ios::app);
    if (!input)
	{
		cerr << "Помилка, файл не може бути відкритий для письма!" << endl;
		exit(1);
	}
	input << "Хай щастить у Вашій хаті, мамо,\nВсім, хто переступить Ваш поріг:\nДобрим людям, і птахам так само,\nІ котові, що в теплі приліг;\nХай щастить кожненькій деревині,\nЩо до хати віти притуля,\nХай щастить малесенькій травині\nЙ вітерцю, що приліта здаля.\n Ви завжди за всіх були дбайливі -\nБо така ж та доля у вдови.\nБо ж як будуть всі навкруг щасливі,\nТо щасливі будете і Ви." << endl;
    time_t now = time(NULL);
    char date_time[100];
    strftime(date_time, 100, "%Y-%m-%d %H:%M:%S", localtime(&now));
    input << date_time << endl;
    input.close();
    return 0;
}

int add_calculation_and_bits(float x, float y, int b, string file_output)
{
    ofstream output(file_output, ios::app);
    if (!output)
	{
		cerr << "Помилка, файл не може бути відкритий для письма!" << endl;
		exit(1);
	}
	output << s_calculation(x, y) << endl;
	bitset<32> bit_b(b);
	output << bit_b << endl;
	output.close();
    return 0;
}

