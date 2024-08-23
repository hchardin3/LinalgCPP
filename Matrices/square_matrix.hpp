#pragma once

#include "../LinalgCPP.hpp"
#include <iostream>
#include <utility>
#include <vector>
#include <type_traits>
#include "range.hpp"

template<typename T, int Size>
class MatrixS : public MatrixX<T, Size, Size> {
    public:

    // Class constructors
    MatrixS();
    MatrixS(const MatrixX<T, Size, Size>& m);

    static MatrixS Identity();

    // Class methods
    T trace() const;

    MatrixS<T, Size> power(int n) const;

    T determinant() const;

    MatrixS<T, Size> inverse() const;
};

template<int Size>
using MatrixSd = MatrixS<double, Size>;

template<int Size>
using MatrixSi = MatrixS<int, Size>;

template<int Size>
using MatrixSf = MatrixS<float, Size>;