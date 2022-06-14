#include "SimpleMC3.hpp"
#include "random1.cpp"
#include <cmath>

double SimpleMonteCarlo3(
    const VanillaOption& TheOption, // passing by reference this time compared to by value before
    double Spot,
    double Vol,
    double r,
    unsigned long NumberOfPaths
){
    double Expiry = TheOption.GetExpiry();  // new

    double variance = Vol*Vol*Expiry;
    double rootVariance = sqrt(variance);
    double itoCorrection = -0.5*variance;

    double movedSpot = Spot*exp(r*Expiry +itoCorrection);
    double thisSpot;
    double runningSum = 0;

    for(unsigned long i = 0; i < NumberOfPaths; i++){
        double thisGaussian = gaussian_box_muller();
        thisSpot = movedSpot * exp(rootVariance * thisGaussian);
        runningSum += TheOption.OptionPayOff(thisSpot); // new way of handling the options payoff
    }   

    double mean = runningSum / NumberOfPaths;
    mean *= exp(-r*Expiry);
    return mean;
}