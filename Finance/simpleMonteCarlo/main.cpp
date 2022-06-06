#include "random1.cpp"
#include <iostream>
#include <algorithm> 
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
    PayOff digitalPayOff(Strike, PayOff::digital);
    PayOff ddigitalPayOff(Strike, PayOff::double_digital);
    
    double resultCall = SimpleMonteCarlo2(callPayOff, Expiry, Spot, Vol, r, numberOfPaths);

    double resultPut = SimpleMonteCarlo2(putPayOff, Expiry, Spot, Vol, r, numberOfPaths);

    double resultDdigital = SimpleMonteCarlo2(ddigitalPayOff, Expiry, Spot, Vol, r, numberOfPaths);

    double resultdigital = SimpleMonteCarlo2(digitalPayOff, Expiry, Spot, Vol, r, numberOfPaths);

    cout << "the prices are " << resultCall << " for the call and " << resultPut << " for the put\n";
    cout << "digital prices are " << resultdigital << " and the double digital price is " << resultDdigital << "\n";

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
    unsigned int NumberOfPaths // 10000000
){
    // double Variance = Vol*Vol*Expiry;
    // double rootVariance = sqrt(Variance);
    // double itoCorrection = -0.5*Variance;

    double movedSpot = Spot * exp(Expiry*(r-0.5*Vol*Vol));
    double thisSpot;
    double runningSum = 0;
    for(unsigned int i = 0 ; i < NumberOfPaths; i++) {
        double thisGaussian = gaussian_box_muller();
        thisSpot = movedSpot * exp(sqrt(Vol*Vol*Expiry)*thisGaussian);
        runningSum += std::max(thisSpot - Strike, 0.0);  // call
    }
    double mean = (runningSum / static_cast<double>(NumberOfPaths)) * exp(-r*Expiry);
    cout << "The call option: " << mean << '\n';
    // return mean;
}