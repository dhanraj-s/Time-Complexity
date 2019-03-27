#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <chrono>
#include "algorithm.h"

void error(const char* message){
  std::cerr << "Error: " << message << std::endl;
  exit(EXIT_FAILURE);
}

double get_execution_time(std::vector<int>& vec,int alg){
  using namespace std::chrono;

  auto start = high_resolution_clock::now();

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

  auto stop = high_resolution_clock::now();

  auto duration = duration_cast<nanoseconds> (stop - start);
  return duration.count();
}

std::vector<int> getTestCases(int n){
  std::vector<int> test_case;
  using namespace std::chrono;

  unsigned seed = steady_clock::now().time_since_epoch().count();
  std::default_random_engine e(seed);
  std::uniform_int_distribution<int> d(1, n);

  for(int i = n; i >= 1; --i)
    test_case.push_back(d(e));

  return test_case;
}

void makeCSV(const char* output_filename, int n, int alg){
  
  std::ofstream ost {output_filename};
  if(!ost) error("Couldn't create output .csv file.");
  
  ost << "Input,Time(ns)"<<std::endl;
  for(int i = 1; i <= n; ++i){
    std::vector<int> arr = getTestCases(i);
    double time = get_execution_time(arr,alg);
    ost << arr.size() << "," << time << std::endl;
  }
  
}

