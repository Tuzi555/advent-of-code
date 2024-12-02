//
// Created by jakub on 12/2/2024.
//

#include "analyzer.h"

#include "trend.h"

#include <cmath>

bool isReportSafe(const std::vector<int> &report) {
    bool unsafe{false};
    int prevNum{-1};
    Trend t{Unset};
    //loop through all numbers
    for (int i = 0; i < report.size(); ++i) {
        const int num{report[i]};
        //first number does not affect safety
        if (prevNum == -1) {
            prevNum = num;
            continue;
        }
        int diff = prevNum - num;
        //diff greater than 3 is unsafe
        if (std::abs(diff) > 3) {
            unsafe = true;
            break;
        }
        if (t == Unset) {
            //if the trend is not determined by the second number it mean it is a duplicate of the first which is unsafe
            if (i > 1) {
                unsafe = true;
                break;
            }
            //determine the trend
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

    return !unsafe;
}
