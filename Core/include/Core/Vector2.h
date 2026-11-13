#ifndef VECTOR_2__
#define VECTOR_2__

#include "Define.h"

#include <string>

namespace bulb
{

template <typename T>
struct Vector2
{
    Vector2(T _x,T _y);

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

    union
    {
        T x;
        T width;
        T r;
    };
    union
    {
        T y;
        T height;
        T g;
    };
};

typedef Vector2<float> Vector2f;
typedef Vector2<int16> Vector2i;
}

#include "Vector2.inl"

#endif
