#pragma once

#include <iostream>
#include <utility>
#include <vector>
#include <type_traits>
#include "row_vector.hpp"
#include "vector3.hpp"
#include "../Matrices/matrix3.hpp"

template <typename T>
class Vector3;

template <typename T>
class RowVector3 : public RowVector<T, 3> {
    public:
    // Constructor
    RowVector3();

    RowVector3(const RowVector<T, 3>& other);
    
    RowVector3(const T& x, const T& y, const T& z);

    RowVector3(const Matrix<T, 1, 3>& matrix);

    // Special constructors
    /**
     * @brief Creates a new RowVector3 instance initialized with zeros.
     *
     * This function returns a new RowVector3 instance where all components (x, y, z) are set to zero.
     *
     * @return A new RowVector3 instance with all components set to zero.
     */
    static RowVector3 Zero();

    /**
     * @brief Creates a new RowVector3 instance initialized with ones.
     *
     * This function returns a new RowVector3 instance where all components (x, y, z) are set to one.
     *
     * @return A new RowVector3 instance with all components set to one.
     */
    static RowVector3 One();

    /**
    * @brief Creates a new RowVector3 instance initialized with a unit vector in the specified direction.

    *
    * This function returns a new RowVector3 instance where the x, y and z components are set based on the given direction.
    * The direction is specified by an integer value, where:
    * - 0: Unit vector in the positive x direction (1, 0, 0)
    * - 1: Unit vector in the positive y direction (0, 1, 0)
    * - 2: Unit vector in the positive z direction (0, 0, 1)
    *
    * @param direction The direction of the unit vector.
    * @return A new RowVector3 instance representing the unit vector in the specified direction.
    */
    static RowVector3 Unit(int direction);

    // Access x, y, z directly
    T& x() { return this->data[0]; }
    const T& x() const { return this->data[0]; }

    T& y() { return this->data[1]; }
    const T& y() const { return this->data[1]; }

    T& z() { return this->data[2]; }
    const T& z() const { return this->data[2]; }

    // Specific utils
    /**
     *@brief Compute the cross-product of this RowVector3 with another insance of RowVector3.
     *
     * This function computes the cross-product of this RowVector3 with another RowVector3.
     * 
     * @param other Another instance of RowVector3
     * @return A new RowVector3 corresponding to the cross-product of this RowVector3 with the other instance of RowVector3
    */
    RowVector3<T> cross(const RowVector3<T>& other) const;

    // Transpose Method
    /**
     * @brief Transpose this instance of RowVector3 to a Vector3 object.
     * 
     * @return A Vector3 object corresponding to the transpose vector of this RowVector3.
     */
    Vector3<T> transpose() const;
    

};

#include "row_vector3.inl"

// Custom vector types
using RowVector3f = RowVector3<float>;
using RowVector3d = RowVector3<double>;
using RowVector3i = RowVector3<int>;