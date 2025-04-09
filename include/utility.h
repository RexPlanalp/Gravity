#ifndef UTILITY_H
#define UTILITY_H


#include <limits>
#include <random>

const double infinity = std::numeric_limits<double>::infinity();
const double epsilon = std::numeric_limits<double>::epsilon();

inline double degrees_to_radians(double angle_degrees)
{
    return angle_degrees * M_PI / (180.0);
}

inline double random_double()
{
    static std::random_device rd;
    static std::seed_seq ss{rd(),rd(),rd(),rd(),rd(),rd(),rd(),rd()};
    static std::mt19937 mt{ ss };
    static std::uniform_real_distribution<> dis(0.0,1.0);
    return dis(mt);
}

inline double random_double(double min, double max)
{
    return min + (max - min)*random_double();
}





#endif