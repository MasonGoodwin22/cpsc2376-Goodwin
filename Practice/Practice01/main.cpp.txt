#include <iostream>
#include <vector>

// Function prototypes
void printVector(const std::vector<int>& vec);
void doubleVector(std::vector<int>& vec);
int findSum(const std::vector<int>& vec);
void printMultiples(const std::vector<int>& vec, int multiple);

int main() {
    std::vector<int> numbers;
    int choice;

    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Add an item to the vector\n";
        std::cout << "2. Print the vector\n";
        std::cout << "3. Double the vector\n";
        std::cout << "4. Find the sum\n";
        std::cout << "5. Print multiples of a value\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                int num;
                std::cout << "Enter a number: ";
                std::cin >> num;
                numbers.push_back(num);
                break;
            }
            case 2:
                printVector(numbers);
                break;
            case 3:
                doubleVector(numbers);
                break;
            case 4:
                std::cout << "Sum: " << findSum(numbers) << "\n";
                break;
            case 5: {
                int multiple;
                std::cout << "Enter a multiple value: ";
                std::cin >> multiple;
                printMultiples(numbers, multiple);
                break;
            }
            case 6:
                std::cout << "Exiting program.\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}

void printVector(const std::vector<int>& vec) {
    std::cout << "Vector elements: ";
    for (size_t i = 0; i < vec.size(); i++) {
        std::cout << vec.at(i) << " ";
    }
    std::cout << "\n";
}

void doubleVector(std::vector<int>& vec) {
    for (size_t i = 0; i < vec.size(); i++) {
        vec.at(i) *= 2;
    }
    std::cout << "Vector doubled successfully.\n";
}

int findSum(const std::vector<int>& vec) {
    int sum = 0;
    for (size_t i = 0; i < vec.size(); i++) {
        sum += vec.at(i);
    }
    return sum;
}

void printMultiples(const std::vector<int>& vec, int multiple) {
    std::cout << "Multiples of " << multiple << ": ";
    for (size_t i = 0; i < vec.size(); i++) {
        if (vec.at(i) % multiple == 0) {
            std::cout << vec.at(i) << " ";
        }
    }
    std::cout << "\n";
}
