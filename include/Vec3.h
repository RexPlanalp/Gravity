

#ifndef VEC3_H
#define VEC3_H

#include <iostream>
#include "utility.h"


class Box;

class Vec3
{
    public:

        // Default constructor: Initializes to zero vector
        Vec3();

        // Parameterized constructor
        Vec3(double x, double y, double z);

        // Getter methods for components
        double x() const;
        double& x();

        double y() const;
        double& y();

        double z() const;
        double& z();

        // - overload
        Vec3 operator-() const;

       // [] overload
        double operator[](int idx) const;
        double& operator[](int idx);

        // += overload
        Vec3& operator+=(const Vec3& V);
        

        // -= overload
        Vec3& operator-=(const Vec3& V);
        

        // *= overload
        Vec3& operator*=(double t);

        // /= overload
        Vec3& operator/=(double t);

        // Norm 
        double length() const;

        // Norm Squared
        double length_squared() const;

        static Vec3 random();
        
      

        static Vec3 random(double min, double max);
       
        static Vec3 random(const Box& box);
       

            

        



        



    private:
        double components[3];
};

std::ostream& operator<<(std::ostream& out, const Vec3& V);

Vec3 operator+(const Vec3& U, const Vec3& V);

Vec3 operator-(const Vec3& U, const Vec3& V);

Vec3 operator*(const Vec3& U, const Vec3& V);


Vec3 operator*(double t, const Vec3& V);

Vec3 operator*(const Vec3& V,double t);

Vec3 operator/(const Vec3& V, double t);

double dot(const Vec3& U, const Vec3& V);

Vec3 cross(const Vec3& U, const Vec3& V);

Vec3 unit_vector(const Vec3& V);





#endif