#include <vector>
#include <climits>

int binary_search(const std::vector<int>& arr, int target){
  int beg = 0,end = arr.size() - 1;
  while(beg <= end){
    int mid = (beg + end)/2;
    if(arr[mid] == target){
      return mid;
    }
    if(arr[mid] > target)
      beg = mid + 1;
    if(arr[mid] < target)
      end = mid - 1;
  }
  return -1; // couldn't find the element

}


void InsertionSort(std::vector<int>& v){
    for(int j = 1; j < v.size(); ++j){
        int key = v[j];
        int i = j - 1;
        while((i > -1) && (v[i] > key)){
            v[i+1] = v[i];
            --i;
        }
        v[i+1] = key;
    }
}


void merge(std::vector<int>& list, int p, int q, int r){
  int n1 = q - p + 1;
  int n2 = r - q;

  std::vector<int> L(n1 + 1);
  std::vector<int> R(n2 + 1);

  L[n1] = INT_MAX;
  R[n2] = INT_MAX;

  for(int i = 0 ; i < n1; ++i)
    L[i] = list[p + i];
  for(int i = 0; i < n2; ++i)
    R[i] = list[q + i + 1];

  int i = 0;
  int j = 0;

  for(int k = p; k <= r; ++k){
    if(L[i] <= R[j])
      list[k] = L[i++];
    else
      list[k] = R[j++];
  }
}

void bubble_sort(std::vector<int>& vec){
  for(int i = 0; i < vec.size() - 1; ++i){
     for (int j = 0; j < vec.size() - i - 1; ++j){
            if (vec[j] > vec[j+1]){
                vec[j]^=vec[j+1];
                vec[j+1]^=vec[j];
                vec[j]^=vec[j+1];
            }
        }
    }

}

void merge_sort(std::vector<int>& list, int p, int r){
  if(p < r){
    int mid = (p + r)/2;
    merge_sort(list,p,mid);
    merge_sort(list,mid + 1,r);
    merge(list,p,mid,r);
  }
}

void sumCheck(std::vector<int>& vec, int sum){
  merge_sort(vec,0,vec.size()-1);
  for(int i = 0; i < vec.size() - 1; ++i){
    int beg = i + 1;
    int end = vec.size() - 1;
    while(beg <= end){
      int mid = (beg + end)/2;
      if(sum == (vec[i] + vec[mid])){
       //std::cout << "Pair (" << vec[i]<<","<<vec[mid]<<") found."<< std::endl;
       return;
      }
      if(sum < (vec[i] + vec[mid]))
        end = mid - 1;
      if(sum > (vec[i] + vec[mid]))
        beg = mid + 1;
    }
  }
  //std::cout << "No such pair found." << std::endl;
}

