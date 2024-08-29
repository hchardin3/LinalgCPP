#ifndef TYPES_HPP
#define TYPES_HPP

#include <limits>

enum class NormType {
    L1 = 1,
    L2 = 2,
    // Add more norms as needed
    Inf = std::numeric_limits<int>::max()  // Representing infinity norm
};

constexpr int DynamicSize = -1;

#endif // TYPES_HPP
