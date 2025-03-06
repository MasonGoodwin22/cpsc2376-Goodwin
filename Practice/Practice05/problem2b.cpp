#include <iostream>
#include <vector>
#include <algorithm>

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

    auto max_it = std::max_element(numbers.begin(), numbers.end());
    auto min_it = std::min_element(numbers.begin(), numbers.end());

    std::cout << "Largest number: " << *max_it << std::endl;
    std::cout << "Smallest number: " << *min_it << std::endl;

    return 0;
}
