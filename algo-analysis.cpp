#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <string>
#include <sstream>
#include "algorithm.h"

void error(const char* message){
  std::cerr << "Error: " << message << std::endl;
  exit(EXIT_FAILURE);
}

double get_execution_time(std::vector<int>& vec,int alg){
  clock_t t;
  double duration;
  t = clock();
  switch(alg){
    case INSERTION:
      InsertionSort(vec);
      break;
    case BINARY:
      binary_search(vec,0);
      break;
    case MERGE:
      merge_sort(vec,0,vec.size()-1);
      break;
    case BUBBLE:
      bubble_sort(vec);
      break;
    case SUM:
      sumCheck(vec,0);
      break;
  }
  t = clock() - t;
  duration = ((double)t) / CLOCKS_PER_SEC;
  return duration*1000000;
}


void test_case_generator(const char* output_filename, int n){

  std::ofstream ost {output_filename};

  if(!ost) error("Couldn't create test case file");
  
  for(int i = n; i >= 1; --i){
    for(int j = i; j >= 1; --j)
      ost << j << " ";
    ost << "\r\n";
  }

}

std::vector<int> get_input_vector(const char* input_filename, int lineno){
  
  std::ifstream ist {input_filename};
  if(!ist) error("Couldn't open input file");

  std::vector<int> arr;
  int value;
  std::string line;

  for(int i = 0; i < lineno; ++i)
    getline(ist,line);

  std::stringstream s {line};

  while(s >> value)
    arr.push_back(value);
  
  return arr;

}

void makeCSV(const char* output_filename,const char* input_filename, int n, int alg){
  
  std::ofstream ost {output_filename};
  if(!ost) error("Couldn't create output .csv file.");
  
  ost << "Input,Time(ms)"<<std::endl;
  for(int i = 0; i < n; ++i){
    std::vector<int> arr = get_input_vector(input_filename,i+1);
    double time = get_execution_time(arr,alg);
    ost << arr.size() << "," << time << std::endl;
  }
  
}

