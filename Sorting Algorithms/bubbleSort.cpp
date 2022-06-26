#include <iostream>
#include <vector>

template <typename T>
void bubbleSort(std::vector<T>&);

int main() {
    size_t size{};
    std::cout << "Enter the size of your array : ";
    std::cin >> size;
    std::vector<int> vec(size);
    for(int i = 0; i < vec.size(); ++i) {
        std::cout << "Enter the #" << i + 1 << " element : ";
        std::cin >> vec[i];
    }
    bubbleSort(vec);
    std::cout << "Sorted array : ";
    for(auto i : vec) {
        std::cout << i << "  ";
    }
    std::cout << std::endl;
}

template <typename T>
void bubbleSort(std::vector<T>& vec) {
    T val{};
    bool flag = false;
    for(int i = 0; i < vec.size(); ++i) {
        for(int j = i + 1; j < vec.size(); ++j) {
            if(vec[i] > vec[j]) {
                val = vec[i];
                vec[i] = vec[j];
                vec[j] = val;
                flag = true;
            }
        }
        if(flag == false) {
            break;
        }
    }
}