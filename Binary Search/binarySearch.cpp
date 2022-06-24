#include <iostream>
#include <vector>

template <typename T>
int binarySearch(const std::vector<T>&, T);
template <typename T>
void insertionSort(std::vector<T>& vec);

int main() {
    std::vector<int> vec {1 , 5, 7, 1375, 39726, 62, 98, 246, 682, 2358, 2468158};
    insertionSort(vec);
    for(auto i : vec) {
        std::cout << i << "  ";
    }
    std::cout << std::endl;
    std::cout << binarySearch(vec , 62) << std::endl;
    return 0;
}

template <typename T>
int binarySearch(const std::vector<T>& vec , T val) {
    int begin = 0;
    int end = vec.size() - 1;
    while(begin <= end) {
        int mid = begin + (end - begin) / 2;
        if(vec[mid] == val) {
            return mid;
        }
        if(vec[mid] > val) {
            end = mid - 1;
        }
        else {
            begin = mid + 1;
        }
    }
    return -1;
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