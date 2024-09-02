#include "matrix.hpp"

// Constructors
template<typename T, int Rows, int Cols>
Matrix<T, Rows, Cols>::Matrix() : actual_rows(Rows == DynamicSize ? 0 : Rows), actual_cols(Cols == DynamicSize ? 0 : Cols), data((Rows == DynamicSize || Cols == DynamicSize) ? 0 : Rows * Cols) {}

template<typename T, int Rows, int Cols>
Matrix<T, Rows, Cols>::Matrix(int rows, int cols) : actual_rows(rows), actual_cols(cols) {
    if (Rows != DynamicSize && Rows != rows) {
        throw std::runtime_error("Fixed rows do not match the provided size.");
    }
    if (Cols != DynamicSize && Cols != cols) {
        throw std::runtime_error("Fixed cols do not match the provided size.");
    }
    data.resize(rows * cols);
}

template<typename T, int Rows, int Cols>
Matrix<T, Rows, Cols> Matrix<T, Rows, Cols>::Zero(int rows, int cols) {
    Matrix result(rows, cols);
    std::fill(result.data.begin(), result.data.end(), T(0));
    return result;
}

template<typename T, int Rows, int Cols>
Matrix<T, Rows, Cols> Matrix<T, Rows, Cols>::One(int rows, int cols) {
    Matrix result(rows, cols);
    std::fill(result.data.begin(), result.data.end(), T(1));
    return result;
}


// Accessors
template<typename T, int Rows, int Cols>
T& Matrix<T, Rows, Cols>::operator()(int i, int j) {
    if(i < 0) {i += num_rows;}
    if(j < 0) {j += num_cols;}
    if (i < 0 || i >= num_rows || j < 0 || j >= num_cols) {
        throw std::out_of_range("Index out of range");
    }
    return data[i * num_cols + j];
}

template<typename T, int Rows, int Cols>
const T& Matrix<T, Rows, Cols>::operator()(int i, int j) const {
    if(i < 0) {i += num_rows;}
    if(j < 0) {j += num_cols;}
    if (i < 0 || i >= num_rows || j < 0 || j >= num_cols) {
        throw std::out_of_range("Index out of range");
    }
    return data[i * num_cols + j];
}


// template<typename T, int Rows, int Cols>
// typename Matrix<T, Rows, Cols>::VectorType Matrix<T, Rows, Cols>::operator()(All, int j) const {
//     if(j < 0) {j += num_cols;}
//     if (j < 0 || j >= num_cols) {
//         throw std::out_of_range("Index out of range");
//     }
//     VectorType column(num_rows);
//     for (int i = 0; i < num_rows; ++i) {
//         column[i] = data[i * num_cols + j];
//     }
//     return column;
// }

// template<typename T, int Rows, int Cols>
// typename Matrix<T, Rows, Cols>::VectorType Matrix<T, Rows, Cols>::operator()(int i, All) const {
//     if(i < 0) {i += num_rows;}
//     if (i < 0 || i >= num_rows) {
//         throw std::out_of_range("Index out of range");
//     }
//     VectorType row(num_cols);
//     for (int j = 0; j < num_cols; ++j) {
//         row[j] = data[i * num_cols + j];
//     }
//     return row;
// }


// template<typename T, int Rows, int Cols>
// Matrix<T, (Rows != Eigen::Dynamic ? Rows : 0), (Cols != Eigen::Dynamic ? Cols : 0)>
// Matrix<T, Rows, Cols>::operator()(Range row_range, Range col_range) const {
//     int row_start = row_range.start < 0 ? row_range.start + num_rows : row_range.start;
//     int row_end = row_range.end < 0 ? row_range.end + num_rows : row_range.end;
//     int col_start = col_range.start < 0 ? col_range.start + num_cols : col_range.start;
//     int col_end = col_range.end < 0 ? col_range.end + num_cols : col_range.end;

//     if (row_start < 0 || row_end > num_rows || col_start < 0 || col_end > num_cols || row_start >= row_end || col_start >= col_end) {
//         throw std::out_of_range("Submatrix index out of range");
//     }

//     Matrix<T, row_end - row_start, col_end - col_start> submatrix;
//     for (int i = row_start; i < row_end; ++i) {
//         for (int j = col_start; j < col_end; ++j) {
//             submatrix(i - row_start, j - col_start) = (*this)(i, j);
//         }
//     }
//     return submatrix;
// }

// template<typename T, int Rows, int Cols>
// Matrix<T, (Rows != Eigen::Dynamic ? Rows : 0), 1> Matrix<T, Rows, Cols>::operator()(Range row_range, int j) const {
//     int row_start = row_range.start < 0 ? row_range.start + num_rows : row_range.start;
//     int row_end = row_range.end < 0 ? row_range.end + num_rows : row_range.end;

//     if (row_start < 0 || row_end > num_rows || j < 0 || j >= num_cols || row_start >= row_end) {
//         throw std::out_of_range("Submatrix index out of range");
//     }

