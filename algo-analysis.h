#ifndef ALGOANALYSIS
#define ALGOANALYSIS

#include<vector>
void error(const char* message);
double get_execution_time(std::vector<int>& vec);
void sumCheck(std::vector<int>& vec, int sum);
void makeCSV(const char* output_filename, int n,int alg);
std::vector<int> getTestCases(int n);

#endif 