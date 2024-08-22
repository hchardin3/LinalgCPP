#include "matrix.hpp"
#include "vector.hpp"

template<typename T>
MatrixX<T>::MatrixX(int rows, int cols) : num_rows(rows), num_cols(cols), data(num_rows * num_cols) {}

template<typename T>
MatrixX<T> MatrixX<T>::Zero(int rows, int cols) {
    MatrixX<T> result(num_rows, num_cols);
    result.data = VectorX<T>::Zero(num_rows * num_cols);
    return result;
}

template<typename T>
MatrixX<T> MatrixX<T>::One(int rows, int cols) {
    MatrixX<T> result(num_rows * num_cols);
    result.data = VectorX<T>::One(num_rows * num_cols);
    return result;
}

template<typename T>
MatrixX<T> MatrixX<T>::Identity(int size) {
    MatrixX result = MatrixX::Zero(size, size);
    for (int i = 0; i < size; ++i) {
        result(i, i) = static_cast<T>(1);
    }
}

// Operators
template<typename T>
MatrixX<T> MatrixX<T>::operator+(const MatrixX& other) const {
    if (num_rows!= other.num_rows || num_cols!= other.num_cols) {
        throw std::invalid_argument("Matrices must have the same dimensions for addition");
    }

    MatrixX result(num_rows, num_cols);
    for (int i = 0; i < num_rows; ++i) {
        for (int j = 0; j < num_cols; ++j) {
            result.data[i * num_cols + j] = data[i * num_cols + j] + other.data[i * num_cols + j];
        }
    }
    return result;
}

template<typename T>
MatrixX<T> MatrixX<T>::operator-(const MatrixX& other) const {
    if (num_rows!= other.num_rows || num_cols!= other.num_cols) {
        throw std::invalid_argument("Matrices must have the same dimensions for subtraction");
    }

    MatrixX result(num_rows, num_cols);
    for (int i = 0; i < num_rows; ++i) {
        for (int j = 0; j < num_cols; ++j) {
            result.data[i * num_cols + j] = data[i * num_cols + j] - other.data[i * num_cols + j];
        }
    }
    return result;
}

template<typename T>
MatrixX<T> MatrixX<T>::operator*(const MatrixX& other) const {
    if (num_cols!= other.num_rows) {
        throw std::invalid_argument("Matrices must have compatible dimensions for multiplication");
    }

    MatrixX result(num_rows, other.num_cols);
    for (int i = 0; i < num_rows; ++i) {
        for (int j = 0; j < other.num_cols; ++j) {
            T sum = 0;
            for (int k = 0; k < num_cols; ++k) {
                sum += data[i * num_rows + k] * other.data[k * other.num_rows + j];
            }
            result.data[i * num_rows + j] = sum;
        }
    }
    return result;
}

template<typename T>
MatrixX<T> MatrixX<T>::operator*(const T& scalar) const {
    MatrixX result(num_rows, num_cols);
    for (int i = 0; i < num_rows; ++i) {
        for (int j = 0; j < num_cols; ++j) {
            result.data[i * num_cols + j] = data[i * num_cols + j] * scalar;
        }
    }
    return result;
}

template<typename T>
MatrixX<T> MatrixX<T>::operator/(const T& scalar) const {
    if (scalar == 0) {
        throw std::invalid_argument("Division by zero is not allowed");
    }

    MatrixX result(num_rows, num_cols);
    for (int i = 0; i < num_rows; ++i) {
        for (int j = 0; j < num_cols; ++j) {
            result.data[i * num_cols + j] = data[i * num_cols + j] / scalar;
        }
    }
    return result;
}

template<typename T>
MatrixX<T> MatrixX<T>::operator+=(const MatrixX& other) {
    if (num_rows!= other.num_rows || num_cols!= other.num_cols) {
        throw std::invalid_argument("Matrices must have the same dimensions for addition");
    }

    for (int i = 0; i < num_rows; ++i) {
        for (int j = 0; j < num_cols; ++j) {
            data[i * num_cols + j] += other.data[i * num_cols + j];
        }
    }
    return *this;
}

template<typename T>
MatrixX<T> MatrixX<T>::operator-=(const MatrixX& other) {
    if (num_rows!= other.num_rows || num_cols!= other.num_cols) {
        throw std::invalid_argument("Matrices must have the same dimensions for subtraction");
    }

    for (int i = 0; i < num_rows; ++i) {
        for (int j = 0; j < num_cols; ++j) {
            data[i * num_cols + j] -= other.data[i * num_cols + j];
        }
    }
    return *this;
}

template<typename T>
VectorX<T> MatrixX<T>::operator*(const VectorX<T>& other) const {
    if (num_cols!= other.size()) {
        throw std::invalid_argument("Matrix and vector dimensions must match for multiplication");
    }

    VectorX<T> result = VectorX<T>::Zero(num_rows);
    for (int i = 0; i < num_rows; ++i) {
        for (int j = 0; j < num_cols; ++j) {
            result[i] += data[i * num_rows + j] * other[j];
        }
    }
    return result;
}

// Accessors
template <typename T>
T& MatrixX<T>::operator()(int i, int j) {
    if(i < 0) {i += num_rows;}
    if(j < 0) {j += num_cols;}
    if (i < 0 || i >= num_rows || j < 0 || j >= num_cols) {
        throw std::out_of_range("Index out of range");
    }
    return data[i * num_cols + j];
}

