#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <cmath>
#include <stdexcept>
#include <random>
#include <vector>
#include "matrix.hpp"

template<typename T>
class VectorX {
protected:
    int size;
    std::vector<T> data;
    bool is_transposed = false; // True if the VectorX is transposed (row VectorX), false by default (column VectorX)
    
public:
    // Constructor
    VectorX(int size = 10);

    static VectorX<T> Zero(int size);
    static VectorX<T> One(int size);
    static VectorX<T> Unit(int size, int direction);
    static VectorX<T> Random(int size, T min, T max);

    // Operators
    VectorX<T> operator+(const VectorX<T>& other) const;
    VectorX<T> operator-(const VectorX<T>& other) const;
    VectorX<T> operator*(const T& value) const;
    VectorX<T> operator/(const T& value) const;
    VectorX<T> operator*(const MatrixX<T>& matrix) const;

    VectorX<T> operator+=(const VectorX<T>& other);
    VectorX<T> operator-=(const VectorX<T>& other);

    T operator[](int index) const;

    // Utils
    bool isTransposed() const;
    void transpose();
    T norm() const;
    VectorX<T> normalize() const;
    T dot(const VectorX<T>& other) const;
    T distance(const VectorX<T>& other) const;
    int size() const;

    // Display
    void display() const;
};

class VectorXd : public VectorX<double> {
public:
    // Constructor
    VectorXd(int size) : VectorX<double>(size) {}
};

class VectorXi : public VectorX<int> {
public:
    // Constructor
    VectorXi(int size) : VectorX<int>(size) {}
};

#endif // VECTOR_HPP