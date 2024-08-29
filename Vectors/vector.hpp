#pragma once

#include <iostream>
#include <utility>
#include <vector>
#include <type_traits>
#include "../Matrices/matrix.hpp"
#include "../Utils/range.hpp"
#include "../Utils/types.hpp"
#include "row_vector.hpp"

template<typename T, int Size = DynamicSize>
class RowVector; 

template <typename T, int Size>
class Vector : public Matrix<T, Size, 1> {
public:
    // Constructor
    Vector();

    Vector(int size);

    Vector(const Matrix<T, Size, 1>& mat);

    // Unit vector function
    Vector Zero(int size = Size);

    Vector One(int size = Size);

    Vector Unit(int size = Size, int direction = 0);

    // Operators
    Vector operator+(const Vector& other) const;
    Vector operator-(const Vector& other) const;
    Vector operator*(const T& scalar) const;
    Vector operator/(const T& scalar) const;

    // Overloading the +=, -=, *=, /= operators
    Vector& operator+=(const Vector& other);
    Vector& operator-=(const Vector& other);
    Vector& operator*=(const T& scalar);
    Vector& operator/=(const T& scalar);

    // Overloading the [] operator
    T& operator[](int i);

    const T& operator[](int i) const;

    // Overloading the () operator
    T& operator()(int i);

    const T& operator()(int i) const;

    // Transpose Method
    RowVector<T, Size> transpose() const;

    // Additional vector-specific methods can be added here
    T dot(const Vector& other) const;
};

#include "vector.inl"

// Custom vector types
using VectorXf = Vector<float, DynamicSize>;
using VectorXd = Vector<double, DynamicSize>;
using VectorXi = Vector<int, DynamicSize>;
