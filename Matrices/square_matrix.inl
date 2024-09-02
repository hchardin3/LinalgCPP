#include "square_matrix.hpp"

// Constructors
template <typename T, int Size>
MatrixS<T, Size>::MatrixS() : Matrix<T, Size, Size>() {}

template <typename T, int Size>
MatrixS<T, Size>::MatrixS(const Matrix<T, Size, Size>& m) : Matrix<T, Size, Size>(m) {}

template <typename T, int Size>
MatrixS<T, Size>::MatrixS(int size) : Matrix<T, Size, Size>(size, size) {}

template <typename T, int Size>
MatrixS<T, Size> MatrixS<T, Size>::Zero(int size) {
    return MatrixS<T, Size>(Matrix<T, Size, Size>::Zero(size, size));
}

template <typename T, int Size>
MatrixS<T, Size> MatrixS<T, Size>::One(int size) {
    return MatrixS<T, Size>(Matrix<T, Size, Size>::One(size, size));
}

// Identity matrix
template <typename T, int Size>
MatrixS<T, Size> MatrixS<T, Size>::Identity(int size) {
    MatrixS<T, Size> result = MatrixS<T, Size>::Zero(size);  // Adjust for dynamic size
    for (int i = 0; i < Size; ++i) {
        result(i, i) = T(1);
    }
    return result;
}

// Trace
template <typename T, int Size>
T MatrixS<T, Size>::trace() const {
    T sum = T(0);
    for (int i = 0; i < Size; ++i) {
        sum += (*this)(i, i);
    }
    return sum;
}

// Matrix power
template <typename T, int Size>
MatrixS<T, Size> MatrixS<T, Size>::power(int n) const {
    if (n < 0) {
        throw std::invalid_argument("Exponent must be non-negative.");
    }
    MatrixS<T, Size> result = MatrixS<T, Size>::Identity();
    MatrixS<T, Size> temp = *this;
    for (int i = 0; i < n; ++i) {
        result *= temp;
    }
    return result;
}

// Determinant
template<typename T, int Size>
T MatrixS<T, Size>::determinant() const {
    static_assert(Size > 0, "Matrix size must be greater than 0");

    if constexpr (Size == 1) {
        return (*this)(0, 0);  // Determinant of a 1x1 matrix is the element itself
    } else if constexpr (Size == 2) {
        // Determinant of a 2x2 matrix: ad - bc
        return (*this)(0, 0) * (*this)(1, 1) - (*this)(0, 1) * (*this)(1, 0);
    } else if constexpr (Size == 3) {
        // Determinant of a 3x3 matrix:
        return (*this)(0, 0) * ((*this)(1, 1) * (*this)(2, 2) - (*this)(1, 2) * (*this)(2, 1)) -
               (*this)(0, 1) * ((*this)(1, 0) * (*this)(2, 2) - (*this)(1, 2) * (*this)(2, 0)) +
               (*this)(0, 2) * ((*this)(1, 0) * (*this)(2, 1) - (*this)(1, 1) * (*this)(2, 0));
    } else {
        // For larger matrices, use recursive expansion by minors
        T det = T(0);
        for (int j = 0; j < Size; ++j) {
            MatrixS<T, Size - 1> submatrix;
            for (int sub_i = 0, src_i = 1; sub_i < Size - 1; ++sub_i, ++src_i) {
                for (int sub_j = 0, src_j = 0; sub_j < Size - 1; ++sub_j, ++src_j) {
                    if (src_j == j) ++src_j; // Skip the current column
                    submatrix(sub_i, sub_j) = (*this)(src_i, src_j);
                }
            }
            T sign = (j % 2 == 0) ? T(1) : T(-1);
            det += sign * (*this)(0, j) * submatrix.determinant();
        }
        return det;
    }
}

// Inverse
template<typename T, int Size>
MatrixS<T, Size> MatrixS<T, Size>::inverse() const {
    T det = this->determinant();

    if (det == T(0)) {
        throw std::invalid_argument("Matrix is singular and cannot be inverted.");
    }

    MatrixS<T, Size> adjugate; // Adjugate matrix

    // Compute the cofactor matrix and transpose it to get the adjugate
    for (int i = 0; i < Size; ++i) {
        for (int j = 0; j < Size; ++j) {
            // Create a (Size-1) x (Size-1) submatrix
            MatrixS<T, Size - 1> submatrix;
            for (int sub_i = 0, src_i = 0; src_i < Size; ++src_i) {
                if (src_i == i) continue; // Skip the current row
                for (int sub_j = 0, src_j = 0; src_j < Size; ++src_j) {
                    if (src_j == j) continue; // Skip the current column
                    submatrix(sub_i, sub_j) = (*this)(src_i, src_j);
                    sub_j++;
                }
                sub_i++;
            }

            // Calculate the cofactor
            T cofactor = submatrix.determinant();
            if ((i + j) % 2 != 0) {
                cofactor = -cofactor; // Apply the sign for the cofactor
            }

            // Place the cofactor in the adjugate matrix (transposed position)
            adjugate(j, i) = cofactor; // Transpose the cofactor matrix
        }
    }

    // Divide the adjugate matrix by the determinant to get the inverse
    return adjugate / det;
}


