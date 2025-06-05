#ifndef S_CALCULATION
#define S_CALCULATION

using namespace std;
#include <string>
#include <iostream>
#include <cmath>
#define _USE_MATH_DEFINES

float s_calculation (float x, float y);

string ECTS_rating (int rating);

string format_float(float value);

string week_temperature(float mon, float tue, float wed, float thu, float fri, float sat, float sun, float &week_celsius, float &week_fahrenheit);

int bits_analysis(int N);

int input_analysis(string file_input, string file_output);

int add_poem_with_time(string file_input);

int add_calculation_and_bits(float x, float y, int b, string file_output);

string read(string path);

vector<string> test_results(string exp_result_1, string exp_result_2, string exp_result_3);

vector<string> test_results_10_1(string exp_result_1, string exp_result_2, string exp_result_3, string exp_result_4, string exp_result_5);

vector<string> input_10_1(string exp_result_1, string exp_result_2, string exp_result_3, string exp_result_4);

vector<string> test_results_10_2(string exp_result_1, string exp_result_2, string exp_result_3);

class ClassLab12_Bezkrovna
{
    private:
        double height;
        double radius;
        string color;
    public:
        ClassLab12_Bezkrovna (double height, double radius, string color);
        double GetHeight();
        double GetRadius();
        string GetColor();
        void SetHeight(double input_height);
        void SetRadius(double input_radius);
        void SetColor(string input_color);
        double CountVolume();
};

ClassLab12_Bezkrovna() : height(1.0), radius(1.0), color("yellow") {}

ClassLab12_Bezkrovna::ClassLab12_Bezkrovna (double input_height, double input_radius, string input_color)
{
    if (input_height <= 0)
    {
        throw invalid_argument("Помилка: висота повинна бути додатньою.");
    }
    if (input_radius <= 0)
    {
        throw invalid_argument("Помилка: радіус повинен бути додатнім.");
    }

    height = input_height;
    radius = input_radius;
    color = input_color;
}

    ClassLab12_Bezkrovna(double input_height, double input_radius, string input_color)
    {


        height = input_height;
        radius = input_radius;
        color = input_color;
    }

double ClassLab12_Bezkrovna::GetHeight() const {return height;}
double ClassLab12_Bezkrovna::GetRadius() const {return radius;}
string ClassLab12_Bezkrovna::GetColor()const {return color;}

void ClassLab12_Bezkrovna::SetHeight(double input_height)
{
    if (input_height <= 0)
    {
        printf("Помилка!");
        return;
    }
    height = input_height;
}

void ClassLab12_Bezkrovna::SetRadius(double input_radius)
{
    if (input_radius <= 0)
    {
        printf("Помилка!");
        return;
    }
    radius = input_radius;
}

void ClassLab12_Bezkrovna::SetColor(string input_color)
{
    color = input_color;
}

double ClassLab12_Bezkrovna::CountVolume()
{
    return (1/3.0)*(M_PI*pow(radius, 2)*height);
}

#endif
