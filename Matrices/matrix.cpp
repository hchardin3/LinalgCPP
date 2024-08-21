#include "matrix.hpp"

template<typename T>
MatrixX<T>::MatrixX(int rows, int cols) : num_rows(rows), num_cols(cols), data(VectorX<T>(num_rows * num_cols)) {}

template<typename T>
MatrixX<T> MatrixX<T>::Zero(int rows, int cols) {
    MatrixX<T> result(num_rows * num_cols);
    result.data = VectorX<T>::Zero(num_rows * num_cols);
    return result;
}

template<typename T>
MatrixX<T> MatrixX<T>::One(int rows, int cols) {
    MatrixX<T> result(num_rows * num_cols);
    result.data = VectorX<T>::One(num_rows * num_cols);
    return result;
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
                sum += data[i * num_cols + k] * other.data[k * other.num_cols + j];
            }
            result.data[i * other.num_cols + j] = sum;
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

// Utils
template<typename T>
std::list<int> MatrixX<T>::shape() const {return std::list<int>({num_rows, num_cols});}

template<typename T>
VectorX<T> MatrixX<T>::flatten() const {return data;}

template<typename T>
MatrixX<T> MatrixX<T>::transpose() const {
    MatrixX result(num_cols, num_rows);
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