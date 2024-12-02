#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <map>

int main() {
    //read file
    std::ifstream file("../input.txt");
    //put first number into array 1 and second number into array 2
    std::vector<int> firstVec{};
    std::vector<int> secondVec{};
    std::string line{};
    while (std::getline(file, line)) {
        int num1;
        int num2;
        std::istringstream iss(line);
        iss >> num1 >> num2;
        firstVec.push_back(num1);
        secondVec.push_back(num2);
    }
    //sort vectors asc
    std::ranges::sort(firstVec);
    std::ranges::sort(secondVec);
    //for each element in array subtract the numbers and get the absolute values of their diff and sum them
    int sum1{0};
    for (int i = 0; i < firstVec.size(); ++i) {
        sum1 += std::abs(firstVec[i] - secondVec[i]);
    }
    std::cout << std::left;
    std::cout << std::setw(30) << "First part: " << sum1 << std::endl;

    //second part
    //iterate over first vector and check how many times the number appears in the second vector
    std::map<int, int> occurrences{};

    int sum2{0};

    for (int num1: firstVec) {
        if (auto find = occurrences.find(num1); find != occurrences.end()) {
            sum2 += find->second;
            continue;
        }
        int localSum{0};
        for (int num2: secondVec) {
            if (num1 == num2) {
                localSum += num1;
            }
        }
        occurrences.insert(std::make_pair(num1, localSum));
        sum2 += localSum;
    }

    std::cout << std::setw(30) << "Second part: " << sum2 << std::endl;

    return 0;
}
