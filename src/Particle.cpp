#include "Particle.h"


double kineticEnergy(const std::shared_ptr<Particle> p)
{
    return 0.5 * p->mass * p->velocity.length_squared();
}