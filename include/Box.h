#ifndef BOX_H
#define BOX_H

#include "Vec3.h"
#include "Particle.h"

class Box
{
    public: 

        Box() : center{0.0,0.0,0.0} {}
        Box(Vec3 center, double xWidth, double yWidth, double zWidth) : center(center), xWidth(xWidth), yWidth(yWidth), zWidth(zWidth) {}

        void checkBoundary(Particle& p);


        Vec3 center = Vec3(0.0,0.0,0.0);
        double xWidth = 1.0;
        double yWidth = 1.0;
        double zWidth = 1.0;

        const Vec3 xHat = Vec3(1.0,0.0,0.0);
        const Vec3 yHat = Vec3(0.0,1.0,0.0);
        const Vec3 zHat = Vec3(0.0,0.0,1.0);

    private:
        void reflectX();
        void reflectY();
        void reflectZ();

        

};  

#endif