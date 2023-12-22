#include "Day1.h"

void Day1::processFile(const std::string& filePath) {
    std::ifstream file(filePath);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            int number = extractNumbers(line);
            // Use 'number' as needed, for example, you can accumulate it to the global sum
            globalSum += number;
            // Debug: Show each new addition to the global sum
            std::cout << "Current Number: " << number << " | Global Sum: " << globalSum << std::endl;

        }
        file.close();
    }
    else {
        std::cerr << "Unable to open file: " << filePath << std::endl;
    }

    // Debug: Show the global sum after processing the file
    std::cout << "Global Sum: " << globalSum << std::endl;
}

int Day1::extractNumbers(const std::string& line) {
    int firstDigit = -1;
    int lastDigit = -1;

    for (char c : line) {
        if (isdigit(c)) {
            // If the first digit is not found yet, set it as the first digit
            if (firstDigit == -1) {
                firstDigit = c - '0';
            }
            // Update the last digit with the current digit
            lastDigit = c - '0';
        }
    }

    // Debug: Show the line, its first and last digits, and the current number
    if (firstDigit != -1 && lastDigit != -1) {
        std::cout << "Line: " << line << " First Digit: " << firstDigit << " Last Digit: " << lastDigit << " Current Number: " << firstDigit * 10 + lastDigit << std::endl;
        // Return the current number
        return firstDigit * 10 + lastDigit;
    }
    else {
        // Return 0 if no digits are found
        return 0;
    }
}