#ifndef VECTOR_H_
#define VECTOR_H_





class Vector2
{
    public:
    double x, y;

    Vector2() {this->x = 0; this->y = 0; };
    Vector2(double x_, double y_) {this->x = x_; this->y = y_; };
    Vector2(const Vector2& other) {this->x = other.x; this->y = other.y; };


    Vector2 operator+(const Vector2& other);
    Vector2 & operator+=(const Vector2& other);
    Vector2 operator-(const Vector2& other);
    Vector2 & operator-=(const Vector2& other);
    Vector2 operator*(const double& scalar);
    Vector2 & operator*=(const double& scalar);
    Vector2 operator/(const double& scalar);
    Vector2 & operator/=(const double& scalar);

    friend Vector2 operator*(const double& scalar, const Vector2& v);


    double mag() const;
    double mag_squared() const;
    void normalize();

};

double dot_product(const Vector2& v1, const Vector2& v2);





#endif