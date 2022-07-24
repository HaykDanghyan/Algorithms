#include <iostream>
#include <vector>

template <typename T>
void insertionSort(std::vector<T>&);

template <typename T>
int binarySearchRecursive(std::vector<T>& , int, int, T);

int main() {
    std::vector<int> vec {9, 1843, 47352, 274, 751, 862, 9726};
    insertionSort(vec);
    int begin = 0;
    int end = vec.size() - 1;
    int target = 23;
    std::cout << binarySearchRecursive(vec, begin, end, target) << std::endl;
}

template <typename T>
void insertionSort(std::vector<T>& vec) {
    for(int i = 1; i < vec.size(); ++i) {
        T val = vec[i];
        int j = i - 1;
        while(j >= 0 and vec[j] > val) {
            vec[j + 1] = vec[j];
            --j;
        }
        vec[j + 1] = val;
    } 
}

template <typename T>
int binarySearchRecursive(std::vector<T>& vec, int begin, int end, T target) {
    if(begin <= end) {
        int mid = begin + (end - begin) / 2;
        if(vec[mid] == target) {
            return mid;
        }
        else if(vec[mid] < target) {
            return binarySearchRecursive(vec, mid + 1, end, target);
        } 
        else {
            return binarySearchRecursive(vec, begin, mid - 1, target);
        }
    }
    return -1;
}