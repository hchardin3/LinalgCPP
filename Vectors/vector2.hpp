#pragma once

#include <iostream>
#include <utility>
#include <vector>
#include <type_traits>
#include "vector.hpp"
#include "row_vector2.hpp"

template<typename T>
class RowVector2; 

template <typename T>
class Vector2 : public Vector<T, 2> {
    public:
    // Constructor that initializes the base class with size 2
    Vector2();

    Vector2(const T& x, const T& y);

    Vector2(const Vector<T, 2>& vector);

    Vector2(const Matrix<T, 2, 1>& matrix);

    /**
     * @brief Returns a Vector2 with all components set to zero.
     *
     * This static function creates and returns a Vector2 object with all components initialized to zero.
     *
     * @return A Vector2 object with all components set to zero.
     */
    static Vector2 Zero();

    /**
    * @brief Returns a Vector2 with all components set to one.
    *
    * This static function creates and returns a Vector2 object with all components initialized to one.
    *
    * @return A Vector2 object with all components set to one.
    */
    static Vector2 One();

    /**
    * @brief Returns a Vector2 with a unit vector in the specified direction.
    *
    * This static function creates and returns a Vector2 object with a unit vector in the specified direction.
    * The direction is specified by an integer value, where 0 represents the x-axis, 1 represents the y-axis,
    * and any other value results in a zero vector.
    *
    * @param direction The direction of the unit vector. 0 for x-axis, 1 for y-axis.
    *
    * @return A Vector2 object representing a unit vector in the specified direction.
    */
    static Vector2 Unit(int direction);

    // Access x, y directly
    T& x() { return this->data[0]; }
    const T& x() const { return this->data[0]; }

    T& y() { return this->data[1]; }
    const T& y() const { return this->data[1]; }

    // Functions
    /**
     * @brief Calculates the angle between this Vector2 and another Vector2 in radians.
     *
     * This function calculates the angle between this Vector2 and another Vector2 using the dot product formula.
     * The angle is measured in radians, with a positive value indicating a counter-clockwise rotation.
     *
     * @param other The other Vector2 to calculate the angle with.
     *
     * @return The angle between this Vector2 and the other Vector2 in radians.
     */
    T angle(const Vector2<T>& other) const;

    /**
     * @brief Rotates this Vector2 by the specified angle in radians.
     *
     * This function creates and returns a new Vector2 object that represents the result of rotating this Vector2
     * by the specified angle in radians. The rotation is performed counter-clockwise.
     *
     * @param angle The angle in radians to rotate this Vector2 by. A positive value indicates a counter-clockwise rotation.
     *
     * @return A new Vector2 object representing the result of rotating this Vector2 by the specified angle.
     */
    Vector2<T> rotate(T angle) const;

    // Rewrite transpose
    /**
     * @brief Transposes this Vector2 object and returns a new RowVector2 object.
     *
     * This function creates and returns a new RowVector2 object that represents the transpose of this Vector2.
     * In the context of 2D vectors, transposing a Vector2 means swapping its x and y components.
     *
     * @return A new RowVector2 object representing the transpose of this Vector2.
     */
    RowVector2<T> transpose() const;

};

#include "vector2.inl"

// Custom vector types
using Vector2f = Vector2<float>;
using Vector2d = Vector2<double>;
using Vector2i = Vector2<int>;