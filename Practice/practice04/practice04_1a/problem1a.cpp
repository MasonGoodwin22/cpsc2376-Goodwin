#include <iostream>
#include <iomanip>

using namespace std;

// Converts temperature based on the provided scale
double convertTemperature(double temp, char scale = 'F') {
    if (scale == 'F') {
        return (temp * 9.0 / 5.0) + 32;  // Celsius to Fahrenheit
    } else {
        return (temp - 32) * 5.0 / 9.0;  // Fahrenheit to Celsius
    }
}

int main() {
    int choice;
    double temperature;
    
    cout << "1. Convert Celsius to Fahrenheit\n";
    cout << "2. Convert Fahrenheit to Celsius\n";
    cout << "Choose an option: ";
    cin >> choice;

    cout << "Enter temperature: ";
    cin >> temperature;

    if (choice == 1) {
        cout << "Converted: " << fixed << setprecision(2) 
             << convertTemperature(temperature, 'F') << "°F\n";
    } else if (choice == 2) {
        cout << "Converted: " << fixed << setprecision(2) 
             << convertTemperature(temperature, 'C') << "°C\n";
    } else {
        cout << "Invalid choice.\n";
    }

    return 0;
}
