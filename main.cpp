#include <iostream>
#include "algo-analysis.h"
int main(){
  const char TEST_CASE[] = "test_cases";
  const char OUTPUT_FILE[] = "results.csv";
  int n = 0, alg;
  std::cout <<"1.Insertion Sort\n2.Merge Sort\n3.Bubble Sort\n4.Binary Search\n5.Sum Check"<< std::endl;
  std::cout << "Enter algorithm #: ";
  std::cin >> alg;
  std::cout << "Enter number of test cases to be generated: ";
  std::cin >> n;
  std::cout << "Generating test cases..."<<std::endl;
  test_case_generator(TEST_CASE,n);
  std::cout << "Making .csv file..." <<std::endl;
  makeCSV(OUTPUT_FILE,TEST_CASE,n,alg-1);
  std::cout << "Done!" << std::endl;  
  return 0;
}
