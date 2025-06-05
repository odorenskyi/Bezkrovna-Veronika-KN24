#ifndef MODULESBEZKROVNA_H_INCLUDED
#define MODULESBEZKROVNA_H_INCLUDED

using namespace std;
#include <string>
#include <iostream>
#include <cmath>
#include <stdexcept>
#define _USE_MATH_DEFINES

class ClassLab12_Bezkrovna
{
    private:
        double height;
        double radius;
        string color;
    public:
        ClassLab12_Bezkrovna();
        ClassLab12_Bezkrovna (double height, double radius, string color);
        double GetHeight() const;
        double GetRadius() const;
        string GetColor() const;
        void SetHeight(double input_height);
        void SetRadius(double input_radius);
        void SetColor(string input_color);
        double CountVolume();
};

ClassLab12_Bezkrovna::ClassLab12_Bezkrovna() : height(1.0), radius(1.0), color("yellow") {}

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

double ClassLab12_Bezkrovna::GetHeight() const {return height;}
double ClassLab12_Bezkrovna::GetRadius() const {return radius;}
string ClassLab12_Bezkrovna::GetColor() const {return color;}

void ClassLab12_Bezkrovna::SetHeight(double input_height)
{
    if (input_height <= 0)
    {
        cerr << "Помилка!" << endl;
        return;
    }
    height = input_height;
}

void ClassLab12_Bezkrovna::SetRadius(double input_radius)
{
    if (input_radius <= 0)
    {
        cerr << "Помилка!" << endl;
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
