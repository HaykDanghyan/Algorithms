#include <iostream>
#include <vector>

template <typename T>
void insertionSort(std::vector<T>&);

int main() {
    
    size_t size{};
    std::cout << "Enter the size of your array : ";
    std::cin >> size;
    std::vector<int> vec(size);
    for(int i = 0; i < vec.size(); ++i) {
        std::cout << "Enter the #" << i + 1 << " element : ";
        std::cin >> vec[i];
    }
    insertionSort(vec);
    for(auto i : vec) {
        std::cout << i << "  ";
    }
    std::cout << std::endl;
    return 0;

}

template <typename T>
void insertionSort(std::vector<T>& vec) {
    for(int i = 1; i < vec.size(); ++i) {
        T key = vec[i];
        int j = i - 1;
        while(j >= 0 and vec[j] > key) {
            vec[j + 1] = vec[j];
            j -= 1;
        }
        vec[j + 1] = key;
    }
}
