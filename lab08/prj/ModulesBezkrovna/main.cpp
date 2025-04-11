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
        cout << "�������: ����� �� ���������� ������� ��'�����" << endl;
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
        return "�������...";
    }
    if (rating>=1 && rating<=34)
    {
        return "������: FX, ���������: � ����'������� ��������� ������.";
    }
    if (rating>=35 && rating<=59)
    {
        return "������: F, ���������: � ��������� ���������� ���������.";
    }
    if (rating>=60 && rating<=66)
    {
        return "������: E, ���������: ������� ��������� ��������.";
    }
    if (rating>=67 && rating<=74)
    {
        return "������: D, ���������: ��������, ��� � ������� ������� �������.";
    }
    if (rating>=75 && rating<=81)
    {
        return "������: C, ���������: ������� ��������� ��������� �� ������ ������� ������� �������.";
    }
    if (rating>=82 && rating<=89)
    {
        return "������: B, ���������: ���� ����������, ���� �������.";
    }
    if (rating>=90 && rating<=100)
    {
        return "������: A, ���������: ������ ��������� � ��������� ������� �������.";
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
    string result = "��������������� ����������� �� ������: " + format_float(week_celsius) + "\n��������������� ����������� �� �����������: " + format_float(week_fahrenheit);
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
		cerr << "�������, ���� �� ���� ���� �������� ��� ������!" << endl;
		exit(1);
	}
    ifstream input(file_input);
    if (!input)
	{
		cerr << "�������, ���� �� ���� ���� �������� ��� �������!" << endl;
		exit(1);
	}
    output << "��������� �������" << endl;
    output << "����" << endl;
    output << "�������������" << endl;
    output << "������" << endl;
    output << "2025 ��" << endl;
    string text;
    string poem = "��� ������� � ����� ���, ����, "
                  "���, ��� ����������� ��� ����: "
                  "������ �����, � ������ ��� ����, "
                  "� �����, �� � ���� �����; "
                  "��� ������� ��������� �������, "
                  "�� �� ���� ��� �������, "
                  "��� ������� ���������� ������ "
                  "� ������, �� ������ �����. ";
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
        output << "\n� ���� ���� ����������" << endl;
        output.close();
        ofstream input(file_input, ios::trunc);
        if (!input)
        {
            cerr << "�������, ���� �� ���� ���� �������� ��� ������!" << endl;
            exit(1);
        }
        input << "��� �������!" << endl;
        input.close();
        return 0;
    }
    else if (is_word(text))
    {
        output <<  "\nʳ������ ���� � ����: " << text.length()<< endl;
    }
    else
    {
        output <<  "\n����� �������" << endl;
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
        output <<  "\n����� �������� � �������� ������ ���� ������� ������ \"��� ������� � ����� ���, ����\":" << endl;
        output <<  "��� ������� � ����� ���, ����,\n���, ��� ����������� ��� ����:\n������ �����, � ������ ��� ����,\n� �����, �� � ���� �����;\n��� ������� ��������� �������,\n�� �� ���� ��� �������,\n��� ������� ���������� ������\n� ������, �� ������ �����." << endl;
    }
    else
    {
        output <<  "\n����� �� �������� � �������� ������ ���� ������� ������ \"��� ������� � ����� ���, ����\":" << endl;
        output <<  "��� ������� � ����� ���, ����,\n���, ��� ����������� ��� ����:\n������ �����, � ������ ��� ����,\n� �����, �� � ���� �����;\n��� ������� ��������� �������,\n�� �� ���� ��� �������,\n��� ������� ���������� ������\n� ������, �� ������ �����." << endl;
    }
    output.close();
    return 0;
}

int add_poem_with_time(string file_input)
{
    ofstream input(file_input, ios::app);
    if (!input)
	{
		cerr << "�������, ���� �� ���� ���� �������� ��� ������!" << endl;
		exit(1);
	}
	input << "��� ������� � ����� ���, ����,\n���, ��� ����������� ��� ����:\n������ �����, � ������ ��� ����,\n� �����, �� � ���� �����;\n��� ������� ��������� �������,\n�� �� ���� ��� �������,\n��� ������� ���������� ������\n� ������, �� ������ �����.\n �� ������ �� ��� ���� ������� -\n�� ���� � �� ���� � �����.\n�� � �� ������ �� ������� ������,\n�� ������ ������ � ��." << endl;
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
		cerr << "�������, ���� �� ���� ���� �������� ��� ������!" << endl;
		exit(1);
	}
	output << s_calculation(x, y) << endl;
	bitset<32> bit_b(b);
	output << bit_b << endl;
	output.close();
    return 0;
}

string read(string path)
{
    ifstream file(path);
    if (!file)
	{
		return "�������, ���� �� ���� ���� �������� ��� �������!";
	}
    string text;
    string line;
    while (getline(file, line))
    {
        text += line + '\n';
    }
    file.close();
    return text;
}

vector<string> test_results(string exp_result_1, string exp_result_2, string exp_result_3)
{

    vector<string> Test_results;
    string expected_result_1 = read(exp_result_1);
    string expected_result_2 = read(exp_result_2);
    string expected_result_3 = read(exp_result_3);
    Test_results.push_back(expected_result_1);
    Test_results.push_back(expected_result_2);
    Test_results.push_back(expected_result_3);
    return Test_results;
}

vector<string> test_results_10_1(string exp_result_1, string exp_result_2, string exp_result_3, string exp_result_4, string exp_result_5)
{

    vector<string> Test_results;
    string expected_result_1 = read(exp_result_1);
    string expected_result_2 = read(exp_result_2);
    string expected_result_3 = read(exp_result_3);
    string expected_result_4 = read(exp_result_4);
    string expected_result_5 = read(exp_result_5);
    Test_results.push_back(expected_result_1);
    Test_results.push_back(expected_result_2);
    Test_results.push_back(expected_result_3);
    Test_results.push_back(expected_result_4);
    Test_results.push_back(expected_result_5);
    return Test_results;
}

vector<string> input_10_1(string exp_result_1, string exp_result_2, string exp_result_3, string exp_result_4)
{
    vector<string> Test_results;
    string expected_result_1 = read(exp_result_1);
    string expected_result_2 = read(exp_result_2);
    string expected_result_3 = read(exp_result_3);
    string expected_result_4 = read(exp_result_4);
    Test_results.push_back(expected_result_1);
    Test_results.push_back(expected_result_2);
    Test_results.push_back(expected_result_3);
    Test_results.push_back(expected_result_4);
    return Test_results;
}

vector<string> test_results_10_2(string exp_result_1, string exp_result_2, string exp_result_3)
{
    time_t now = time(NULL);
    char date_time[100];
    strftime(date_time, 100, "%Y-%m-%d %H:%M:%S", localtime(&now));
    vector<string> Test_results;
    string expected_result_1 = read(exp_result_1);
    expected_result_1 += date_time;
    expected_result_1 += '\n';
    string expected_result_2 = read(exp_result_2);
    expected_result_2 += date_time;
    expected_result_2 += '\n';
    string expected_result_3 = read(exp_result_3);
    expected_result_3 += date_time;
    expected_result_3 += '\n';
    Test_results.push_back(expected_result_1);
    Test_results.push_back(expected_result_2);
    Test_results.push_back(expected_result_3);
    return Test_results;
}

