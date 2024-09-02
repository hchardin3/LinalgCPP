#pragma once

#include <iostream>
#include <utility>
#include <vector>
#include <type_traits>
#include <cmath>
#include "../Utils/range.hpp"
#include "../Utils/types.hpp"

template<typename T, int Rows, int Cols>
class Matrix {
    protected:
        std::vector<T> data;
        int actual_rows;
        int actual_cols;
    
    public:
        static constexpr int num_rows = Rows;
        static constexpr int num_cols = Cols;

    // Constructors
    Matrix();

    Matrix(int rows, int cols);
    
    /**
     * @brief Creates a new Matrix object filled with zeros.
     *
     * This function creates a new Matrix object with the specified number of rows and columns,
     * and initializes all elements to zero. If no dimensions are provided, the function uses the
     * template parameters Rows and Cols as the default dimensions.
     *
     * @param rows The number of rows for the new Matrix. Default is Rows (template parameter).
     * @param cols The number of columns for the new Matrix. Default is Cols (template parameter).
     *
     * @return A new Matrix object filled with zeros.
     */
    static Matrix Zero(int rows = Rows, int cols = Cols);

    /**
     * @brief Creates a new Matrix object filled with ones.
     *
     * This function creates a new Matrix object with the specified number of rows and columns,
     * and initializes all elements to one. If no dimensions are provided, the function uses the
     * template parameters Rows and Cols as the default dimensions.
     *
     * @param rows The number of rows for the new Matrix. Default is Rows (template parameter).
     * @param cols The number of columns for the new Matrix. Default is Cols (template parameter).
     *
     * @return A new Matrix object filled with ones.
     */
    static Matrix One(int rows = Rows, int cols = Cols);

    // Accessors
    T& operator()(int i, int j);
    const T& operator()(int i, int j) const;

    // Matrix<T> operator()(All, int j) const;
    // Matrix<T> operator()(int i, All) const;

    // Matrix<T> operator()(Range row_range, Range col_range) const;
    // Matrix<T> operator()(Range row_range, int j) const;
    // Matrix<T> operator()(int i, Range col_range) const;

    Matrix<T, Rows, 1> row(int i) const;

    Matrix<T, 1, Cols> col(int j) const;

    // Operators
    Matrix operator+(const Matrix& other) const;

    Matrix operator-(const Matrix& other) const;

    Matrix& operator+=(const Matrix& other);

    Matrix& operator-=(const Matrix& other);

    Matrix operator*(const T& scalar) const;

    Matrix operator/(const T& scalar) const;

    Matrix& operator*=(const T& scalar);

    Matrix& operator/=(const T& scalar);

    template<int OtherRows, int OtherCols>
    Matrix<T, Rows, OtherCols> operator*(const Matrix<T, OtherRows, OtherCols>& other) const;

    template<int OtherRows, int OtherCols>
    Matrix<T, Rows, OtherCols> operator*=(const Matrix<T, OtherRows, OtherCols>& other);

    // Conversion operator for Matrix<T, 1, 1> to T
    operator T() const;

    // Other functions
    /**
     * @brief Returns the shape of the matrix as a pair of integers.
     *
     * This function returns a pair of integers representing the number of rows and columns in the matrix.
     * The first element of the pair is the number of rows, and the second element is the number of columns.
     *
     * @return A pair of integers representing the shape of the matrix. The first element is the number of rows,
     * and the second element is the number of columns.
     */
    const std::pair<const int, const int> shape() const;

    /**
     * @brief Returns the transpose of the matrix.
     *
     * This function computes and returns the transpose of the current matrix. The transpose of a matrix
     * is obtained by swapping its rows with columns. For a matrix A with dimensions m x n, its transpose
     * is denoted as A^T and has dimensions n x m.
     *
     * @return A new Matrix object representing the transpose of the current matrix. The returned matrix
     * has dimensions num_cols x num_rows.
     */
    Matrix<T, Cols, Rows> transpose() const;

    /**
     * @brief Reshapes the current matrix to a new shape specified by new_rows and new_cols.
     *
     * This function creates a new Matrix object with the specified number of rows and columns,
     * reshaping the current matrix data. If the new dimensions cannot be accommodated by the current
     * matrix data, the function throws an std::invalid_argument exception.
     *
     * @param new_rows The new number of rows for the reshaped Matrix.
     * @param new_cols The new number of columns for the reshaped Matrix.
     *
     * @return A new Matrix object with the reshaped dimensions. The returned matrix has dimensions
     * new_rows x new_cols.
     *
     * @throws std::invalid_argument if the new dimensions cannot be accommodated by the current matrix data.
     */
    template<int NewRows, int NewCols>
    Matrix<T, NewRows, NewCols> reshape(int new_rows, int new_cols) const;

    /**
     * @brief Flattens the current matrix into a 1D row vector.
     *
     * This function creates a new Matrix object with dimensions 1 x (num_rows * num_cols),
     * where the original matrix data is rearranged into a single row. The elements of the original
     * matrix are copied into the new matrix in row-major order.
     *
     * @return A new Matrix object representing the flattened version of the current matrix.
     * The returned matrix has dimensions 1 x (num_rows * num_cols).
     */
    Matrix<T, 1, Rows * Cols> flatten() const;

    // Norm methods
    /**
     * @brief Calculates the norm of the matrix.
     *
     * This function computes and returns the norm of the current matrix based on the specified norm type.
     * The norm is a measure of the magnitude of a vector or matrix. The supported norm types are L1, L2,
     * and infinity norm.
     *
     * @param type The type of norm to compute. The default norm type is L2.
     *
     * @return The computed norm of the matrix.
     *
     * @throws std::invalid_argument if an unsupported norm type is specified.
     *
     * @note The L1 norm is the sum of the absolute values of the elements.
     * @note The L2 norm (Euclidean norm) is the square root of the sum of the squared elements.
     * @note The infinity norm is the maximum absolute row sum.
     */
    T norm(NormType type = NormType::L2) const;

    /**
     * @brief Normalizes the current matrix to have a unit norm.
     *
     * This function computes and returns a new Matrix object where each element is scaled by a factor
     * such that the resulting matrix has a unit norm. The norm is calculated based on the specified norm type.
     * The supported norm types are L1, L2, and infinity norm.
     *
     * @param type The type of norm to use for normalization. The default norm type is L2.
     *
     * @return A new Matrix object where each element is scaled by a factor such that the resulting matrix
     * has a unit norm.
     *
     * @throws std::invalid_argument if an unsupported norm type is specified.
     *
     * @note The L1 norm is the sum of the absolute values of the elements.
     * @note The L2 norm (Euclidean norm) is the square root of the sum of the squared elements.
     * @note The infinity norm is the maximum absolute row sum.
     */
    Matrix normalize(NormType type = NormType::L2) const;

    // Display
    /**
     * @brief Displays the matrix elements in a formatted manner.
     *
     * This function prints the elements of the matrix to the standard output stream (std::cout) in a
     * human-readable format. The elements are displayed in a grid-like structure, with each element separated
     * by a space. The function does not return any value.
     *
     * @note The display format is suitable for small matrices. For larger matrices, the output may be
     * truncated or difficult to read.
     */
    void display() const;
    
};

#include "matrix.inl"

// Custom matrix types
using MatrixXd = Matrix<double, DynamicSize, DynamicSize>;
using Matrixi = Matrix<int, DynamicSize, DynamicSize>;
using Matrixf = Matrix<float, DynamicSize, DynamicSize>;