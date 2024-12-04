#include <fstream>
#include <iostream>
#include <regex>
#include <sstream>

int main() {
    std::ifstream file("../input.txt");
    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string contents = buffer.str();

    std::regex pattern(R"(mul\((\d{1,3}),(\d{1,3})\))");
    auto firstPartBegin = std::sregex_iterator(contents.begin(), contents.end(), pattern);
    auto regexIteratorEnd = std::sregex_iterator();
    int sum1{0};
    for (std::sregex_iterator i = firstPartBegin; i != regexIteratorEnd; ++i) {
        const std::smatch &match = *i;
        sum1 += std::stoi(match[1].str()) * std::stoi(match[2].str());
    }

    std::cout << std::left;
    std::cout << std::setw(30) << "First part: " << sum1 << std::endl;

    bool mulEnabled{true};
    std::regex extendedPattern(R"((mul\((\d{1,3}),(\d{1,3})\))|(do\(\))|(don't\(\)))");
    auto secondPartBegin = std::sregex_iterator(contents.begin(), contents.end(), extendedPattern);

    int sum2{0};
    for (std::sregex_iterator i = secondPartBegin; i != regexIteratorEnd; ++i) {
        const std::smatch &match = *i;
        const std::string debugMatch = match.str();
        //check if mulEnabled should change
        if (match[4].matched) {
            mulEnabled = true;
            continue;
        }
        if (match[5].matched) {
            mulEnabled = false;
            continue;
        }
        if (mulEnabled && match[1].matched) {
            sum2 += std::stoi(match[2].str()) * std::stoi(match[3].str());
        }
    }
    std::cout << std::setw(30) << "Second part: " << sum2 << std::endl;
}
