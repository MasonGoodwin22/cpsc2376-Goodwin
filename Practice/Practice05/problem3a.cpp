#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main() {
    std::vector<int> numbers;
    int num;

    std::cout << "Enter integers (end with non-integer input): ";
    while (std::cin >> num) {
        numbers.push_back(num);
    }

    if (numbers.empty()) {
        std::cout << "No numbers entered." << std::endl;
        return 0;
    }

    std::cout << "Squared numbers: ";
    std::for_each(numbers.begin(), numbers.end(), [](int x) {
        std::cout << (x * x) << " ";
    });
    std::cout << std::endl;

    int sum_of_squares = std::accumulate(numbers.begin(), numbers.end(), 0, [](int acc, int x) {
        return acc + (x * x);
    });

    std::cout << "Sum of squared values: " << sum_of_squares << std::endl;

    return 0;
}