//     Matrix<T, row_end - row_start, 1> submatrix;
//     for (int i = row_start; i < row_end; ++i) {
//         submatrix(i - row_start, 0) = (*this)(i, j);
//     }
//     return submatrix;
// }

// template<typename T, int Rows, int Cols>
// Matrix<T, 1, (Cols != Eigen::Dynamic ? Cols : 0)> Matrix<T, Rows, Cols>::operator()(int i, Range col_range) const {
//     int col_start = col_range.start < 0 ? col_range.start + num_cols : col_range.start;
//     int col_end = col_range.end < 0 ? col_range.end + num_cols : col_range.end;

//     if (i < 0 || i >= num_rows || col_start < 0 || col_end > num_cols || col_start >= col_end) {
//         throw std::out_of_range("Submatrix index out of range");
//     }

//     Matrix<T, 1, col_end - col_start> submatrix;
//     for (int j = col_start; j < col_end; ++j) {
//         submatrix(0, j - col_start) = (*this)(i, j);
//     }
//     return submatrix;
// }


// Operators
template<typename T, int Rows, int Cols>
Matrix<T, Rows, Cols> Matrix<T, Rows, Cols>::operator+(const Matrix<T, Rows, Cols>& other) const {
    if (this->actual_cols != other.actual_cols || this->actual_rows!= other.actual_rows) {
        throw std::invalid_argument("Matrices have different dimensions");
    }
    Matrix result;
    for(int i = 0; i < actual_rows; ++i) {
        for (int j = 0; j < actual_cols; ++j) {
            result(i, j) = (*this).operator()(i, j) + other(i, j);
        }
    }
    return result;
}

template<typename T, int Rows, int Cols>
Matrix<T, Rows, Cols> Matrix<T, Rows, Cols>::operator-(const Matrix<T, Rows, Cols>& other) const {
    if (this->actual_cols != other.actual_cols || this->actual_rows!= other.actual_rows) {
        throw std::invalid_argument("Matrices have different dimensions");
    }
    Matrix result;
    for(int i = 0; i < actual_rows; ++i) {
        for (int j = 0; j < actual_cols; ++j) {
            result(i, j) = (*this).operator()(i, j) - other(i, j);
        }
    }
    return result;
}

template<typename T, int Rows, int Cols>
Matrix<T, Rows, Cols>& Matrix<T, Rows, Cols>::operator+=(const Matrix<T, Rows, Cols> & other) {
    if (this->actual_cols != other.actual_cols || this->actual_rows!= other.actual_rows) {
        throw std::invalid_argument("Matrices have different dimensions");
    }
    for(int i = 0; i < actual_rows; ++i) {
        for (int j = 0; j < actual_cols; ++j) {
            (*this).operator()(i, j) += other(i, j);
        }
    }
    return *this;
}

template<typename T, int Rows, int Cols>
Matrix<T, Rows, Cols>& Matrix<T, Rows, Cols>::operator-=(const Matrix<T, Rows, Cols> & other) {
    if (this->actual_cols != other.actual_cols || this->actual_rows!= other.actual_rows) {
        throw std::invalid_argument("Matrices have different dimensions");
    }
    for(int i = 0; i < actual_rows; ++i) {
        for (int j = 0; j < actual_cols; ++j) {
            (*this).operator()(i, j) -= other(i, j);
        }
    }
    return *this;
}

template<typename T, int Rows, int Cols>
Matrix<T, Rows, Cols> Matrix<T, Rows, Cols>::operator*(const T& scalar) const {
    Matrix result;
    for(int i = 0; i < actual_rows; ++i) {
        for (int j = 0; j < actual_cols; ++j) {
            result.data[i * Cols + j] = data[i * Cols + j] * scalar;
        }
    }
    return result;
}

template<typename T, int Rows, int Cols>
Matrix<T, Rows, Cols> Matrix<T, Rows, Cols>::operator/(const T& scalar) const {
    if (scalar == T(0)) {
        throw std::invalid_argument("Division by zero is not allowed");
    }
    Matrix result;
    for(int i = 0; i < actual_rows; ++i) {
        for (int j = 0; j < actual_cols; ++j) {
            result.data[i * Cols + j] = data[i * Cols + j] / scalar;
        }
    }
    return result;
}

template<typename T, int Rows, int Cols>
Matrix<T, Rows, Cols>& Matrix<T, Rows, Cols>::operator*=(const T& scalar) {
    for(int i = 0; i < actual_rows; ++i) {
        for (int j = 0; j < actual_cols; ++j) {
            (*this).operator()(i, j) *= scalar;
        }
    }
    return *this;
}

template<typename T, int Rows, int Cols>
Matrix<T, Rows, Cols>& Matrix<T, Rows, Cols>::operator/=(const T& scalar) {
    if (scalar == T(0)) {
        throw std::invalid_argument("Division by zero is not allowed");
    }
    for(int i = 0; i < actual_rows; ++i) {
        for (int j = 0; j < actual_cols; ++j) {
            (*this).operator()(i, j) /= scalar;
        }
    }
    return *this;
}

