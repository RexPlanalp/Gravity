#include "Vec3.h"
#include "Box.h"
#include <cassert>
#include "utility.h"


// Constructors
Vec3::Vec3() : components{0.0,0.0,0.0} {}
Vec3::Vec3(double x, double y, double z) : components{x,y,z} {}


// Getters for components
double Vec3::x() const {return components[0];}
double& Vec3::x() {return components[0];}

double Vec3::y() const {return components[1];}
double& Vec3::y() {return components[1];}

double Vec3::z() const {return components[2];}
double& Vec3::z() {return components[2];}

// Overloads

double Vec3::operator[](int idx) const
{
    assert(idx >= 0 && idx < 3 && "Index out of bounds!");
    return components[idx];
}
double& Vec3::operator[](int idx)
{
    assert(idx >= 0 && idx < 3 && "Index out of bounds!");
    return components[idx];
}

Vec3 Vec3::operator-() const
{
    return Vec3(-x(),-y(),-z());
}

Vec3& Vec3::operator+=(const Vec3& V)
{
    x() += V.x();
    y() += V.y();
    z() += V.z();
    return*this;
}

Vec3& Vec3::operator-=(const Vec3& V)
{
    return *this += -V;
}

Vec3& Vec3::operator*=(double t)
{
    x() *= t;
    y() *= t;
    z() *= t;
    return *this;
}

Vec3& Vec3::operator/=(double t)
{   
    assert(std::abs(t) > epsilon && "Cannot divide by zero");
    return *this *= (1/t);
}

double Vec3::length() const
{
    return std::sqrt(length_squared());
}

double Vec3::length_squared() const
{
    return x()*x() + y()*y() + z()*z();
}

//////////// Helper Funcs///////////////
std::ostream& operator<<(std::ostream& out, const Vec3& V)
{
    return out << V.x() << ' ' << V.y() << ' ' << V.z();
}

Vec3 operator+(const Vec3& U, const Vec3& V)
{
    return Vec3(U.x()+V.x(),U.y()+V.y(),U.z()+V.z());
}

Vec3 operator-(const Vec3& U, const Vec3& V)
{
    return Vec3(U.x()-V.x(),U.y()-V.y(),U.z()-V.z());
}

Vec3 operator*(const Vec3& U, const Vec3& V)
{
    return Vec3(U.x()*V.x(),U.y()*V.y(),U.z()*V.z());
}

Vec3 operator*(double t, const Vec3& V)
{
    return  Vec3(t*V.x(),t*V.y(),t*V.z());
}

Vec3 operator*(const Vec3& V,double t)
{
    return  t*V;
}

Vec3 operator/(const Vec3& V, double t)
{   
    assert(std::abs(t) > std::numeric_limits<double>::epsilon() && "Cannot divide by zero");
    return (1/t)*V;
}

double dot(const Vec3& U, const Vec3& V)
{
    return U.x()*V.x() + U.y()*V.y()+U.z()*V.z();
}

Vec3 cross(const Vec3& U, const Vec3& V) 
{
    return Vec3(U.y() * V.z() - U.z() * V.y(),U.z() * V.x() - U.x() * V.z(),U.x() * V.y() - U.y() * V.x());
}

Vec3 unit_vector(const Vec3& V)
{
    return V / V.length();
}


Vec3 Vec3::random()
{
    return Vec3(random_double(),random_double(),random_double());
}


Vec3 Vec3::random(double min, double max)
{
    return Vec3(random_double(min,max),random_double(min,max),random_double(min,max));
}
Vec3 Vec3::random(const Box& box)
{
    return Vec3(random_double(-box.xWidth / 2.0,box.xWidth / 2.0),random_double(-box.yWidth / 2.0,box.yWidth / 2.0),random_double(-box.zWidth / 2.0,box.zWidth / 2.0));
}
    

