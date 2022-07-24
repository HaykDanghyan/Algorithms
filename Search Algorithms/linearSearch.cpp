#include <iostream>
#include <vector>

template <typename T>
int linearSearch(const std::vector<T>& vec , T key) {
    for(int i{}; i < vec.size(); ++i) {
        if(vec[i] == key) {
            return i;
        }
    }
    return -1;
}

int main() {
    std::vector<double> vec {0.234, 0.123567, 234.135, 455.1347, 75.457};
    std::cout << linearSearch(vec , 75.457) << std::endl;
    return 0;
} 