template<typename T, int Rows, int Cols>
template<int OtherRows, int OtherCols>
Matrix<T, Rows, OtherCols> Matrix<T, Rows, Cols>::operator*(const Matrix<T, OtherRows, OtherCols>& other) const {
    const std::pair<const int, const int> other_shape = other.shape();
    const int other_rows = other_shape.first;
    const int other_cols = other_shape.second;
    if (this->actual_cols != other_rows) {
        throw std::invalid_argument("Matrices must have compatible dimensions for multiplication");
    }
    Matrix<T, Rows, OtherCols> result;
    for(int i = 0; i < actual_rows; ++i) {
        for (int j = 0; j < other_cols; ++j) {
            result(i, j) = T(0);
            for (int k = 0; k < other_rows; ++k) {
                (result)(i, j) += (*this)(i, k) * other(k, j);
            }
        }
    }
    return result;
}
template<typename T, int Rows, int Cols>
template<int OtherRows, int OtherCols>
  Matrix<T, Rows, OtherCols> Matrix<T, Rows, Cols>::operator*=(const Matrix<T, OtherRows, OtherCols>& other) {
    if (this->actual_cols != other.actual_rows) {
        throw std::invalid_argument("Matrices must have compatible dimensions for multiplication");
    }
    Matrix<T, Rows, OtherCols> result = Matrix<T, Rows, OtherCols>::Zero(actual_rows, other.actual_cols);
    for(int i = 0; i < actual_rows; ++i) {
        for (int j = 0; j < other.actual_cols; ++j) {
            for (int k = 0; k < other.actual_rows; ++k) {
                (result)(i, j) += (*this)(i, k) * other(k, j);
            }            
        }
    }
    *this = result;
    return *this;
  }

// Conversion operator for Matrix<T, 1, 1> to T
template<typename T, int Rows, int Cols>
Matrix<T, Rows, Cols>::operator T() const  {
    static_assert(Rows == 1 && Cols == 1, "Conversion to type T is only valid for Matrix<T, 1, 1>");
    return data[0];
}

// Other functions
template<typename T, int Rows, int Cols>
const std::pair<const int, const int> Matrix<T, Rows, Cols>::shape() const {
    return std::make_pair(actual_rows, actual_cols);
}

template<typename T, int Rows, int Cols>
Matrix<T, Cols, Rows> Matrix<T, Rows, Cols>::transpose() const {
    Matrix<T, Cols, Rows> result(this->actual_cols, this->actual_rows);
    for(int j = 0; j < actual_cols; ++j) {
        for (int i = 0; i < actual_rows; ++i) {
            result(j, i) = (*this).operator()(i, j);
        }
    }
    return result;
}

template<typename T, int Rows, int Cols>
template<int NewRows, int NewCols>
Matrix<T, NewRows, NewCols> Matrix<T, Rows, Cols>::reshape(int new_rows, int new_cols) const {
    if (new_rows * new_cols != actual_rows * actual_cols) {
        throw std::runtime_error("Reshape dimensions must match the total number of elements.");
    }
    
    Matrix<T, NewRows, NewCols> result;
    result.data = data;
    return result;
}


template<typename T, int Rows, int Cols>
Matrix<T, 1, Rows * Cols> Matrix<T, Rows, Cols>::flatten() const {
    Matrix<T, 1, Rows * Cols> result(1, actual_rows * actual_cols);
    result.data = data;
    return result;
}

// Norm methods
template<typename T, int Rows, int Cols>
T Matrix<T, Rows, Cols>::norm(NormType type) const {
    T sum = T(0);

    if (type == NormType::Inf) {
        // Infinity norm (max absolute row sum)
        for (int i = 0; i < actual_rows; ++i) {
            T row_sum = T(0);
            for (int j = 0; j < actual_cols; ++j) {
                row_sum += std::abs((*this).operator()(i, j));
            }
            sum = std::max(sum, row_sum);
        }
        return sum;
    } else {
        for (int i = 0; i < actual_rows; ++i) {
            for (int j = 0; j < actual_cols; ++j) {
                T element = (*this).operator()(i, j);
                sum += std::pow(std::abs(element), static_cast<int>(type));
            }
        }
        return std::pow(sum, T(1) / static_cast<int>(type));
    }
}

template<typename T, int Rows, int Cols>
Matrix<T, Rows, Cols> Matrix<T, Rows, Cols>::normalize() const{
    T norm_val = this->norm();
    if (norm_val == T(0)) {
        throw std::invalid_argument("Cannot normalize a zero-matrix");
    }
    return this->operator/(norm_val);
}

// Display
template<typename T, int Rows, int Cols>
void Matrix<T, Rows, Cols>::display() const {
    std::cout << "Matrix<" << typeid(T).name() << ", " << actual_rows << ", " << actual_cols << ">" << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    for(int i = 0; i < actual_rows; ++i) {
        for (int j = 0; j < actual_cols; ++j) {
            std::cout << (*this).operator()(i, j) << " ";
        }
        std::cout << std::endl;
    }
}