#pragma once

#include "../LinalgCPP.hpp"
#include <iostream>
#include <utility>
#include <vector>
#include <type_traits>
#include "range.hpp"

template <typename T>
class Vector2 : public VectorX<T, 2> {
    public:
    // Constructor that initializes the base class with size 2
    Vector2();

    Vector2(const T& x, const T& y);

    // Access x, y directly
    T& x() { return this->data[0]; }
    const T& x() const { return this->data[0]; }

    T& y() { return this->data[1]; }
    const T& y() const { return this->data[1]; }

    // Functions
    T angle(const Vector2<T>& other) const;

    Vector2<T> rotate(T angle) const;

};