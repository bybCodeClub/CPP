#ifndef SIMPLEMC_HPP
#define SIMPLEMC_HPP

#include "payoff.hpp"

double SimpleMonteCarlo2(
    const PayOff& thePayOff,    // replaced strike
    double Expiry,
    double Spot,
    double Vol,
    double r,
    unsigned long NumberOfPaths
);

#endif