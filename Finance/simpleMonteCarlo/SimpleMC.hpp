#ifndef SIMPLEMC_HPP
#define SIMPLEMC_HPP

#include "payoff.hpp"
#include "payoff2.hpp"

double SimpleMonteCarlo2(
    PayOff& thePayOff,    // replaced strike
    double Expiry,
    double Spot,
    double Vol,
    double r,
    unsigned long NumberOfPaths
);

#endif