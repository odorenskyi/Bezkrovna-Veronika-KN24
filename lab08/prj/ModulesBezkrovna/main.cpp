#include <cmath>
#include <iostream>
#define _USE_MATH_DEFINES

float s_calculation (float x, float y)
{
    if ((pow(y,x) - M_PI) < 0)
    {
        std::cout << "Помилка: вираз під квадратним коренем від'ємний" << std::endl;
    }
    float S = pow(x,2) - pow(y, 3) + sqrt(pow(y,x) - M_PI);

    return S;
}


