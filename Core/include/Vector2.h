#ifndef VECTOR_2__
#define VECTOR_2__

#include "Log.h"
#include <string>

template <typename T>
struct Vector2
{
    Vector2(T _x,T _y);
    static Vector2<T> Zero;
    static Vector2<T> One;

    void operator+=(Vector2<T> const& rhs);
    void operator-=(Vector2<T> const& rhs);
    void operator*=(Vector2<T> const& rhs);
    void operator/=(Vector2<T> const& rhs);

    void operator+=(T const& rhs);
    void operator-=(T const& rhs);
    void operator*=(T const& rhs);
    void operator/=(T const& rhs);
    
    T GetMagnitude();
    void Normalize();
    T Dot(Vector2<T> const& other);

    std::string ToString();

    T x;
    T y;
};

#include "Vector2.inl"

typedef Vector2<float> Vector2f;
typedef Vector2<int> Vector2i;

#endif
