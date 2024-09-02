#pragma once

#include <iostream>
#include <utility>
#include <vector>
#include <type_traits>
#include "row_vector.hpp"
#include "vector2.hpp"
#include "../Matrices/matrix2.hpp"
#include "../Matrices/matrix.hpp"

template <typename T>
class RowVector2 : public RowVector<T, 2> {
    public:
    // Constructor that initializes the base class with size 2
    RowVector2();

    RowVector2(const RowVector<T, 2>& other);

    RowVector2(const Matrix<T, 1, 2>& other);

    RowVector2(const T& x, const T& y);

    // Special constructors
    /**
     * @brief Creates a new RowVector2 instance initialized with zeros.
     *
     * This function returns a new RowVector2 instance where both x and y components are set to zero.
     *
     * @return A new RowVector2 instance with both x and y components set to zero.
     */
    static RowVector2 Zero();

    /**
    * @brief Creates a new RowVector2 instance initialized with ones.
    *
    * This function returns a new RowVector2 instance where both x and y components are set to one.
    *
    * @return A new RowVector2 instance with both x and y components set to one.
    */
    static RowVector2 One();
    
    /**
    * @brief Creates a new RowVector2 instance initialized with a unit vector in the specified direction.

    *
    * This function returns a new RowVector2 instance where the x and y components are set based on the given direction.
    * The direction is specified by an integer value, where:
    * - 0: Unit vector in the positive x direction (1, 0)
    * - 1: Unit vector in the positive y direction (0, 1)
    *
    * @param direction The direction of the unit vector.
    * @return A new RowVector2 instance representing the unit vector in the specified direction.
    */
    static RowVector2 Unit(int direction);

    // Access x, y directly
    T& x() { return this->data[0]; }
    const T& x() const { return this->data[0]; }

    T& y() { return this->data[1]; }
    const T& y() const { return this->data[1]; }

    // Functions
    /**
     * @brief Calculates the angle between this RowVector2 instance and another RowVector2 instance.
     *
     * This function calculates the angle in radians between this RowVector2 instance and another RowVector2 instance.
     * The angle is measured in the counter-clockwise direction from the positive x-axis.
     *
     * @param other The other RowVector2 instance to calculate the angle with.
     * @return The angle in radians between this RowVector2 instance and the other RowVector2 instance.
     *         The angle is in the range [-π, π].
     */
    T angle(const RowVector2<T>& other) const;

    /**
    * @brief Rotates this RowVector2 instance by the specified angle in radians.
    *
    * This function creates a new RowVector2 instance that represents the result of rotating this RowVector2 instance
    * by the specified angle in radians. The rotation is performed counter-clockwise around the origin.
    *
    * @param angle The angle in radians to rotate this RowVector2 instance by.
    * @return A new RowVector2 instance representing the result of the rotation.
    *
    * @note The angle is in the range [-π, π].
    */
    RowVector2<T> rotate(T angle) const;


    // Transpose Method
    /**
     * @brief Transposes this RowVector2 instance into a Vector2 instance.
     *
     * This function creates a new Vector2 instance that represents the transpose of this RowVector2 instance.
     * In the context of vectors, the transpose of a row vector is a column vector.
     *
     * @return A new Vector2 instance representing the transpose of this RowVector2 instance.
     *
     * @note This function overrides the base class's transpose method to provide a specific implementation for RowVector2.
     */
    Vector2<T> transpose() const override;

};

#include "row_vector2.inl"

// Custom vector types
using RowVector2f = RowVector2<float>;
using RowVector2d = RowVector2<double>;
using RowVector2i = RowVector2<int>;