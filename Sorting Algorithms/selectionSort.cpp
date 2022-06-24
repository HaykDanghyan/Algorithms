#include <iostream>
#include <vector>

template <typename T>
void selectionSort(std::vector<T>&);

int main() {
    size_t size;
    std::cout << "Enter the size of your array : ";
    std::cin >> size;
    std::vector<int> vec(size);
    for(int i = 0; i < vec.size(); ++i) {
        std::cout << "Enter the #" << i + 1 << " element : ";
        std::cin >> vec[i];
    }
    selectionSort(vec);
    for(auto i : vec) {
        std::cout << i << "  ";
    }
    std::cout << std::endl;
    return 0;
}

template <typename T>
void selectionSort(std::vector<T>& vec) {
    T val{};
    int low{};
    for(int i = 0; i < vec.size() - 1; ++i) {
        low = i;
        for(int j = i + 1; j < vec.size(); ++j) {
            if(vec[j] < vec[low]) {
                low = j;
            }
        }
        val = vec[low];
        vec[low] = vec[i];
        vec[i] = val;
    }
 
}