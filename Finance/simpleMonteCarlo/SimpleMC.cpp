#include "SimpleMC.hpp"
#include "random1.cpp"
#include <cmath>
#include "payoff.hpp" 
#include "payoff2.cpp"

using namespace std;

double SimpleMonteCarlo2(
    PayOff& thePayOff, // if PayOff2& is type then its set for payOff2Maincpp
    double Expiry,
    double Spot,
    double Vol,
    double r,
    unsigned long NumberOfPaths
    ){
        double variance = Vol*Vol*Expiry;
        double rootVariance = sqrt(variance);
        double itoCorrection = -0.5*variance;

        double movedSpot = Spot * exp(r*Expiry +itoCorrection);
        double thisSpot;
        double runningSum = 0.0;

        for(unsigned long i=0; i < NumberOfPaths; i++) {
            double thisGaussian = gaussian_box_muller();
            thisSpot = movedSpot * exp(rootVariance * thisGaussian);
            runningSum += thePayOff(thisSpot);
             
        }
        double mean = runningSum / NumberOfPaths;
        mean *= exp(-r*Expiry);
        return mean;
    }