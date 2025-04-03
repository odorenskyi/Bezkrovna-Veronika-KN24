#ifndef S_CALCULATION
#define S_CALCULATION

using namespace std;
#include <string>

float s_calculation (float x, float y);

string ECTS_rating (int rating);

string format_float(float value);

string week_temperature(float mon, float tue, float wed, float thu, float fri, float sat, float sun, float &week_celsius, float &week_fahrenheit);
int bits_analysis(int N);

string test_module(bool result);

#endif
