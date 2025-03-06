#include <iostream>
#include <vector>
#include <numeric>

int main() {
    std::vector<int> numbers;
    int num;

    std::cout << "Enter integers (end with non-integer input): ";
    while (std::cin >> num) {
        numbers.push_back(num);
    }

    std::cout << "Numbers entered: ";
    for (auto it = numbers.begin(); it != numbers.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    int even_sum = 0;
    for (auto it = numbers.begin(); it != numbers.end(); ++it) {
        if (*it % 2 == 0) {
            even_sum += *it;
        }
    }

    std::cout << "Sum of even numbers: " << even_sum << std::endl;

    return 0;
}
