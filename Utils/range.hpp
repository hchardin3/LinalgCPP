#include <stdexcept>
#include <vector>

struct Range {
    int start;
    int end;
    Range(int start, int end) : start(start), end(end) {}
};

struct All {
    // Represents the entire row or column
};
