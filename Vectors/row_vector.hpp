#pragma once

#include <iostream>
#include <utility>
#include <vector>
#include <type_traits>
#include "../Matrices/matrix.hpp"
#include "../Utils/range.hpp"
#include "../Utils/types.hpp"
#include "vector.hpp" 

template<typename T, int Size = DynamicSize>
class Vector; 

template <typename T, int Size>
class RowVector : public Matrix<T, 1, Size> {
public:
    // Constructor
    RowVector();

    RowVector(int size);

    RowVector(const Matrix<T, 1, Size>& other);

    // Unit vector function
    static RowVector Zero(int n);
    static RowVector One(int n);
    static RowVector Unit(int n);

    // Operators
    RowVector operator+(const RowVector& other) const;
    RowVector operator-(const RowVector& other) const;
    RowVector operator*(const T& scalar) const;
    RowVector operator/(const T& scalar) const;

    template<int N>
    RowVector<T, N> operator*(const Matrix<T, Size, N>& other) const;

    T operator*(const Vector<T, Size>& other) const;

    RowVector& operator+=(const RowVector& other);
    RowVector& operator-=(const RowVector& other);
    RowVector& operator*=(const T& scalar);
    RowVector& operator/=(const T& scalar);



    // Overloading the [] operator
    T& operator[](int i);

    const T& operator[](int i) const;

    // Overloading the () operator
    T& operator()(int i);

    const T& operator()(int i) const;

    // Transpose Method
    Vector<T, Size> transpose() const;

    // Additional vector-specific methods can be added here
    T dot(const RowVector& other) const;
};

#include "row_vector.inl"

// Custom vector types
using RowVectorXf = RowVector<float, DynamicSize>;
using RowVectorXd = RowVector<double, DynamicSize>;
using RowVectorXi = RowVector<int, DynamicSize>;
