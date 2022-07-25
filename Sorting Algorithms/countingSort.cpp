#include <iostream>
#include <algorithm>
#include <vector>

void countingSort(std::vector<int>& vec) {
	auto max = *std::max_element(vec.begin(), vec.end());
	auto min = *std::min_element(vec.begin(), vec.end());

	int range = max - min + 1;
	std::vector<int> count(range);
	std::vector<int> output(vec.size());

	for (int i = 0; i < vec.size(); ++i) {
		count[vec[i] - min]++;
	}
	for (int i = 1; i < count.size(); ++i) {
		count[i] += count[i - 1];
	}
	for (int i = vec.size() - 1; i >= 0; --i) {
		output[count[vec[i] - min] - 1] = vec[i];
		count[vec[i] - min]--;
	}
	for (int i = 0; i < vec.size(); ++i) {
		vec[i] = output[i];
	}
}

int main() {
	std::vector<int> vec;
	for (int i = 0; i < 10; ++i) {
		vec.push_back(1 + rand() % 200);
	}
	countingSort(vec);
	for (const auto& elem : vec) {
		std::cout << elem << "  ";
	}
	std::cout << std::endl;
	return 0;
}
