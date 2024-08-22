#pragma once

#include "LinalgCPP.hpp"
#include <iostream>
#include <list>
#include "range.hpp"

template<typename T>
class VectorX;

template <typename T>
class MatrixX {
    protected:
        int num_rows;
        int num_cols;
        VectorX<T> data;

    public:
        // Constructor
        MatrixX(int rows, int cols);

        static MatrixX Zero(int rows, int cols);

        static MatrixX One(int rows, int cols);

        static MatrixX Identity(int size);

        // Operators
        MatrixX operator+(const MatrixX& other) const;

        MatrixX operator-(const MatrixX& other) const;

        MatrixX operator*(const MatrixX& other) const;

        MatrixX operator*(const T& scalar) const;

        MatrixX operator/(const T& scalar) const;

        MatrixX operator+=(const MatrixX& other);
        MatrixX operator-=(const MatrixX& other);

        VectorX<T> operator*(const VectorX<T>& other) const;

        // Accessors
        T& operator()(int i, int j);
        const T& operator()(int i, int j) const;

        std::vector<T> operator()(All, int j) const;
        std::vector<T> operator()(int i, All) const;

        MatrixX<T> operator()(Range row_range, Range col_range) const;
        MatrixX<T> operator()(Range row_range, int j) const;
        MatrixX<T> operator()(int i, Range col_range) const;

        // Utils
        std::list<int> shape() const;

        VectorX<T> flatten() const;

        MatrixX<T> reshape(int new_rows, int new_cols) const;

        MatrixX transpose() const;

        // Display
        void display() const;
};

class MatrixXd : public MatrixX<double> {
    public:
    MatrixXd(int rows, int cols) : MatrixX<double>(rows, cols) {}
};

class MatrixXi : public MatrixX<int> {
    public:
    MatrixXi(int rows, int cols) : MatrixX<int>(rows, cols) {}
};

class MatrixXf : public MatrixX<float> {
    public:
    MatrixXf(int rows, int cols) : MatrixX<float>(rows, cols) {}
};

template <typename T>
class MatrixS : public MatrixX<T> {
    public:
    MatrixS(int size) : MatrixX<T>(size, size) {}

    // Utils
    T trace() const;

    MatrixS<T> power(int n) const;

};