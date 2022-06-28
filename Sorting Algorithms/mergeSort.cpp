#include <iostream>
#include <vector>

template <typename T>
void mergeSort(std::vector<T>&, int, int);
template <typename T>
void merge(std::vector<T>&, int, int, int);

int main() {
    size_t size;
    std::cout << "Enter the size of your array : ";
    std::cin >> size;
    std::vector<int> vec(size);
    for(int i = 0; i < vec.size(); ++i) {
        std::cout << "Enter the " << i + 1 << " element : ";
        std::cin >> vec[i];
    }
    int begin = 0;
    int end = vec.size() - 1;
    int mid = begin + (end - begin) / 2;
    mergeSort(vec, begin, end);
    for(auto i : vec) {
        std::cout << i << "  ";
    }
    std::cout << std::endl;
}

template <typename T>
void mergeSort(std::vector<T>& vec, int begin, int end) {
    if(begin < end) {
        int mid = begin + (end - begin) / 2;
        mergeSort(vec, begin, mid);
        mergeSort(vec, mid + 1, end);
        merge(vec, begin, end, mid);
    }
} 

template <typename T>
void merge(std::vector<T>& vec, int begin, int end, int mid) {
    int leftSize = mid - begin + 1;
    int rightSize = end - mid;
    std::vector<T> leftVec(leftSize);
    std::vector<T> rightVec(rightSize);
    for(int i = 0; i < leftVec.size(); ++i) {
        leftVec[i] = vec[i + begin];
    }
    for(int j = 0; j < rightVec.size(); ++j) {
        rightVec[j] = vec[j + 1 + mid];
    }

    int n1 = 0;
    int n2 = 0;
    for(int i = begin; i <= end; ++i) {
        if(n1 < leftSize and n2 < rightSize) {
            if(leftVec[n1] < rightVec[n2]) {
                vec[i] = leftVec[n1];
                ++n1;
            } 
            else {
                vec[i] = rightVec[n2];
                ++n2;
            }
        }
        else if(!n1 < leftSize and n2 < rightSize) {
            vec[i] = rightVec[n2];
            ++n2;
        }
        else {
            vec[i] = leftVec[n1];
            ++n1;
        }
    }
}