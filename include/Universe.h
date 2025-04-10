#ifndef UNIVERSE_H
#define UNIVERSE_H

#include <memory>
#include <vector>
#include "Particle.h"
#include "Box.h"
#include <iostream>

class Universe
{
    public:

        Universe() : bodies{} {}
        Universe(const Box& box, int N);

        void dumpPositions(std::ostream& out);

    private:
        std::vector<std::shared_ptr<Particle>> bodies;

        double potentialEnergy(const std::shared_ptr<Particle> p1, const std::shared_ptr<Particle> p2);
        double kineticEnergy(const std::shared_ptr<Particle>);

        int N;


};

#endif 