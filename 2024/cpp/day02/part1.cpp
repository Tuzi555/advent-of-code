//
// Created by jakub on 12/2/2024.
//

#include "part1.h"

#include "trend.h"

#include <cmath>


int analyzeReports(std::vector<std::vector<int> > &reports) {
    int safeLines{0};
    for (const auto &report: reports) {
        bool unsafe{false};
        int prevNum{-1};
        Trend t{Unset};
        for (int i = 0; i < report.size(); ++i) {
            const int num{report[i]};
            if (prevNum == -1) {
                prevNum = num;
                continue;
            }
            int diff = prevNum - num;
            if (std::abs(diff) > 3) {
                unsafe = true;
                break;
            }
            if (t == Unset) {
                if (i > 1) {
                    unsafe = true;
                    break;
                }
                if (diff != 0) {
                    t = diff > 0 ? Descending : Ascending;
                }
            } else {
                if (diff != 0) {
                    if (const Trend
                        newT = diff > 0 ? Descending : Ascending; newT != t) {
                        unsafe = true;
                        break;
                    }
                } else {
                    unsafe = true;
                    break;
                }
            }
            prevNum = num;
        }

        if (!unsafe) ++safeLines;
    }
    return safeLines;
}
