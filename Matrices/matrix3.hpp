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
    /**
     * @brief Creates a 3x3 matrix with all elements initialized to zero.
     *
     * @return A 3x3 matrix with all elements set to zero.
     */
    static Matrix3 Zero();

    /**
     * @brief Creates a 3x3 matrix with all elements initialized to one.
     *
     * This function generates a 3x3 matrix where all elements are set to one.
     * It is useful for initializing matrices with a constant value.
     *
     * @return A 3x3 matrix with all elements set to one.
     */
    static Matrix3 One();

    /**
     * @brief Creates a 3x3 identity matrix.
     *
     * An identity matrix is a square matrix with ones on the main diagonal (top-left to bottom-right)
     * and zeros in all other positions. This function generates a 3x3 identity matrix.
     *
     * @return A 3x3 identity matrix.
     */
    static Matrix3 Identity();

    // Static methods to create 3x3 rotation matrices
    /**
     * @brief Creates a 3x3 rotation matrix around the X-axis.
     *
     * This function generates a 3x3 rotation matrix that rotates a vector around the X-axis by the given angle.
     * The angle is specified in radians.
     *
     * @param angle_in_radians The angle of rotation in radians.
     *
     * @return A 3x3 rotation matrix around the X-axis.
     *
     * @note The rotation matrix is defined as follows:
     * [1, 0, 0]
     * [0, cos(angle), -sin(angle)]
     * [0, sin(angle), cos(angle)]
     */
    static Matrix3<T> RotationX(T angle_in_radians);

    /**
     * @brief Creates a 3x3 rotation matrix around the Y-axis.//+
     *
     * This function generates a 3x3 rotation matrix that rotates a vector around the Y-axis by the given angle.//+
     * The angle is specified in radians.//+
     *
     * @param angle_in_radians The angle of rotation in radians.//+
     *
     * @return A 3x3 rotation matrix around the Y-axis.//+
     *
     * @note The rotation matrix is defined as follows://+
     * [cos(angle), 0, sin(angle)]//+
     * [0, 1, 0]//+
     * [-sin(angle), 0, cos(angle)]//+
     */
    static Matrix3<T> RotationY(T angle_in_radians);
    
    /**
     * @brief Creates a 3x3 rotation matrix around the Z-axis.
     *
     * This function generates a 3x3 rotation matrix that rotates a vector around the Z-axis by the given angle.
     * The angle is specified in radians.
     *
     * @param angle_in_radians The angle of rotation in radians.
     *
     * @return A 3x3 rotation matrix around the Z-axis.
     *
     * @note The rotation matrix is defined as follows:
     * [cos(angle), -sin(angle), 0]
     * [sin(angle), cos(angle), 0]
     * [0, 0, 1]
     */
    static Matrix3<T> RotationZ(T angle_in_radians);

    // Additional 3x3 specific methods can be added here
    /**
     * @brief Calculates the inverse of the 3x3 matrix.
     *
     * This function computes the inverse of the current 3x3 matrix.
     * The inverse of a matrix is another matrix that, when multiplied by the original matrix,
     * results in the identity matrix.
     *
     * @return The inverse of the 3x3 matrix.
     *
     * @note The inverse of a matrix can be calculated using the following formula:
     * [a, b, c]
     * [d, e, f]
     * [g, h, i]
     *
     * Adjugate matrix:
     * [ei - fh, cf - di, bf - ce]
     * [fh - di, ai - cg, ce - af]
     * [cg - bh, df - bg, ae - bd]
     *
     * Inverse matrix = (1 / determinant) * Adjugate matrix
     *
     * Determinant of a 3x3 matrix:
     * a(ei - fh) - b(di - fg) + c(dh - eg)
     */
    Matrix3 inverse() const;
};

#include "matrix3.inl"

// Alias templates for common 3x3 matrix types
using Matrix3d = Matrix3<double>;
using Matrix3i = Matrix3<int>;
using Matrix3f = Matrix3<float>;