template <typename T>
const T& MatrixX<T>::operator()(int i, int j) const {
    if(i < 0) {i += num_rows;}
    if(j < 0) {j += num_cols;}
    if (i < 0 || i >= num_rows || j < 0 || j >= num_cols) {
        throw std::out_of_range("Index out of range");
    }
    return data[i * num_cols + j];
}

template <typename T>
std::vector<T> MatrixX<T>::operator()(All, int j) const {
    if(j < 0) {j += num_cols;}
    if (j < 0 || j >= num_cols) {
        throw std::out_of_range("Index out of range");
    }
    std::vector<T> column(num_rows);
    for (int i = 0; i < num_rows; ++i) {
        column[i] = data[i * num_cols + j];
    }
    return column;
}

template <typename T>
std::vector<T> MatrixX<T>::operator()(int i, All) const {
    if(i < 0) {i += num_rows;}
    if (i < 0 || i >= num_rows) {
        throw std::out_of_range("Index out of range");
    }
    std::vector<T> row(num_cols);
    for (int j = 0; j < num_cols; ++j) {
        row[j] = data[i * num_cols + j];
    }
    return row;
}

template <typename T>
MatrixX<T> MatrixX<T>::operator()(Range row_range, Range col_range) const {
    int row_start = row_range.start < 0 ? row_range.start + num_rows : row_range.start;
    int row_end = row_range.end < 0 ? row_range.end + num_rows : row_range.end;
    int col_start = col_range.start < 0 ? col_range.start + num_cols : col_range.start;
    int col_end = col_range.end < 0 ? col_range.end + num_cols : col_range.end;

    if (row_start < 0 || row_end > num_rows || col_start < 0 || col_end > num_cols || row_start > row_end || col_start > col_end) {
        throw std::out_of_range("Submatrix index out of range");
    }

    MatrixX<T> submatrix(row_end - row_start, col_end - col_start);
    for (int i = row_start; i < row_end; ++i) {
        for (int j = col_start; j < col_end; ++j) {
            submatrix(i - row_start, j - col_start) = (*this)(i, j);
        }
    }
    return submatrix;
}

template <typename T>
MatrixX<T> MatrixX<T>::operator()(Range row_range, int j) const {
    int row_start = row_range.start < 0 ? row_range.start + num_rows : row_range.start;
    int row_end = row_range.end < 0 ? row_range.end + num_rows : row_range.end;

    if (row_start < 0 || row_end > num_rows || j < 0 || j >= num_cols || row_start > row_end) {
        throw std::out_of_range("Submatrix index out of range");
    }

    MatrixX<T> submatrix(row_end - row_start, 1);
    for (int i = row_start; i < row_end; ++i) {
        submatrix(i - row_start, 0) = (*this)(i, j);
    }
    return submatrix;
}

template <typename T>
MatrixX<T> MatrixX<T>::operator()(int i, Range col_range) const {
    int col_start = col_range.start < 0 ? col_range.start + num_cols : col_range.start;
    int col_end = col_range.end < 0 ? col_range.end + num_cols : col_range.end;

    if (i < 0 || i >= num_rows || col_start < 0 || col_end > num_cols || col_start > col_end) {
        throw std::out_of_range("Submatrix index out of range");
    }

    MatrixX<T> submatrix(1, col_end - col_start);
    for (int j = col_start; j < col_end; ++j) {
        submatrix(0, j - col_start) = (*this)(i, j);
    }
    return submatrix;
}

// Utils
template<typename T>
std::list<int> MatrixX<T>::shape() const {return std::list<int>({num_rows, num_cols});}

template<typename T>
VectorX<T> MatrixX<T>::flatten() const {return data;}

template<typename T>
MatrixX<T> MatrixX<T>::reshape(int new_rows, int new_cols) const {
    if(num_rows * num_cols != new_rows * new_cols) {
        throw std::invalid_argument("Reshaping is not possible with the current shape");
    }
    MatrixX<T> result(new_rows, new_cols);
    result.data = this->data;
    return result;
}

template<typename T>
MatrixX<T> MatrixX<T>::transpose() const {
    MatrixX<T> result(num_cols, num_rows);
    for (int i = 0; i < num_rows; ++i) {
        for (int j = 0; j < num_cols; ++j) {
            result.data[j * num_cols + i] = data[i * num_rows + j];
        }
    }
    return result;
}  

// Display
template<typename T>
void MatrixX<T>::display() const {
    std::cout << "["
    for (int i = 0; i < num_rows; ++i) {
        for (int j = 0; j < num_cols; ++j) {
            if (j > 0) {
                std::cout << ", " << data[i * num_cols + j];
            } else {
                std::cout << data[i * num_cols + j] << " ";
            }
        }
        std::cout << std::endl;
    }
    std::cout << "]" << std::endl;
}


/// Class MatrixS
template<typename T>
T MatrixS<T>::trace() const {
    T result = 0;
    for (int i = 0; i < num_rows; ++i) {
        result += data[i * num_cols + i];
    }
    return result;
}

template<typename T>
MatrixS<T> MatrixS<T>::power(int n) const {
    if(n < 0) {
        throw std::invalid_argument("Exponent must be non-negative");
    } else if (n == 0) {
        return MatrixS<T>::identity(this->num_rows);
    } else if (n == 1) {
        return *this;
    } else {
        MatrixS<T> result = (*this);
        for(int i = 1; i < n; ++i) {    
            result *= (*this);
        }
    }

}