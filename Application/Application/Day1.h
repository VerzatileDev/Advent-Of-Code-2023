#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

class Day1 {
public:
    void processFile(const std::string& filePath);
    int extractNumbers(const std::string& line);

private:
    int globalSum = 0;
};