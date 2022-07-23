#include <iostream>
#include <vector>

template <typename T>
int partition(std::vector<T>& vec, int l, int r) {
    auto pivot = vec[r];
    int i = l - 1;
    for (int j = l; j < r; ++j) {
        if (vec[j] < pivot) {
            ++i;
            std::swap(vec[i], vec[j]);
        }
    }
    std::swap(vec[i + 1], vec[r]);
    return i + 1;
}


template <typename T>
void quickSort(std::vector<T>& vec, int l, int r) {
    if (r < l) {
        return;
    }
    if (l < r) {
        int index = partition(vec, l, r);
        quickSort(vec, l, index - 1);
        quickSort(vec, index + 1, r);
    }
}

int main() {
    std::vector<int> vec;
    for (int i = 0; i < 10; ++i) {
        vec.push_back(1 + rand() % 200);
    }
    int beg = 0;
    int end = vec.size() - 1;
    quickSort(vec, beg, end);
    for (const auto& elem : vec) {
        std::cout << elem << "  ";
    }
    std::cout << std::endl;
    return 0;
}