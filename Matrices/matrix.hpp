#pragma once

#include "../LinalgCPP.hpp"
#include <iostream>
#include <utility>
#include <vector>
#include <type_traits>
#include <limits>
#include "range.hpp"

enum class NormType {
    L1 = 1,
    L2 = 2,
    // Add more norms as needed
    Inf = std::numeric_limits<int>::max()  // Representing infinity norm
};

constexpr int DynamicSize = -1;

template<typename T, int Rows, int Cols>
class MatrixX {
    protected:
        std::vector<T> data;
        int actual_rows;
        int actual_cols;
    
    public:
        static constexpr int num_rows = Rows;
        static constexpr int num_cols = Cols;

    // Constructors
    MatrixX();

    static MatrixX Zero();

    static MatrixX One();

    // Accessors
    T& operator()(int i, int j);
    const T& operator()(int i, int j) const;

    // MatrixX<T> operator()(All, int j) const;
    // MatrixX<T> operator()(int i, All) const;

    // MatrixX<T> operator()(Range row_range, Range col_range) const;
    // MatrixX<T> operator()(Range row_range, int j) const;
    // MatrixX<T> operator()(int i, Range col_range) const;

    MatrixX<T, Rows, 1> row(int i) const;

    MatrixX<T, 1, Cols> col(int j) const;

    // Operators
    MatrixX operator+(const MatrixX& other) const;

    MatrixX operator-(const MatrixX& other) const;

    MatrixX operator+=(const MatrixX& other);

    MatrixX operator-=(const MatrixX& other);

    MatrixX operator*(const T& scalar) const;

    MatrixX operator/(const T& scalar) const;

    MatrixX operator*=(const T& scalar);

    MatrixX operator/=(const T& scalar);

    template<int OtherRows, int OtherCols>
    MatrixX<T, Rows, OtherCols> operator*(const MatrixX<T, OtherRows, OtherCols>& other) const;

    // Other functions
    std::pair<int, int> shape() const;

    MatrixX<T, Cols, Rows> transpose() const;

    template<int NewRows, int NewCols>
    MatrixX<T, NewRows, NewCols> reshape(int NewRows, int NewCols) const;

    MatrixX<T, 1, Rows * Cols> flatten() const;

    // Norm methods

    T norm(NormType type = NormType::L2) const;

    MatrixX normalize() const;

    // Display
    void display() const;
    
};

template<int Rows, int Cols>
using MatrixXd = MatrixX<double, Rows, Cols>;

template<int Rows, int Cols>
using MatrixXi = MatrixX<int, Rows, Cols>;

template<int Rows, int Cols>
using MatrixXf = MatrixX<float, Rows, Cols>;