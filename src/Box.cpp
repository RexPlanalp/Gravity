#include "Box.h"
#include "Particle.h"

void Box::checkBoundary(Particle& p)
{
    if (p.position.x() >= xWidth / 2)
    {   
        p.position.x() = xWidth / 2;
        p.velocity = p.velocity - 2 * dot(p.velocity,xHat) * (xHat);
    }
    else if (p.position.x() <= -xWidth / 2)
    {   
        p.position.x() = -xWidth / 2;
        p.velocity = p.velocity - 2 * dot(p.velocity,-xHat) * (-xHat);
    }

    else if (p.position.y() >= yWidth / 2)
    {   
        p.position.y() = yWidth / 2;
        p.velocity = p.velocity - 2 * dot(p.velocity,yHat) * (yHat);
    }
    else if (p.position.y() <= -yWidth / 2)
    {   
        p.position.y() = -yWidth / 2;
        p.velocity = p.velocity - 2 * dot(p.velocity,-yHat) * (-yHat);
    }

    else if (p.position.z() >= zWidth / 2)
    {
        p.position.z() = zWidth / 2;
        p.velocity = p.velocity - 2 * dot(p.velocity,zHat) * (zHat);
    }
    else if (p.position.z() <= -zWidth / 2)
    {   
        p.position.z() = -zWidth / 2;
        p.velocity = p.velocity - 2 * dot(p.velocity,-zHat) * (-zHat);
    }
   
}