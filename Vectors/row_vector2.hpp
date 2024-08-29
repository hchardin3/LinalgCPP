#pragma once

#include <iostream>
#include <utility>
#include <vector>
#include <type_traits>
#include "row_vector.hpp"
#include "vector2.hpp"
#include "matrix2.hpp"
#include "matrix.hpp"

template <typename T>
class RowVector2 : public RowVector<T, 2> {
    public:
    // Constructor that initializes the base class with size 2
    RowVector2();

    RowVector2(const RowVector<T, 2>& other);

    RowVector2(const T& x, const T& y);

    // Special constructors
    RowVector2 Zero();

    RowVector2 One();
    RowVector2 Unit(int direction);

    // Operators
    RowVector2 operator+(const RowVector2& other) const;
    RowVector2 operator-(const RowVector2& other) const;
    RowVector2 operator*(const T& scalar) const;
    RowVector2 operator/(const T& scalar) const;

    RowVector2& operator+=(const RowVector2& other);
    RowVector2& operator-=(const RowVector2& other);
    RowVector2& operator*=(const T& scalar);
    RowVector2& operator/=(const T& scalar);

    RowVector2 operator*(const Matrix2<T>& matrix) const;

    // Access x, y directly
    T& x() { return this->data[0]; }
    const T& x() const { return this->data[0]; }

    T& y() { return this->data[1]; }
    const T& y() const { return this->data[1]; }

    // Functions
    T angle(const RowVector2<T>& other) const;

    RowVector2<T> rotate(T angle) const;

    // Transpose Method
    Vector2<T> transpose() const override;

};

#include "row_vector2.inl"

// Custom vector types
using RowVector2f = RowVector2<float>;
using RowVector2d = RowVector2<double>;
using RowVector2i = RowVector2<int>;