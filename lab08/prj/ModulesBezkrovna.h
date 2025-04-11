#ifndef S_CALCULATION
#define S_CALCULATION

using namespace std;
#include <string>

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

#endif
