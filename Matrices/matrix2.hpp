#pragma once

#include <cmath>
#include "square_matrix.hpp"
#include "vector2.hpp"

template<typename T>
class Matrix2 : public MatrixS<T, 2> {
public:
    // Constructors
    Matrix2();
    Matrix2(const Matrix<T, 2, 2>& m);

    Matrix2 Zero() const;

    Matrix2 One() const;

    Matrix2 Identity() const;

    // Operators

    Matrix2 operator+(const Matrix2& other) const;

    Matrix2 operator-(const Matrix2& other) const;

    Matrix2 operator*(const Matrix2& other) const;

    Matrix2 operator*(T scalar) const;

    Matrix2 operator/(T scalar) const;

    Matrix2& operator+=(const Matrix2& other);

    Matrix2& operator-=(const Matrix2& other);

    Matrix2& operator*=(const Matrix2& other);

    Matrix2& operator*=(T scalar);

    Matrix2& operator/=(T scalar);

    // Vector operations
    Vector2<T> operator*(const Vector2<T>& other) const;

    // Static method to create a 2x2 rotation matrix
    static Matrix2<T> Rotation(T angle_in_radians);

    // Additional 2x2 specific methods can be added here
};

#include "matrix2.inl"

// Alias templates for common 2x2 matrix types
using Matrix2d = Matrix2<double>;
using Matrix2i = Matrix2<int>;
using Matrix2f = Matrix2<float>;
