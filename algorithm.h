#ifndef ALGORITHM
#define ALGORITHM

void sumCheck(std::vector<int>&,int);
void merge_sort(std::vector<int>& list, int p, int r);
void bubble_sort(std::vector<int>& vec);
void InsertionSort(std::vector<int>& v);
int binary_search(const std::vector<int>& arr, int target);

enum algo {
    INSERTION,
    MERGE,
    BUBBLE,
    BINARY,
    SUM
};

#endif 