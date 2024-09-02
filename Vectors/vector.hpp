#pragma once

#include <iostream>
#include <utility>
#include <vector>
#include <type_traits>
#include "../Matrices/matrix.hpp"
#include "../Utils/range.hpp"
#include "../Utils/types.hpp"
#include "row_vector.hpp"

template<typename T, int Size = DynamicSize>
class RowVector; 

template <typename T, int Size>
class Vector : public Matrix<T, Size, 1> {
public:
    // Constructor
    Vector();

    Vector(int size);

    Vector(const Matrix<T, Size, 1>& mat);

    // Unit vector function
    /**
    * @brief Creates a new Vector object with all elements initialized to zero.
    *
    * This function constructs a Vector object of the specified size, where all elements are initialized to zero.
    * If no size is provided, the default size specified by the template parameter 'Size' is used.
    *
    * @param size The size of the Vector object to be created. If not provided, the default size is used.
    * @return A new Vector object with all elements initialized to zero.
    */
    static Vector Zero(int size = Size);

    /**
    * @brief Creates a new Vector object with all elements initialized to one.
    *
    * This function constructs a Vector object of the specified size, where all elements are initialized to one.
    * If no size is provided, the default size specified by the template parameter 'Size' is used.
    *
    * @param size The size of the Vector object to be created. If not provided, the default size is used.
    * @return A new Vector object with all elements initialized to one.
    */
    static Vector One(int size = Size);

    /**
    * @brief Creates a new Vector object with a single element set to one and all others set to zero.
    *
    * This function constructs a Vector object of the specified size, where the element at the specified 'direction' index is set to one,
    * and all other elements are initialized to zero. If no size is provided, the default size specified by the template parameter 'Size' is used.
    *
    * @param size The size of the Vector object to be created. If not provided, the default size is used.
    * @param direction The index of the element to be set to one. If not provided, the default value is 0.
    * @return A new Vector object with a single element set to one and all others set to zero.
    */
    static Vector Unit(int size = Size, int direction = 0);

    // Overloading the [] operator
    T& operator[](int i);

    const T& operator[](int i) const;

    // Overloading the () operator
    T& operator()(int i);

    const T& operator()(int i) const;

    // Transpose Method
    /**
     * @brief Computes the transpose of the current Vector object.
     *
     * This function returns a new RowVector object that represents the transpose of the current Vector object.
     * The transpose of a Vector is obtained by swapping its rows and columns.
     *
     * @return A new RowVector object representing the transpose of the current Vector object.
     */
    RowVector<T, Size> transpose() const;

    // Additional vector-specific methods can be added here
    /**
     * @brief Returns the size of the Vector object.
     *
     * This function returns the number of elements in the Vector object.
     * If the size is not explicitly specified during object creation, the default size specified by the template parameter 'Size' is used.
     *
     * @return The size of the Vector object.
     */
    int size() const;

    /**
     * @brief Computes the dot product of the current Vector object with another Vector object.
     *
     * This function calculates the dot product of the current Vector object with another Vector object.
     * The dot product is a scalar value obtained by multiplying corresponding elements of the two Vectors and summing the results.
     * If the sizes of the two Vectors are not equal, the function will throw an exception.
     *
     * @param other The Vector object with which to compute the dot product.
     * @return The dot product of the current Vector object with the 'other' Vector object.
     * @throws std::invalid_argument If the sizes of the two Vectors are not equal.
     */
    T dot(const Vector& other) const;
};

#include "vector.inl"

// Custom vector types
using VectorXf = Vector<float, DynamicSize>;
using VectorXd = Vector<double, DynamicSize>;
using VectorXi = Vector<int, DynamicSize>;
