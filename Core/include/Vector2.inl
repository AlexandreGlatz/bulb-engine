#include <cmath>
#include <string>

template <typename T>
Vector2<T>::Vector2(T _x, T _y)
{
    x = _x, y = _y;
}

template <typename T>
std::string Vector2<T>::ToString()
{
    return "x : " + std::to_string(x) +" y : " + std::to_string(y);
}

template <typename T>
void Vector2<T>::operator+=(Vector2<T> const& rhs)
{
    x += rhs.x;
    y += rhs.y;
}

template <typename T>
void Vector2<T>::operator-=(Vector2<T> const& rhs)
{
    x -= rhs.x;
    y -= rhs.y;
}

template <typename T>
void Vector2<T>::operator*=(Vector2<T> const& rhs)
{
    x *= rhs.x;
    y *= rhs.y;
}

template <typename T>
void Vector2<T>::operator/=(Vector2<T> const& rhs)
{
    x /= rhs.x;
    y /= rhs.y;
}

template <typename T>
Vector2<T> operator+(Vector2<T> lhs, Vector2<T> const& rhs)
{
    lhs += rhs;
    return lhs;
}

template <typename T>
Vector2<T> operator-(Vector2<T> lhs, Vector2<T> const& rhs)
{
    lhs -= rhs;
    return lhs;
}

template <typename T>
Vector2<T> operator/(Vector2<T> lhs, Vector2<T> const& rhs)
{
    lhs /= rhs;
    return lhs;
}

template <typename T>
void Vector2<T>::operator+=(T const& rhs)
{
    x += rhs;
    y += rhs;
}

template <typename T>
void Vector2<T>::operator-=(T const& rhs)
{
    x -= rhs;
    y -= rhs;
}

template <typename T>
void Vector2<T>::operator*=(T const& rhs)
{
    x *= rhs;
    y *= rhs;
}

template <typename T>
void Vector2<T>::operator/=(T const& rhs)
{
    x /= rhs;
    y /= rhs;
}

template <typename T>
Vector2<T> operator+(Vector2<T> lhs, T const& rhs)
{
    lhs += rhs;
    return lhs;
}

template <typename T>
Vector2<T> operator-(Vector2<T> lhs, T const& rhs)
{
    lhs -= rhs;
    return lhs;
}

template <typename T>
Vector2<T> operator*(Vector2<T> lhs, T const& rhs)
{
    lhs *= rhs;
    return lhs;
}

template <typename T>
Vector2<T> operator/(Vector2<T> lhs, T const& rhs)
{
    lhs /= rhs;
    return lhs;
}

template <typename T>
T Vector2<T>::GetMagnitude()
{
    return std::sqrt(x*x+y*y);
}

template <typename T>
void Vector2<T>::Normalize()
{
    *this /= GetMagnitude();
}

template <typename T>
T Vector2<T>::Dot(Vector2<T> const& other)
{
    return x * other.x + y * other.y;
}
