#include "part1.h"

#include <fstream>
#include <iostream>

#include "part2.h"


int main() {
    //load data into 2d vector
    std::ifstream file("../input.txt");
    std::vector<std::vector<char> > charGrid{};
    std::string line{};
    while (std::getline(file, line)) {
        std::vector chars(line.begin(), line.end());
        charGrid.push_back(chars);
    }

    solvePart1(charGrid);
    solvePart2(charGrid);

    return 0;
}
