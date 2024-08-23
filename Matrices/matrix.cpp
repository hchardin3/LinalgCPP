#include "matrix.hpp"

// Constructors
template<typename T, int Rows, int Cols>
MatrixX<T, Rows, Cols>::MatrixX() : data(Rows * Cols) {}

template<typename T, int Rows, int Cols>
MatrixX<T, Rows, Cols> MatrixX<T, Rows, Cols>::Zero() {
    MatrixX result;
    for(int i = 0; i < Rows; ++i) {
        for (int j = 0; j < Cols; ++j) {
            data[i * Cols + j] = T(0);
        }
    }
    return result;
}

template<typename T, int Rows, int Cols>
MatrixX<T, Rows, Cols> MatrixX<T, Rows, Cols>::One() {
    MatrixX result;
    for(int i = 0; i < Rows; ++i) {
        for (int j = 0; j < Cols; ++j) {
            data[i * Cols + j] = T(1);
        }
    }
    return result;
}

// Accessors
template<typename T, int Rows, int Cols>
T& MatrixX<T, Rows, Cols>::operator()(int i, int j) {
    if(i < 0) {i += num_rows;}
    if(j < 0) {j += num_cols;}
    if (i < 0 || i >= num_rows || j < 0 || j >= num_cols) {
        throw std::out_of_range("Index out of range");
    }
    return data[i * num_cols + j];
}

template<typename T, int Rows, int Cols>
const T& MatrixX<T, Rows, Cols>::operator()(int i, int j) const {
    if(i < 0) {i += num_rows;}
    if(j < 0) {j += num_cols;}
    if (i < 0 || i >= num_rows || j < 0 || j >= num_cols) {
        throw std::out_of_range("Index out of range");
    }
    return data[i * num_cols + j];
}


// template<typename T, int Rows, int Cols>
// typename MatrixX<T, Rows, Cols>::VectorType MatrixX<T, Rows, Cols>::operator()(All, int j) const {
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
// typename MatrixX<T, Rows, Cols>::VectorType MatrixX<T, Rows, Cols>::operator()(int i, All) const {
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
// MatrixX<T, (Rows != Eigen::Dynamic ? Rows : 0), (Cols != Eigen::Dynamic ? Cols : 0)>
// MatrixX<T, Rows, Cols>::operator()(Range row_range, Range col_range) const {
//     int row_start = row_range.start < 0 ? row_range.start + num_rows : row_range.start;
//     int row_end = row_range.end < 0 ? row_range.end + num_rows : row_range.end;
//     int col_start = col_range.start < 0 ? col_range.start + num_cols : col_range.start;
//     int col_end = col_range.end < 0 ? col_range.end + num_cols : col_range.end;

//     if (row_start < 0 || row_end > num_rows || col_start < 0 || col_end > num_cols || row_start >= row_end || col_start >= col_end) {
//         throw std::out_of_range("Submatrix index out of range");
//     }

//     MatrixX<T, row_end - row_start, col_end - col_start> submatrix;
//     for (int i = row_start; i < row_end; ++i) {
//         for (int j = col_start; j < col_end; ++j) {
//             submatrix(i - row_start, j - col_start) = (*this)(i, j);
//         }
//     }
//     return submatrix;
// }

// template<typename T, int Rows, int Cols>
// MatrixX<T, (Rows != Eigen::Dynamic ? Rows : 0), 1> MatrixX<T, Rows, Cols>::operator()(Range row_range, int j) const {
//     int row_start = row_range.start < 0 ? row_range.start + num_rows : row_range.start;
//     int row_end = row_range.end < 0 ? row_range.end + num_rows : row_range.end;

//     if (row_start < 0 || row_end > num_rows || j < 0 || j >= num_cols || row_start >= row_end) {
//         throw std::out_of_range("Submatrix index out of range");
//     }

//     MatrixX<T, row_end - row_start, 1> submatrix;
//     for (int i = row_start; i < row_end; ++i) {
//         submatrix(i - row_start, 0) = (*this)(i, j);
//     }
//     return submatrix;
// }

