#pragma once

#include <iostream>
#include <utility>
#include <vector>
#include <type_traits>
#include "vector.hpp"
#include "row_vector3.hpp"

template<typename T>
class RowVector3; 

template <typename T>
class Vector3 : public Vector<T, 3> {
    public:
    // Constructor
    Vector3();
    
    Vector3(const T& x, const T& y, const T& z);

    Vector3(const Vector<T, 3>& vector);

    static Vector3 Zero();

    static Vector3 One();

    static Vector3 Unit(int direction);

    // Access x, y, z directly
    T& x() { return this->data[0]; }
    const T& x() const { return this->data[0]; }

    T& y() { return this->data[1]; }
    const T& y() const { return this->data[1]; }

    T& z() { return this->data[2]; }
    const T& z() const { return this->data[2]; }

    // Specific utils
    Vector3<T> cross(const Vector3<T>& other) const;

    // Rewrite transpose
    RowVector3<T> transpose() const;
};

#include "vector3.inl" // Include implementation here, at the end of the header

// Custom vector types
using Vector3f = Vector3<float>;
using Vector3d = Vector3<double>;
using Vector3i = Vector3<int>;