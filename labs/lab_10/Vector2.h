#pragma once

#include <iostream>

struct Vector2 {
public:
    float x, y;

    Vector2(float x = 0.0f, float y = 0.0f);

    float& operator[](size_t index);

    Vector2& operator+=(const Vector2& other);
    Vector2& operator-=(const Vector2& other);
    Vector2& operator*=(float scalar);
    Vector2& operator/=(float scalar);
};

Vector2 operator+(const Vector2& lhs, const Vector2& rhs);
Vector2 operator-(const Vector2& lhs, const Vector2& rhs);
Vector2 operator*(const Vector2& vec, float scalar);
Vector2 operator*(float scalar, const Vector2& vec);
Vector2 operator/(const Vector2& vec, float scalar);

std::ostream& operator<<(std::ostream& os, const Vector2& vec);
