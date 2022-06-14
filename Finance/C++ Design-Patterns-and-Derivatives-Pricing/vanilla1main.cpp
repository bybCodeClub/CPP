#include "SimpleMC3.cpp"
#include "doubledigital.cpp"
#include "vanilla1.cpp"
#include <iostream>

using namespace std;

int main() {
    double Expiry;
    double Low, Up;
    double Spot;
    double Vol;
    double r;
    unsigned long NumberOfPaths;

    cout << "Enter expiry \n";
    cin >> Expiry;

    cout << "Enter low \n";
    cin >> Low;

    cout << "Enter Up \n";
    cin >> Up;

    cout << "Enter spot \n";
    cin >> Spot;

    cout << "Enter vol \n";
    cin >> Vol;

    cout << "Enter r \n";
    cin >> r;

    cout << "Enter Number of paths \n";
    cin >> NumberOfPaths;

    PODoubleDigital thePayOff(Low, Up);

    VanillaOption theOption(thePayOff, Expiry);

    double result = SimpleMonteCarlo3(
        theOption,
        Spot,
        Vol,
        r,
        NumberOfPaths
    );

    cout << "The price is " << result << "\n";

    double tmp;
    cin >> tmp;
    return 0;
}