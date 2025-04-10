#ifndef PARTICLE_H
#define PARTICLE_H

#include "Vec3.h"
#include <memory>

class Particle
{
    public:
        Particle() : position{0.0,0.0,0.0}, velocity{0.0,0.0,0.0}, mass{0.0} {}
        Particle(Vec3 position, Vec3 velocity, double mass) : position(position), velocity(velocity), mass(mass) {}


        Vec3 position;
        Vec3 velocity;
        double mass;
    
};

double kineticEnergy(const std::shared_ptr<Particle> p);



#endif