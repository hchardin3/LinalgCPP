#pragma once

#include <cmath>
#include "square_matrix.hpp"
#include "../Vectors/vector3.hpp"

template<typename T>
class Matrix3 : public MatrixS<T, 3> {
public:
    // Constructors
    Matrix3();
    Matrix3(const Matrix<T, 3, 3>& m);

    Matrix3(const MatrixS<T, 3>& m);

    // Generation methods
    static Matrix3 Zero();

    static Matrix3 One();

    static Matrix3 Identity();

    // Static methods to create 3x3 rotation matrices
    static Matrix3<T> RotationX(T angle_in_radians);
    static Matrix3<T> RotationY(T angle_in_radians);
    static Matrix3<T> RotationZ(T angle_in_radians);

    // Additional 3x3 specific methods can be added here
    Matrix3 inverse() const;
};

#include "matrix3.inl"

// Alias templates for common 3x3 matrix types
using Matrix3d = Matrix3<double>;
using Matrix3i = Matrix3<int>;
using Matrix3f = Matrix3<float>;
