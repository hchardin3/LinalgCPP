#pragma once

#include <iostream>
#include <utility>
#include <vector>
#include <type_traits>
#include <cmath>
#include "../Utils/range.hpp"
#include "../Utils/types.hpp"

template<typename T, int Rows, int Cols>
class Matrix {
    protected:
        std::vector<T> data;
        int actual_rows;
        int actual_cols;
    
    public:
        static constexpr int num_rows = Rows;
        static constexpr int num_cols = Cols;

    // Constructors
    Matrix();

    Matrix(int rows, int cols);
    
    static Matrix Zero(int rows = Rows, int cols = Cols);

    static Matrix One(int rows = Rows, int cols = Cols);

    // Accessors
    T& operator()(int i, int j);
    const T& operator()(int i, int j) const;

    // Matrix<T> operator()(All, int j) const;
    // Matrix<T> operator()(int i, All) const;

    // Matrix<T> operator()(Range row_range, Range col_range) const;
    // Matrix<T> operator()(Range row_range, int j) const;
    // Matrix<T> operator()(int i, Range col_range) const;

    Matrix<T, Rows, 1> row(int i) const;

    Matrix<T, 1, Cols> col(int j) const;

    // Operators
    Matrix operator+(const Matrix& other) const;

    Matrix operator-(const Matrix& other) const;

    Matrix& operator+=(const Matrix& other);

    Matrix& operator-=(const Matrix& other);

    Matrix operator*(const T& scalar) const;

    Matrix operator/(const T& scalar) const;

    Matrix& operator*=(const T& scalar);

    Matrix& operator/=(const T& scalar);

    template<int OtherRows, int OtherCols>
    Matrix<T, Rows, OtherCols> operator*(const Matrix<T, OtherRows, OtherCols>& other) const;

    template<int OtherRows, int OtherCols>
    Matrix<T, Rows, OtherCols> operator*=(const Matrix<T, OtherRows, OtherCols>& other);

    // Conversion operator for Matrix<T, 1, 1> to T
    operator T() const;

    // Other functions
    const std::pair<const int, const int> shape() const;

    Matrix<T, Cols, Rows> transpose() const;

    template<int NewRows, int NewCols>
    Matrix<T, NewRows, NewCols> reshape(int new_rows, int new_cols) const;

    Matrix<T, 1, Rows * Cols> flatten() const;

    // Norm methods
    T norm(NormType type = NormType::L2) const;

    Matrix normalize() const;

    // Display
    void display() const;
    
};

#include "matrix.inl"

// Custom matrix types
using MatrixXd = Matrix<double, DynamicSize, DynamicSize>;
using Matrixi = Matrix<int, DynamicSize, DynamicSize>;
using Matrixf = Matrix<float, DynamicSize, DynamicSize>;