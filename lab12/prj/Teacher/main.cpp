#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "ModulesBezkrovna.h"

using namespace std;

bool is_in_lab12(const string& filePath)
{
    return filePath.find("\\lab12\\prj") != string::npos;
}

bool check_main_location()
{
    string filePath = __FILE__;
    if (!is_in_lab12(filePath))
    {
        for (int i = 0; i < 100; ++i)
        {
            cout << '\a';
        }
        ofstream output("TestResults.txt");
        if (output)
        {
            output << "Встановлені вимоги порядку виконання лабораторної роботи порушено!";
            output.close();
            return false;
        }
        else
        {
            cerr << "Помилка, файл не може бути відкритий для письма!" << endl;
        }

    }
    return true;
}

int main()
{
    if (!check_main_location())
    {
        return 1;
    }
    ifstream input("C:\\Users\\Ніка\\Documents\\бмтп 2 сем\\Лабораторні роботи\\Bezkrovna-Veronika-KN24\\lab12\\TestSuite\\TestCase.txt");
    ofstream output("TestResults.txt");
    if (!input || !output)
	{
		cerr << "Помилка, файл не може бути відкритий!" << endl;
		return 1;
	}
	string line;
	const double EPSILON = 1e-1;
    int test_number = 1;
    while (getline(input, line))
    {
        stringstream ss(line);
        double height, radius, volume, result_volume;
        string color;
        ss >> height >> radius >> volume >> ws;
        getline(ss, color);
        ClassLab12_Bezkrovna Cone(height, radius, color);
        result_volume = Cone.CountVolume();
        output << "Test " << test_number++ << endl;
        output << "Об'єм: " << result_volume << endl;
        if(abs(result_volume - volume) < EPSILON)
        {
            output << "Status: passed" << endl;
        }
        else
        {
            output << "Status: failed" << endl;
        }
    }
    return 0;
}
