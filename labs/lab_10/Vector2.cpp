#include "Vector2.h"
#include <stdexcept>

Vector2::Vector2(float x, float y) : x(x), y(y) {}

float& Vector2::operator[](size_t index) {
    if (index == 0) return x;
    else if (index == 1) return y;
    throw std::out_of_range("Index must be 0 or 1");
}

Vector2& Vector2::operator+=(const Vector2& other) {
    x += other.x;
    y += other.y;
    return *this;
}

Vector2& Vector2::operator-=(const Vector2& other) {
    x -= other.x;
    y -= other.y;
    return *this;
}

Vector2& Vector2::operator*=(float value) {
    x *= value;
    y *= value;
    return *this;
}

Vector2& Vector2::operator/=(float value) {
    if (value == 0) throw std::invalid_argument("Division by zero");
    x /= value;
    y /= value;
    return *this;
}

Vector2 operator+(const Vector2& a, const Vector2& b) {
    return Vector2(a.x + b.x, a.y + b.y);
}

Vector2 operator-(const Vector2& a, const Vector2& b) {
    return Vector2(a.x - b.x, a.y - b.y);
}

Vector2 operator*(const Vector2& vector, float value) {
    return Vector2(vector.x * value, vector.y * value);
}

Vector2 operator*(float value, const Vector2& vector) {
    return vector * value;
}

Vector2 operator/(const Vector2& vector, float value) {
    if (value == 0) throw std::invalid_argument("Division by zero");
    return Vector2(vector.x / value, vector.y / value);
}

std::ostream& operator<<(std::ostream& out, const Vector2& vector) {
    out << "(" << vector.x << ", " << vector.y << ")";
    return out;
}