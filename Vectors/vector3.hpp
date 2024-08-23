#pragma once

#include "../LinalgCPP.hpp"
#include <iostream>
#include <utility>
#include <vector>
#include <type_traits>
#include "range.hpp"

template <typename T>
class Vector3 : public VectorX<T, 3> {
    public:
    // Constructor
    Vector3();
    
    Vector3(const T& x, const T& y, const T& z);

    // Access x, y, z directly
    T& x() { return this->data[0]; }
    const T& x() const { return this->data[0]; }

    T& y() { return this->data[1]; }
    const T& y() const { return this->data[1]; }

    T& z() { return this->data[2]; }
    const T& z() const { return this->data[2]; }

    // Specific utils
    Vector3<T> cross(const Vector3<T>& other) const;
    

};