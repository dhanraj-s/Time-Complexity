#include<vector>
void error(const char* message);
void test_case_generator(const char* input_filename, int n);
std::vector<int> get_input_vector(const char* input_filename, int lineno);
void makeCSV(const char* output_filename,const char* input_filename, int n,int alg);
double get_execution_time(std::vector<int>& vec);
void sumCheck(std::vector<int>& vec, int sum);
