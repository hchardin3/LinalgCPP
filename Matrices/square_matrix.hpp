#pragma once

#include <iostream>
#include <utility>
#include <vector>
#include <type_traits>
#include "matrix.hpp"

template<typename T, int Size>
class MatrixS : public Matrix<T, Size, Size> {
public:
    // Constructors
    MatrixS();
    MatrixS(const Matrix<T, Size, Size>& m);

    MatrixS(int size);

    static MatrixS<T, Size> Zero(int size);

    static MatrixS<T, Size> One(int size);

    static MatrixS Identity(int size);

    // Class methods
    T trace() const;

    MatrixS<T, Size> power(int n) const;

    T determinant() const;

    MatrixS<T, Size> inverse() const;
};

#include "square_matrix.inl"

// Alias templates for common matrix types
using MatrixSd = MatrixS<double, DynamicSize>;
using MatrixSi = MatrixS<int, DynamicSize>;
using MatrixSf = MatrixS<float, DynamicSize>;