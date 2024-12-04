//
// Created by Jakub Tuzar on 04.12.2024.
//

#include "part2.h"
#include "point.h"

#include <vector>
#include <iostream>
#include <iomanip>


void solvePart2(const std::vector<std::vector<char> > &charGrid) {
    int xmasCount{0};
    std::vector<point> anchorPoints{};
    std::tuple<point, point> pointsToCheckOffsets[2] = {
        {{1, 1}, {-1, -1}},
        {{-1, 1}, {1, -1}},
    };

    for (int i = 0; i < charGrid.size(); ++i) {
        for (int j = 0; j < charGrid.at(i).size(); ++j) {
            if (charGrid.at(i).at(j) == 'A') {
                anchorPoints.push_back({i, j});
            }
        }
    }


    for (point anchorPoint: anchorPoints) {
        bool wrongCharEncountered{false};
        for (auto [first, second]: pointsToCheckOffsets) {
            char foundChars[2]{};
            try {
                foundChars[0] = charGrid.at(anchorPoint.x + first.x).at(anchorPoint.y + first.y);
                foundChars[1] = charGrid.at(anchorPoint.x + second.x).at(anchorPoint.y + second.y);
            } catch (const std::out_of_range &_) {
                wrongCharEncountered = true;
                break;
            }
            if (foundChars[0] != 'S' && foundChars[0] != 'M') {
                wrongCharEncountered = true;
                break;
            }
            if (foundChars[1] != 'S' && foundChars[1] != 'M') {
                wrongCharEncountered = true;
                break;
            }
            if (foundChars[0] == foundChars[1]) {
                wrongCharEncountered = true;
                break;
            }
        }
        if (!wrongCharEncountered) {
            ++xmasCount;
        }
    }


    std::cout << std::left;
    std::cout << std::setw(30) << "Second part: " << xmasCount << "\n";
}
