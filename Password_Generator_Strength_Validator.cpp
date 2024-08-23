#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <algorithm> // For count_if

using namespace std;
string generatePassword(int length) {
    string password = ""; // To store the generated password
    string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789~`! @#$%^&*"; // Characters set
    int charSize = characters.size();
    srand(static_cast<unsigned int>(time(0))); 

    for (int i = 0; i < length; ++i) {
        int randomIndex = rand() % charSize; // Get a random index
        password += characters[randomIndex]; // Append the corresponding character
    }

    return password;
}

string evaluatePasswordStrength(const string& password) {
    bool hasLower = any_of(password.begin(), password.end(), ::islower);
    bool hasUpper = any_of(password.begin(), password.end(), ::isupper);
    bool hasDigit = any_of(password.begin(), password.end(), ::isdigit);
    bool hasSpecial = any_of(password.begin(), password.end(), [](char c){ return ispunct(c); });

    int strengthScore = hasLower + hasUpper + hasDigit + hasSpecial;

    if (strengthScore == 4 && password.length() >= 12) {
        return "Strong";
    } else if (strengthScore >= 3 && password.length() >= 8) {
        return "Moderate";
    } else {
        return "Weak";
    }

}

int main() {
    int length;

    // Prompt user for the password length with input validation
    do {
        cout << "Enter the length of the password (minimum 6 characters): ";
        cin >> length;
        if (length < 6) {
            cout << "Password length must be at least 6 characters. Please try again." << endl;
        }
    } while (length < 6);

    // Generate the password
    string password = generatePassword(length);

    // Evaluate password strength
    string strength = evaluatePasswordStrength(password);

    // Display the password and its strength
    cout << "Generated Password: " << password << endl;
    cout << "Password Strength: " << strength << endl;

    return 0;
}