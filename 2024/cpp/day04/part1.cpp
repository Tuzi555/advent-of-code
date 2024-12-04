//
// Created by Jakub Tuzar on 04.12.2024.
//

#include "part1.h"

#include "point.h"

#include <iomanip>
#include <iostream>
#include <vector>


void solvePart1(const std::vector<std::vector<char> > &charGrid) {
    int xmasCount{0};
    std::vector<point> xs{};
    point directions[8] = {
        {1, 0},
        {1, 1},
        {0, 1},
        {-1, 1},
        {-1, 0},
        {-1, -1},
        {0, -1},
        {1, -1}
    };
    constexpr char searchSequence[4] = {'X', 'M', 'A', 'S'};
    //find all xs (starting position for word xmas)
    for (int i = 0; i < charGrid.size(); ++i) {
        for (int j = 0; j < charGrid.at(i).size(); ++j) {
            if (charGrid.at(i).at(j) == searchSequence[0]) {
                xs.push_back({i, j});
            }
        }
    }

    //for each x try every direction to find consequent characters until word xmas is complete or until an invalid char is found
    //if the word xmas was completed, increment the count
    for (point startingX: xs) {
        for (point direction: directions) {
            bool wrongCharEncountered{false};
            for (int i = 1; i < std::ranges::size(searchSequence); ++i) {
                point searchLocation{startingX.x + i * direction.x, startingX.y + i * direction.y};
                char foundChar{};
                try {
                    foundChar = charGrid.at(searchLocation.x).at(searchLocation.y);
                } catch (const std::out_of_range &_) {
                    wrongCharEncountered = true;
                    break;
                }
                if (foundChar != searchSequence[i]) {
                    wrongCharEncountered = true;
                    break;
                }
            }
            if (!wrongCharEncountered) {
                ++xmasCount;
            }
        }
    }
    std::cout << std::left;
    std::cout << std::setw(30) << "First part: " << xmasCount << "\n";
}
