#pragma once

#include "debug.h"

namespace capted {

std::vector<IntPair> deepCopy(std::vector<IntPair> orig) {
    std::vector<IntPair> copy;

    for (IntPair &p : orig) {
        copy.push_back(IntPair(p.first, p.second));
    }

    return copy;
}

std::vector<std::vector<IntPair>> deepCopy(std::vector<std::vector<IntPair>> orig) {
    std::vector<std::vector<IntPair>> copy;

    for (auto m : orig) {
        copy.push_back(deepCopy(m));
    }

    return copy;
}

} // namespace capted
