#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <locale>
#include <windows.h>
#include "ModulesBezkrovna.h"

using namespace std;

int main()
{
    SetConsoleCP(866);
    SetConsoleOutputCP(866);
    setlocale (LC_CTYPE, "ukr");

    string exp_result_1_1 = "text_files\\expected_results\\for_10_1\\10_1_1.txt";
    string exp_result_1_2 = "text_files\\expected_results\\for_10_1\\10_1_2.txt";
    string exp_result_1_3 = "text_files\\expected_results\\for_10_1\\10_1_3_output.txt";
    string exp_result_1_4 = "text_files\\expected_results\\for_10_1\\10_1_3_input.txt";
    string exp_result_1_5 = "text_files\\expected_results\\for_10_1\\10_1_4.txt";

    string exp_result_2_1 = "text_files\\expected_results\\for_10_2\\10_2_1.txt";
    string exp_result_2_2 = "text_files\\expected_results\\for_10_2\\10_2_2.txt";
    string exp_result_2_3 = "text_files\\expected_results\\for_10_2\\10_2_3.txt";

    string exp_result_3_1 = "text_files\\expected_results\\for_10_3\\10_3_1.txt";
    string exp_result_3_2 = "text_files\\expected_results\\for_10_3\\10_3_2.txt";
    string exp_result_3_3 = "text_files\\expected_results\\for_10_3\\10_3_3.txt";

    string input_1_1 = "text_files\\input\\for_10_1\\input_1.txt";
    string input_1_2 = "text_files\\input\\for_10_1\\input_2.txt";
    string input_1_3 = "text_files\\input\\for_10_1\\input_3.txt";
    string input_1_4 = "text_files\\input\\for_10_1\\input_4.txt";

    string input_2_1 = "text_files\\input\\for_10_2\\input_1.txt";
    string input_2_2 = "text_files\\input\\for_10_2\\input_2.txt";
    string input_2_3 = "text_files\\input\\for_10_2\\input_3.txt";

    string input_3_1 = "text_files\\input\\for_10_3\\input_1.txt";
    string input_3_2 = "text_files\\input\\for_10_3\\input_2.txt";
    string input_3_3 = "text_files\\input\\for_10_3\\input_3.txt";

    float x[] = {3, 4 ,7};
    float y[] = {4, 10, 3};
    int b[] = {3, 11, 675};

    vector<string> test_res_1 = test_results_10_1(exp_result_1_1, exp_result_1_2, exp_result_1_3, exp_result_1_4, exp_result_1_5);
    vector<string> test_res_2 = test_results_10_2(exp_result_2_1, exp_result_2_2, exp_result_2_3);
    vector<string> test_res_3 = test_results(exp_result_3_1, exp_result_3_2, exp_result_3_3);

    vector<string> input_1 = input_10_1(input_1_1, input_1_2, input_1_3, input_1_4);
    vector<string> input_2 = test_results(input_2_1, input_2_2, input_2_3);
    vector<string> input_3 = test_results(input_3_1, input_3_2, input_3_3);

    string input = "text_files\\files_for_testing\\input.txt";
    string output = "text_files\\files_for_testing\\output.txt";

    ofstream test_results("text_files\\test_results\\test_results.txt");
    test_results << "For task 10_1" << endl;
    ofstream input_10_1_3_result(input);
    input_10_1_3_result << input_1[2] << endl;
    input_10_1_3_result.close();
    ifstream input_10_1_3_input(input);
    string result_input_10_1_3 = read(input);
    input_10_1_3_input.close();
    for(int i = 0; i < 2; i++)
    {
        ofstream input_10_1(input);
        input_10_1 << input_1[i] << endl;
        input_10_1.close();
        input_analysis(input, output);
        string result = read(output);
        if(result == test_res_1[i])
        {
            test_results << "Test case " << i + 1 << " PASSED" << endl;
        }
        else
        {
            test_results << "Test case " << i + 1 << " FAILED" << endl;
        }
    }
    ofstream input_10_1_3(input);
    input_10_1_3 << input_1[2] << endl;
    input_analysis(input, output);
    string result_1 = read(output);
    string result_2 = read(input);
    if((result_1 == test_res_1[2]) && (result_2 == test_res_1[3]))
    {
        test_results << "Test case 3 PASSED" << endl;
    }
    else
    {
        test_results << "Test case 3 FAILED" << endl;
    }
    input_10_1_3.close();
    ofstream input_10_1_4(input, ios::trunc);
    input_10_1_4 << input_1[3] << endl;
    input_analysis(input, output);
    string result = read(output);
    if(result == test_res_1[4])
    {
        test_results << "Test case 4 PASSED" << endl;
    }
    else
    {
        test_results << "Test case 4 FAILED" << endl;
    }
    input_10_1_4.close();

    test_results << "\nFor task 10_2" << endl;
    for(int i = 0; i < 3; i++)
    {
        ofstream input_10_2(input);
        input_10_2 << input_2[i] << endl;
        input_10_2.close();
        add_poem_with_time(input);
        string result = read(input);
        if(result == test_res_2[i])
        {
            test_results << "Test case " << i + 1 << " PASSED" << endl;
        }
        else
        {
            test_results << "Test case " << i + 1 << " FAILED" << endl;
        }
    }
    ofstream output_cleaning(output);
    output_cleaning.close();

    test_results << "\nFor task 10_3" << endl;
    for(int i = 0; i < 3; i++)
    {
        ofstream input_10_3(input);
        input_10_3 << input_3[i] << endl;
        input_10_3.close();
        add_calculation_and_bits(x[i], y[i], b[i], output);
        string result = read(output);
        if(result == test_res_3[i])
        {
            test_results << "Test case " << i + 1 << " PASSED" << endl;
        }
        else
        {
            test_results << "Test case " << i + 1 << " FAILED" << endl;
        }
    }
    cout << "Тестування закінчено. Перегляньте результати в файлі \"test_results.txt\" в директорії text_files\test_results" << endl;
    return 0;
}
