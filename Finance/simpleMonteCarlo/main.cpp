#include "random1.cpp"
#include <iostream>
#include <cmath>
#include "SimpleMC.cpp"
#include "payoff.cpp"

using namespace std;

//Monte carlo implementation
void simpleMonteCarlo1(
    double Expiry,
    double Strike,
    double Spot,
    double Vol,
    double r, 
    unsigned int NumberOfPaths
);

int main() {
    double Expiry;
    double Strike;
    double Spot;
    double Vol;
    double r;
    unsigned long numberOfPaths;

    cout << "\nEnter expiry date";
    cin >> Expiry;
    cout << "\nEnter Strike";
    cin >> Strike;
    cout << "\nEnter Spot";
    cin >> Spot;
    cout << "\nEnter Vol";
    cin >> Vol;
    cout << "\nEnter r";
    cin >> r;
    cout << "\nEnter number of paths";
    cin >> numberOfPaths;

    PayOff callPayOff(Strike, PayOff::call);
    PayOff putPayOff(Strike, PayOff::put);

    double resultCall = SimpleMonteCarlo2(callPayOff, Expiry, Spot, Vol, r, numberOfPaths);

    double resultPut = SimpleMonteCarlo2(putPayOff, Expiry, Spot, Vol, r, numberOfPaths);
    cout <<"the prices are " << resultCall
        << " for the call and "
        << resultPut
        << " for the put\n";

    simpleMonteCarlo1(Expiry, Strike, Spot, Vol, r, numberOfPaths);

    double tmp;
    cin >> tmp;
    return 0;
}

void simpleMonteCarlo1(
    double Expiry,
    double Strike,
    double Spot,
    double Vol,
    double r, 
    unsigned int NumberOfPaths
){
    double Variance = Vol*Vol*Expiry;
    double rootVariance = sqrt(Variance);
    double itoCorrection = -0.5*Variance;

    double movedSpot = Spot * exp(r*Expiry +itoCorrection);
    double thisSpot;
    double runningSum = 0;
    double otherRunningSum = 0;
    for(unsigned int i = 0 ; i < NumberOfPaths; i++) {
        double thisGaussian = getOneGaussianByBoxMuller();
        thisSpot = movedSpot * exp(rootVariance * thisGaussian);

        double thisPayoff = thisSpot - Strike;  // call
        
        thisPayoff = thisPayoff > 0 ? thisPayoff : 0;
        
        runningSum += thisPayoff;
      
    }

    double mean = runningSum / NumberOfPaths;
    mean *= exp(-r*Expiry);

    cout << "The call option: " << mean << '\n';
    // return mean;
}