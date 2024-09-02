#pragma once

#include <iostream>
#include <utility>
#include <vector>
#include <type_traits>
#include "vector.hpp"
#include "row_vector2.hpp"

template<typename T>
class RowVector2; 

template <typename T>
class Vector2 : public Vector<T, 2> {
    public:
    // Constructor that initializes the base class with size 2
    Vector2();

    Vector2(const T& x, const T& y);

    Vector2(const Vector<T, 2>& vector);

    Vector2(const Matrix<T, 2, 1>& matrix);

    static Vector2 Zero();

    static Vector2 One();

    static Vector2 Unit(int direction);

    // Access x, y directly
    T& x() { return this->data[0]; }
    const T& x() const { return this->data[0]; }

    T& y() { return this->data[1]; }
    const T& y() const { return this->data[1]; }

    // Functions
    T angle(const Vector2<T>& other) const;

    Vector2<T> rotate(T angle) const;

    // Rewrite transpose
    RowVector2<T> transpose() const;

};

#include "vector2.inl"

// Custom vector types
using Vector2f = Vector2<float>;
using Vector2d = Vector2<double>;
using Vector2i = Vector2<int>;