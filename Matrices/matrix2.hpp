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

    /**
     * @brief Creates a 2x2 matrix with all elements initialized to zero.
     *
     * @return A 2x2 matrix with all elements set to zero.
     */
    static Matrix2 Zero();

    /**
     * @brief Creates a 2x2 matrix with all elements initialized to one.
     *
     * @return A 2x2 matrix with all elements set to one.
     */
    static Matrix2 One();

    /**
     * @brief Creates a 2x2 identity matrix.
     *
     * An identity matrix is a square matrix with ones on the main diagonal (top left to bottom right)
     * and zeros in all other positions. This function returns a 2x2 identity matrix.
     *
     * @return A 2x2 identity matrix.
     */
    static Matrix2 Identity();

    // Static method to create a 2x2 rotation matrix
    /**
    * @brief Creates a 2x2 rotation matrix.//+
    *
    * A rotation matrix is a square matrix that represents a rotation in a 2D space.//+
    * It is used to rotate vectors and points around the origin by a given angle.//+
    * The rotation matrix for a 2D space can be represented as follows://+
    *
    * [ cos(angle), -sin(angle) ]//+
    * [ sin(angle),  cos(angle) ]//+
    *
    * @param angle_in_radians The angle of rotation in radians.//+
    *
    * @return A 2x2 rotation matrix.//+
    *
    * @note The angle is expected to be in radians.//+
    * @note The returned matrix is a template specialization for the given type T.//+
    */
    static Matrix2<T> Rotation(T angle_in_radians);

    // Additional 2x2 specific methods can be added here
    /**
     * @brief Calculates the inverse of the 2x2 matrix.
     *
     * The inverse of a matrix is another matrix that, when multiplied by the original matrix,
     * results in an identity matrix. In the case of a 2x2 matrix, the inverse can be calculated
     * using the following formula:
     *
     * [ a, b ]^(-1) = (1 / (ad - bc)) * [ d, -b ]
     * [ c, d ]               [ -c, a ]
     *
     * If the determinant (ad - bc) is zero, the matrix is not invertible and this function
     * will return a matrix with all elements set to zero.
     *
     * @return The inverse of the 2x2 matrix. If the matrix is not invertible,
     *         a matrix with all elements set to zero is returned.
     */
    Matrix2 inverse() const;
};

#include "matrix2.inl"

// Alias templates for common 2x2 matrix types
using Matrix2d = Matrix2<double>;
using Matrix2i = Matrix2<int>;
using Matrix2f = Matrix2<float>;
