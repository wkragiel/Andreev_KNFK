#include "vector.h"
#include <cmath>


Vector2 Vector2::operator+(const Vector2& other) {
    return {this->x + other.x, this->y + other.y};
}

Vector2 & Vector2::operator+=(const Vector2& other) {
    this->x += other.x;
    this->y += other.y;
    return *this;
}

Vector2 Vector2::operator-(const Vector2& other) {
    return {this->x - other.x, this->y - other.y};
}

Vector2 & Vector2::operator-=(const Vector2& other) {
    this->x -= other.x;
    this->y -= other.y;
    return *this;
}

Vector2 Vector2::operator*(const double& scalar) {
    return {this->x * scalar, this->y * scalar};
}

Vector2 & Vector2::operator*=(const double& scalar) {
    this->x *= scalar;
    this->y *= scalar;
    return *this;
}

Vector2 Vector2::operator/(const double& scalar) {
    return {this->x / scalar, this->y / scalar};
}

Vector2 & Vector2::operator/=(const double& scalar) {
    this->x /= scalar;
    this->y /= scalar;
    return *this;
}

Vector2 operator*(const double& scalar, const Vector2& v){
    return {v.x * scalar, v.y * scalar};
}

double dot_product(const Vector2 &v1, const Vector2 &v2) {
    return v1.x * v2.x + v1.y * v2.y;
}

double Vector2::mag() const{
    return std::sqrt(this->mag_squared());
}

double Vector2::mag_squared() const {
    return this->x * this->x + this->y * this->y;
}

void Vector2::normalize() {
    double length = this->mag();
    this->x /= length;
    this->y /= length;
}

