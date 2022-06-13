#include <iostream>
#include "doubledigital.cpp"
#include "SimpleMC.cpp"

using namespace std;
int main(){
    double Expiry;
    double Low, Up;
    double Spot;
    double Vol;
    double r;
    unsigned long NumberOfPaths;

    cout << "\nEnter expiry\n";
    cin >> Expiry;
    cout << "\nEnter Low\n";
    cin >> Low;
    cout << "\nEnter Up\n";
    cin >> Up;
    cout << "\nEnter Spot\n";
    cin >> Spot;
    cout << "\nEnter Vol\n";
    cin >> Vol;
    cout << "\nEnter r\n";
    cin >> r;
    cout << "\nEnter number of paths\n";
    cin >> NumberOfPaths;

    PODoubleDigital thePayOff(Low, Up);

    double result = SimpleMonteCarlo2(
        thePayOff,
        Expiry,
        Spot,
        Vol,
        r,
        NumberOfPaths
    );

    cout << "\nThe price is " << result << "\n";
    double tmp;
    cin >> tmp;

    return 0;
}