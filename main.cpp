#include <iostream>
using namespace std;

int main() {
    int number;
    cout << "Enter a four-digit number: ";
    cin >> number;

    if (number < 0 || number > 9999) {
        cout << "Please enter a valid four-digit number." << endl;
        return 1;
    }

    int digits[4];
    digits[0] = number / 1000;
    digits[1] = (number / 100) % 10;
    digits[2] = (number / 10) % 10;
    digits[3] = number % 10;

    // Printing the digits
    cout << "Individual digits are: " << endl;
    cout << "First digit: " << digits[0] << endl;
    cout << "Second digit: " << digits[1] << endl;
    cout << "Third digit: " << digits[2] << endl;
    cout << "Fourth digit: " << digits[3] << endl;

    return 0;
}