// template<typename T, int Rows, int Cols>
// MatrixX<T, 1, (Cols != Eigen::Dynamic ? Cols : 0)> MatrixX<T, Rows, Cols>::operator()(int i, Range col_range) const {
//     int col_start = col_range.start < 0 ? col_range.start + num_cols : col_range.start;
//     int col_end = col_range.end < 0 ? col_range.end + num_cols : col_range.end;

//     if (i < 0 || i >= num_rows || col_start < 0 || col_end > num_cols || col_start >= col_end) {
//         throw std::out_of_range("Submatrix index out of range");
//     }

//     MatrixX<T, 1, col_end - col_start> submatrix;
//     for (int j = col_start; j < col_end; ++j) {
//         submatrix(0, j - col_start) = (*this)(i, j);
//     }
//     return submatrix;
// }


// Operators
template<typename T, int Rows, int Cols>
MatrixX<T, Rows, Cols> MatrixX<T, Rows, Cols>::operator+(const MatrixX<T, Rows, Cols>& other) const {
    MatrixX result;
    for(int i = 0; i < Rows; ++i) {
        for (int j = 0; j < Cols; ++j) {
            result.data[i * Cols + j] = data[i * Cols + j] + other.data[i * Cols + j];
        }
    }
    return result;
}

template<typename T, int Rows, int Cols>
MatrixX<T, Rows, Cols> MatrixX<T, Rows, Cols>::operator-(const MatrixX<T, Rows, Cols>& other) const {
    MatrixX result;
    for(int i = 0; i < Rows; ++i) {
        for (int j = 0; j < Cols; ++j) {
            result.data[i * Cols + j] = data[i * Cols + j] - other.data[i * Cols + j];
        }
    }
    return result;
}

template<typename T, int Rows, int Cols>
MatrixX<T, Rows, Cols> MatrixX<T, Rows, Cols>::operator+=(const MatrixX<T, Rows, Cols> & other) {
    for(int i = 0; i < Rows; ++i) {
        for (int j = 0; j < Cols; ++j) {
            data[i * Cols + j] += other.data[i * Cols + j];
        }
    }
    return *this;
}

template<typename T, int Rows, int Cols>
MatrixX<T, Rows, Cols> MatrixX<T, Rows, Cols>::operator-=(const MatrixX<T, Rows, Cols> & other) {
    for(int i = 0; i < Rows; ++i) {
        for (int j = 0; j < Cols; ++j) {
            data[i * Cols + j] -= other.data[i * Cols + j];
        }
    }
    return *this;
}

template<typename T, int Rows, int Cols>
MatrixX<T, Rows, Cols> MatrixX<T, Rows, Cols>::operator*(const T& scalar) const {
    MatrixX result;
    for(int i = 0; i < Rows; ++i) {
        for (int j = 0; j < Cols; ++j) {
            result.data[i * Cols + j] = data[i * Cols + j] * scalar;
        }
    }
    return result;
}

template<typename T, int Rows, int Cols>
MatrixX<T, Rows, Cols> MatrixX<T, Rows, Cols>::operator/(const T& scalar) const {
    if (scalar == T(0)) {
        throw std::invalid_argument("Division by zero is not allowed");
    }
    MatrixX result;
    for(int i = 0; i < Rows; ++i) {
        for (int j = 0; j < Cols; ++j) {
            result.data[i * Cols + j] = data[i * Cols + j] / scalar;
        }
    }
    return result;
}

template<typename T, int Rows, int Cols>
MatrixX<T, Rows, Cols> MatrixX<T, Rows, Cols>::operator*=(const T& scalar) {
    for(int i = 0; i < Rows; ++i) {
        for (int j = 0; j < Cols; ++j) {
            data[i * Cols + j] *= scalar;
        }
    }
    return *this;
}

