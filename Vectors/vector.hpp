#pragma once

#include "../LinalgCPP.hpp"
#include <iostream>
#include <utility>
#include <vector>
#include <type_traits>
#include "range.hpp"

template <typename T, int Size>
class VectorX : public MatrixX<T, Size, 1> {
public:
    // Constructor
    VectorX();

    // Unit vector function
    VectorX Unit(int n) const;

    // Overloading the [] operator
    T& operator[](int i);

    const T& operator[](int i) const;

    // Overloading the () operator
    T& operator()(int i);

    const T& operator()(int i) const;

    // Additional vector-specific methods can be added here
    T dot(const VectorX& other) const;
};
