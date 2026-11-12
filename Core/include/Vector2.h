#ifndef VECTOR_2__
#define VECTOR_2__

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

#include "Vector2.inl"

typedef Vector2<float> Vector2f;
typedef Vector2<int> Vector2i;

#endif
