#pragma once

#include <iostream>
#include <utility>
#include <vector>
#include <type_traits>
#include "row_vector.hpp"
#include "vector2.hpp"
#include "../Matrices/matrix2.hpp"
#include "../Matrices/matrix.hpp"

template <typename T>
class RowVector2 : public RowVector<T, 2> {
    public:
    // Constructor that initializes the base class with size 2
    RowVector2();

    RowVector2(const RowVector<T, 2>& other);

    RowVector2(const Matrix<T, 1, 2>& other);

    RowVector2(const T& x, const T& y);

    // Special constructors
    static RowVector2 Zero();

    static RowVector2 One();
    static RowVector2 Unit(int direction);

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