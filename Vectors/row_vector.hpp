#pragma once

#include <iostream>
#include <utility>
#include <vector>
#include <type_traits>
#include "../Matrices/matrix.hpp"
#include "../Utils/range.hpp"
#include "../Utils/types.hpp"
#include "vector.hpp" 

template<typename T, int Size = DynamicSize>
class Vector; 

template <typename T, int Size>
class RowVector : public Matrix<T, 1, Size> {
public:
    // Constructor
    RowVector();

    RowVector(int size);

    RowVector(const Matrix<T, 1, Size>& other);

    // Unit vector function
    /**
    * @brief Creates a new RowVector with all elements initialized to zero.
    *
    * This function constructs a new RowVector of size 'n' with all elements initialized to zero.
    *
    * @param n The size of the RowVector to be created.
    * @return A new RowVector of size 'n' with all elements initialized to zero.
    */
    static RowVector Zero(int size = Size);

    /**
    * @brief Creates a new RowVector with all elements initialized to one.
    *
    * This function constructs a new RowVector of size 'n' with all elements initialized to one.
    *
    * @param n The size of the RowVector to be created.
    * @return A new RowVector of size 'n' with all elements initialized to one.
    */
    static RowVector One(int size = Size);
    
    /**
    * @brief Creates a new RowVector with a single element set to one and the rest set to zero.
    *
    * This function constructs a new RowVector of size 'size' with the 'direction'-th element set to one and all other elements set to zero.
    * If 'size' is not provided, the default size is determined by the template parameter 'Size'.
    *
    * @param size The size of the RowVector to be created. If not provided, the default size is used.
    * @param direction The index of the element to be set to one. The index is zero-based.
    * @return A new RowVector of size 'size' with the 'direction'-th element set to one and all other elements set to zero.
    */
    static RowVector Unit(int size = Size, int direction);

    // Overloading the [] operator
    T& operator[](int i);

    const T& operator[](int i) const;

    // Overloading the () operator
    T& operator()(int i);

    const T& operator()(int i) const;

    // Size Method
    /**
     * @brief Returns the size of the RowVector.
     *
     * This function returns the number of elements in the RowVector.
     *
     * @return The size of the RowVector.
     */
    int size() const;

    // Transpose Method
    /**
     * @brief Returns the transpose of the RowVector.
     *
     * This function creates a new Vector object by transposing the current RowVector.
     * The transpose of a RowVector is a Vector with the same number of elements as the original RowVector,
     * but with the rows and columns swapped.
     *
     * @return A new Vector object that is the transpose of the current RowVector.
     */
    Vector<T, Size> transpose() const;

    // Additional vector-specific methods can be added here
    /**
     * @brief Calculates the dot product of the current RowVector with another RowVector.
     *
     * This function computes the dot product of the current RowVector with another RowVector.
     * The dot product is a scalar value that represents the magnitude of the projection of one vector onto another.
     * It is calculated by multiplying corresponding elements of the two vectors and summing the results.
     *
     * @param other The other RowVector with which to calculate the dot product.
     * @return The dot product of the current RowVector with the 'other' RowVector.
     */
    T dot(const RowVector& other) const;
};

#include "row_vector.inl"

// Custom vector types
using RowVectorXf = RowVector<float, DynamicSize>;
using RowVectorXd = RowVector<double, DynamicSize>;
using RowVectorXi = RowVector<int, DynamicSize>;
