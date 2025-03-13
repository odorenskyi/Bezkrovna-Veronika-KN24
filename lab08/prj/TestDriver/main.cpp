#include <iostream>
#include <iomanip>
#include <locale>
#include <windows.h>
#include <cmath>
#include "ModulesBezkrovna.h"

using namespace std;

void test_s_calculation(void)
{
    float e[6] = {-20.58, 35.98, 407.97, 123.95, 564, -1724.02};
    float n[6] = {2, 6, 4, 10, 8, 1};
    float m[6] = {3, 4, -7, 2, 5, 12};
    short i;
    float result;
    for (i=0; i<6; i++)
    {
        result = s_calculation(n[i],m[i]);
        result = round(result * 100) / 100.0;
        if (result == e[i])
            printf ("Test case #%02d PASSED.\n", i+1);
        else printf("Test case #%02d FAILED.\n", i+1);
    }
}

int main()
{
    test_s_calculation();
    return 0;
}
