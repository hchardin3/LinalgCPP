#pragma once

#include <cmath>
#include "square_matrix.hpp"
#include "../Vectors/vector2.hpp"

template<typename T>
class Matrix2 : public MatrixS<T, 2> {
public:
    // Constructors
    Matrix2();
    Matrix2(const Matrix<T, 2, 2>& m);

    Matrix2(const MatrixS<T, 2>& m);

    static Matrix2 Zero();

    static Matrix2 One();

    static Matrix2 Identity();

    // Static method to create a 2x2 rotation matrix
    static Matrix2<T> Rotation(T angle_in_radians);

    // Additional 2x2 specific methods can be added here
    Matrix2 inverse() const;
};

#include "matrix2.inl"

// Alias templates for common 2x2 matrix types
using Matrix2d = Matrix2<double>;
using Matrix2i = Matrix2<int>;
using Matrix2f = Matrix2<float>;
