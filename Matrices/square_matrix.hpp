#pragma once

#include <iostream>
#include <utility>
#include <vector>
#include <type_traits>
#include "matrix.hpp"

template<typename T, int Size>
class MatrixS : public Matrix<T, Size, Size> {
public:
    // Constructors
    MatrixS();
    MatrixS(const Matrix<T, Size, Size>& m);

    MatrixS(int size);

    /**
     * @brief Constructs a square matrix of size 'size' with all elements initialized to zero.
     *
     * @param size The size of the square matrix to be created.
     *
     * @return A square matrix of size 'size' with all elements initialized to zero.
     */
    static MatrixS<T, Size> Zero(int size);

    /**
    * @brief Constructs a square matrix of size 'size' with all elements initialized to one.
    *
    * This function creates a square matrix of the specified size, where all elements are initialized to one.
    *
    * @param size The size of the square matrix to be created.
    *
    * @return A square matrix of size 'size' with all elements initialized to one.
    */
    static MatrixS<T, Size> One(int size);

    /**
    * @brief Constructs an identity matrix of size 'size'.
    *
    * An identity matrix is a square matrix with ones on the main diagonal (top-left to bottom-right)
    * and zeros in all other positions. This function creates an identity matrix of the specified size.
    *
    * @param size The size of the square matrix to be created.
    *
    * @return A square matrix of size 'size' with ones on the main diagonal and zeros elsewhere.
    */
    static MatrixS Identity(int size);

    // Class methods
    /**
     * @brief Calculates the trace of the square matrix.
     *
     * The trace of a square matrix is the sum of its diagonal elements.
     * This function returns the trace of the current square matrix.
     *
     * @return The trace of the square matrix.
     */
    T trace() const;

    /**
    * @brief Calculates the power of the square matrix.
    *
    * This function raises the current square matrix to the power of 'n'.
    * The power operation is defined as multiplying the matrix by itself 'n' times.
    *
    * @param n The power to which the matrix should be raised.
    *
    * @return A new square matrix that is the result of raising the current matrix to the power of 'n'.
    *
    * @note This function only works for positive integers.
    *
    * @note The power operation is not defined for non-square matrices. This function only works
    * with square matrices.
    */
    MatrixS<T, Size> power(int n) const;

    /**
     * @brief Calculates the determinant of the square matrix.
     *
     * The determinant of a square matrix is a scalar value that can be computed from its elements.
     * It has important properties in linear algebra, such as determining the inverse of a matrix and solving systems of linear equations.
     * This function calculates the determinant of the current square matrix.
     *
     * @return The determinant of the square matrix.
     *
     * @note The determinant is only defined for square matrices. This function only works with square matrices.
     *
     * @note The determinant calculation may involve complex arithmetic for matrices with complex elements.
     *
     * @note For large matrices, calculating the determinant can be computationally expensive.
     * It is recommended to use specialized algorithms or libraries for such cases.
     */
    T determinant() const;

    /**
     * @brief Calculates the inverse of the square matrix.
     *
     * The inverse of a square matrix is another square matrix that, when multiplied by the original matrix,
     * results in an identity matrix. The inverse is unique for non-singular square matrices.
     *
     * @return A new square matrix that is the inverse of the current matrix.
     *
     * @note The inverse is only defined for square matrices. This function only works with square matrices.
     *
     * @note The inverse calculation may involve complex arithmetic for matrices with complex elements.
     *
     * @note For large matrices, calculating the inverse can be computationally expensive.
     * It is recommended to use specialized algorithms or libraries for such cases.
     *
     * @note If the current matrix is singular (non-invertible), this function will throw a std::runtime_error.
     */
    MatrixS<T, Size> inverse() const;
};

#include "square_matrix.inl"

// Alias templates for common matrix types
using MatrixSd = MatrixS<double, DynamicSize>;
using MatrixSi = MatrixS<int, DynamicSize>;
using MatrixSf = MatrixS<float, DynamicSize>;