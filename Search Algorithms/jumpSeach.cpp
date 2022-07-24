#include <iostream>
#include <vector>
#include <cmath>

template <typename T>
int jumpSearch(const std::vector<T>& vec, const T& target) {
	int left = 0;
	int right = sqrt(vec.size());

	while (vec[right] <= target && right < vec.size()) {
		left = right;
		right += sqrt(vec.size());

		if (right > vec.size() - 1) {
			right = vec.size();
		}
	}	
	for (int i = left; i < right; ++i) {
		if (vec[i] == target) {
			return i;
		}
	}
	return -1;
}

int main() {
	std::vector<int> vec{1, 2, 4, 5, 6, 7, 8, 12, 34, 56};
	std::cout << jumpSearch(vec, 12) << std::endl;
	return 0;
}
