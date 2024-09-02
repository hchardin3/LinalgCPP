#pragma once

#include <iostream>
#include <utility>
#include <vector>
#include <type_traits>
#include "row_vector.hpp"
#include "vector3.hpp"
#include "../Matrices/matrix3.hpp"

template <typename T>
class Vector3;

template <typename T>
class RowVector3 : public RowVector<T, 3> {
    public:
    // Constructor
    RowVector3();

    RowVector3(const RowVector<T, 3>& other);
    
    RowVector3(const T& x, const T& y, const T& z);

    RowVector3(const Matrix<T, 1, 3>& matrix);

    // Special constructors
    static RowVector3 Zero();

    static RowVector3 One();
    static RowVector3 Unit(int direction);

    // Access x, y, z directly
    T& x() { return this->data[0]; }
    const T& x() const { return this->data[0]; }

    T& y() { return this->data[1]; }
    const T& y() const { return this->data[1]; }

    T& z() { return this->data[2]; }
    const T& z() const { return this->data[2]; }

    // Specific utils
    RowVector3<T> cross(const RowVector3<T>& other) const;

    // Transpose Method
    Vector3<T> transpose() const;
    

};

#include "row_vector3.inl"

// Custom vector types
using RowVector3f = RowVector3<float>;
using RowVector3d = RowVector3<double>;
using RowVector3i = RowVector3<int>;