#ifndef SIMPLEMC3_HPP
#define SIMPLEMC3_HPP

//#include "vanilla1.hpp" // SimpleMC3
#include "vanilla2.hpp" // SimpleMC4

double SimpleMonteCarlo3(
    const VanillaOption& TheOption,
    double Spot,
    double Vol,
    double r,
    unsigned long NumberOfPaths
);

#endif