template<typename T, int Rows, int Cols>
MatrixX<T, Rows, Cols> MatrixX<T, Rows, Cols>::operator/=(const T& scalar) {
    if (scalar == T(0)) {
        throw std::invalid_argument("Division by zero is not allowed");
    }
    for(int i = 0; i < Rows; ++i) {
        for (int j = 0; j < Cols; ++j) {
            data[i * Cols + j] /= scalar;
        }
    }
    return *this;
}

template<typename T, int Rows, int Cols>
template<int OtherRows, int OtherCols>
MatrixX<T, Rows, OtherCols> MatrixX<T, Rows, Cols>::operator*(const MatrixX<T, OtherRows, OtherCols>& other) const {
    if (Cols!= OtherRows) {
        throw std::invalid_argument("Matrices must have compatible dimensions for multiplication");
    }
    MatrixX result;
    for(int i = 0; i < Rows; ++i) {
        for (int j = 0; j < Cols; ++j) {
            result.data[i * Cols + j] = T(0);
            for (int k = 0; k < OtherCols; ++k) {
                result.data[i * Cols + j] += data[i * Cols + k] * other.data[k * OtherCols + j];
            }
        }
    }
    return result;
}

// Other functions
template<typename T, int Rows, int Cols>
std::pair<int, int> MatrixX<T, Rows, Cols>::shape() const {
    return std::make_pair(Rows, Cols);
}

template<typename T, int Rows, int Cols>
MatrixX<T, Cols, Rows> MatrixX<T, Rows, Cols>::transpose() const {
    MatrixX<T, Cols, Rows> result;
    for(int j = 0; j < Cols; ++j) {
        for (int i = 0; i < Rows; ++i) {
            result.data[j * Rows + i] = data[i * Cols + j];
        }
    }
    return result;
}

template<typename T, int Rows, int Cols>
template<int NewRows, int NewCols>
MatrixX<T, NewRows, NewCols> MatrixX<T, Rows, Cols>::reshape(int NewRows, int NewCols) const {
    if (Rows * Cols!= NewRows * NewCols) {
        throw std::invalid_argument("Reshaping matrix dimensions must match");
    }
    MatrixX<T, NewRows, NewCols> result;
    for(int i = 0; i < NewRows; ++i) {
        for (int j = 0; j < NewCols; ++j) {
            result.data[i * NewCols + j] = data[i * Cols + j];
        }
    }
    return result;
}

template<typename T, int Rows, int Cols>
MatrixX<T, 1, Rows * Cols> MatrixX<T, Rows, Cols>::flatten() const {
    return this->reshape(1, Rows * Cols);
}

// Norm methods
template<typename T, int Rows, int Cols>
T MatrixX<T, Rows, Cols>::norm(NormType type = NormType::L2) const {
    T sum = T(0);
    if (type == NormType::Inf) {
        // Infinity norm (max absolute row sum)
        for(int i = 0; i < Rows; ++i) {
            T row_sum = T(0);
            for (int j = 0; j < Cols; ++j) {
                row_sum += std::abs(data[i * Cols + j]);
            }
            sum = std::max(sum, row_sum);
        }
        return sum;
    } else {
        for(int i = 0; i < Rows; ++i) {
            for (int j = 0; j < Cols; ++j) {
                T element = data[i * Cols + j];
                sum += std::pow(std::abs(element), static_cast<int>(type));
            }
        }
        return std::pow(sum, T(1) / static_cast<int>(type));
    }
}

template<typename T, int Rows, int Cols>
MatrixX<T, Rows, Cols> MatrixX<T, Rows, Cols>::normalize() const{
    T norm_val = this->norm();
    if (norm_val == T(0)) {
        throw std::invalid_argument("Cannot normalize a zero-matrix");
    }
    return this->operator/(norm_val);
}

// Display
template<typename T, int Rows, int Cols>
void MatrixX<T, Rows, Cols>::display() const {
    std::cout << "MatrixX<" << typeid(T).name() << ", " << Rows << ", " << Cols << ">" << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    for(int i = 0; i < Rows; ++i) {
        for (int j = 0; j < Cols; ++j) {
            std::cout << data[i * Cols + j] << " ";
        }
        std::cout << std::endl;
    }
}