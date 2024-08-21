#include "vector.hpp"

template<typename T>
class Vector2 : public VectorX<T> {
    public:
    Vector2() : VectorX<T>(2) {}
};