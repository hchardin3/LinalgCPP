#include "vector.hpp"
#include "matrix.hpp"

// Constructor
template <typename T>
VectorX<T>::VectorX(int size) : Size(size), data(size) {}

// Static Factory Methods
template <typename T>
VectorX<T> VectorX<T>::Zero(int size) {
    VectorX<T> vec(size);
    std::fill(vec.data.begin(), vec.data.end(), static_cast<T>(0));
    return vec;
}

template <typename T>
VectorX<T> VectorX<T>::One(int size) {
    VectorX<T> vec(size);
    std::fill(vec.data.begin(), vec.data.end(), static_cast<T>(1));
    return vec;
}

template <typename T>
VectorX<T> VectorX<T>::Unit(int size, int direction) {
    if (direction < 0 || direction >= size) {
        throw std::out_of_range("Direction index out of range");
    }
    VectorX<T> vec = Zero(size);
    vec.data[direction] = static_cast<T>(1);
    return vec;
}

template <typename T>
VectorX<T> VectorX<T>::Random(int size, T min, T max) {
    if (size <= 0) {
        throw std::invalid_argument("Size must be a positive integer");
    }
    VectorX<T> vec(size);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<T> dis(min, max);

    for (int i = 0; i < size; ++i) {
        vec.data[i] = dis(gen);
    }
    return vec;
}

// Operators
template <typename T>
VectorX<T> VectorX<T>::operator+(const VectorX<T>& other) const {
    if (size != other.size) {
        throw std::invalid_argument("Vectors must have the same size for addition");
    }
    VectorX<T> result(size);
    for (int i = 0; i < size; i++) {
        result.data[i] = data[i] + other.data[i];
    }
    return result;
}

template <typename T>
VectorX<T> VectorX<T>::operator-(const VectorX<T>& other) const {
    if (size != other.size) {
        throw std::invalid_argument("Vectors must have the same size for subtraction");
    }
    VectorX<T> result(size);
    for (int i = 0; i < size; i++) {
        result.data[i] = data[i] - other.data[i];
    }
    return result;
}

template <typename T>
VectorX<T> VectorX<T>::operator*(const T& value) const {
    VectorX<T> result(size);
    for (int i = 0; i < size; i++) {
        result.data[i] = data[i] * value;
    }
    return result;
}

template <typename T>
VectorX<T> VectorX<T>::operator/(const T& value) const {
    if (value == 0) {
        throw std::invalid_argument("Division by zero is not allowed");
    }
    VectorX<T> result(size);
    for (int i = 0; i < size; i++) {
        result.data[i] = data[i] / value;
    }
    return result;
}

template <typename T>
VectorX<T> VectorX<T>::operator*(const MatrixX<T>& matrix) const {
    if (!is_transposed) {
        throw std::invalid_argument("Vector must be transposed for multiplication");
    }
    std::list<int> shape = matrix.shape();
    if (size != shape[0]) {
        throw std::invalid_argument("Vector size does not match matrix row size for multiplication");
    }
    VectorX<T> result = Zero(shape[1]);
    result.transpose();
    for (int j = 0; j < shape[1]; j++) {
        for (int i = 0; i < size; i++) {
            result.data[j] += data[i] * matrix(i, j);
        }
    }
    return result;
}

template <typename T>
VectorX<T> VectorX<T>::operator+=(const VectorX<T>& other) {
    if (size!= other.size) {
        throw std::invalid_argument("Vectors must have the same size for addition");
    }
    for (int i = 0; i < size; i++) {
        data[i] += other.data[i];
    }
    return *this;
}

template <typename T>
VectorX<T> VectorX<T>::operator-=(const VectorX<T>& other) {
    if (size!= other.size) {
        throw std::invalid_argument("Vectors must have the same size for subtraction");
    }
    for (int i = 0; i < size; i++) {
        data[i] -= other.data[i];
    }
    return *this;
}

template <typename T>
T VectorX<T>::operator[](int index) const {
    if (index < 0) {
        index += size;
    }
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

// Utils
template <typename T>
bool VectorX<T>::isTransposed() const {
    return is_transposed;
}

template <typename T>
void VectorX<T>::transpose() {
    is_transposed = !is_transposed;
}

template <typename T>
T VectorX<T>::norm() const {
    T sum = 0;
    for (int i = 0; i < size; i++) {
        sum += data[i] * data[i];
    }
    return std::sqrt(sum);
}

template <typename T>
VectorX<T> VectorX<T>::normalize() const {
    T magnitude = norm();
    if (magnitude == 0) {
        throw std::runtime_error("Cannot normalize a zero vector");
    }
    return *this / magnitude;
}

template <typename T>
T VectorX<T>::dot(const VectorX<T>& other) const {
    if (size!= other.size) {
        throw std::invalid_argument("Vectors must have the same size for dot product");
    }
    T sum = 0;
    for (int i = 0; i < size; i++) {
        sum += data[i] * other.data[i];
    }
    return sum;
}

template <typename T>
T VectorX<T>::distance(const VectorX<T>& other) const {
    VectorX<T> diff = *this - other;
    return diff.norm();
}

template <typename T>
int VectorX<T>::size() const {return Size; }




// Display
template <typename T>
void VectorX<T>::display() const {
    std::cout << "[";
    for (int i = 0; i < size; i++) {
        if (i < size - 1) {
            std::cout << data[i] << ", ";
        } else {
            std::cout << data[i];
        }
    }
    std::cout << "]" << std::endl;
}

// Explicit template instantiation
template class VectorX<int>;
template class VectorX<double>;
