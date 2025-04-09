#include "Universe.h"

#include "Box.h"
#include <memory>
#include "Vec3.h"
#include <iostream>
Universe::Universe(const Box& box, int N) : N(N)
{   
    double totalMass {0.0};
    for (int n = 0; n < N; n++)
    {   
        double m = random_double(1,2);
        totalMass += m;
        bodies.push_back(std::make_shared<Particle>(Vec3::random(box),Vec3::random(-1,1),m));
    }


    for (int n = 0; n < N; n++)
    {   
        bodies[n]->mass /= totalMass;
    }

    double totalPotentialEnergy {0.0};
    double totalKineticEnergy {0.0};
    for (int i = 0; i < N; i++)
    {
        totalKineticEnergy += kineticEnergy(bodies[i]);
        for (int j = i + 1; j < N; j++)
        {
            totalPotentialEnergy += potentialEnergy(bodies[i],bodies[j]);

        }
    }

    double scale = std::sqrt(2.0 * totalKineticEnergy / std::abs(totalPotentialEnergy));

    for (int n = 0; n < N; n++)
    {   
        bodies[n]->velocity /= scale;
    }

}


double Universe::potentialEnergy(const std::shared_ptr<Particle> p1, const std::shared_ptr<Particle> p2)
{
    return - (p1->mass * p2->mass) / ((p1->position-p2->position).length());
}

double Universe::kineticEnergy(const std::shared_ptr<Particle> p)
{
    return 0.5 * p->mass * p->velocity.length_squared();
}


void Universe::dumpInitial()
{
    for (int n = 0; n < N; n++)
    {
        std::clog << "Dumping particle: " << n + 1 << '\n' << std::flush;
        std::cout << bodies[n]->position << '\n';
    }
}