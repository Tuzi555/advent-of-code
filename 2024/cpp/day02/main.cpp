#include "analyzer.h"

#include <fstream>
#include <iomanip>
#include <sstream>
#include <string>
#include <iostream>
#include <vector>


int main() {
    //read file
    std::ifstream file("../input.txt");
    std::string line{};
    std::vector<std::vector<int> > reports{};
    while (std::getline(file, line)) {
        std::vector<int> lineVec{};
        std::istringstream iss(line);
        int num{};
        while (iss >> num) {
            lineVec.push_back(num);
        }
        reports.push_back(lineVec);
    }

    int safeLines1{0};
    for (const auto &report: reports) {
        if (isReportSafe(report)) ++safeLines1;
    }
    //iterate over each line and determine if the difference is always less than 3 and if it is only ascendig or descendig (no changes on one line allowed)
    std::cout << std::left;
    std::cout << std::setw(30) << "First part: " << safeLines1 << std::endl;

    int safeLines2{0};
    for (const auto &report: reports) {
        if (isReportSafe(report)) {
            ++safeLines2;
            continue;
        }

        bool anySafe{false};
        for (int i = 0; i < report.size(); ++i) {
            std::vector<int> subVec = report;
            subVec.erase(subVec.begin() + i);
            if (isReportSafe(subVec)) {
                anySafe = true;
                break;
            }
        }
        if (anySafe) ++safeLines2;
    }
    //iterate over each line and determine if the difference is always less than 3 and if it is only ascendig or descendig (no changes on one line allowed)
    std::cout << std::setw(30) << "Second part: " << safeLines2 << std::endl;
}
