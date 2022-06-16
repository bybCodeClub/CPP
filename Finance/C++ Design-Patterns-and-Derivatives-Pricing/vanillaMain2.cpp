#include "SimpleMC3.cpp" // set to be MC4
#include "vanilla2.cpp"
#include <iostream>

using namespace std;

int main() {
    double Expiry;
    double Strike;
    double Spot;
    double Vol;
    double r;
    unsigned long NumberOfPaths;
    cout << "\nEnter expiry\n";
    cin >> Expiry;
    cout << "\nStrike\n";
    cin >> Strike;
    cout << "\nEnter spot\n";
    cin >> Spot;
    cout << "\nEnter vol\n";
    cin >> Vol;
    cout << "\nr\n";
    cin >> r;
    cout << "\nNumber of paths\n";
    cin >> NumberOfPaths;

    PayOffCall2 thePayOff(Strike);
    VanillaOption2 theOption(thePayOff, Expiry);

    double result = SimpleMonteCarlo3(theOption,
    Spot,
    Vol,
    r,
    NumberOfPaths);

    cout <<"\nthe call price is " << result << "\n";

    VanillaOption2 secondOption(theOption);
    result = SimpleMonteCarlo3(secondOption,
    Spot,
    Vol,
    r,
    NumberOfPaths);

    cout <<"\nthe call price is " << result << "\n";

    PayOffPut2 otherPayOff(Strike);
    VanillaOption2 thirdOption(otherPayOff, Expiry);
    theOption = thirdOption;
    result = SimpleMonteCarlo3(theOption,
    Spot,
    Vol,
    r,
    NumberOfPaths);

    cout <<"\nthe put price is " << result << "\n";

    double tmp;
    cin >> tmp;    

    return 0;
}