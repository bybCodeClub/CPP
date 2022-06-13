// using payOff2 using the virtual keyword and inheritance with our monte clarlo 2 implementation
#include "SimpleMC.cpp"
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
    cout << "\nEnter Strike\n";
    cin >> Strike;
    cout << "\nEnter Spot\n";
    cin >> Spot;
    cout << "\nEnter Vol\n";
    cin >> Vol;
    cout << "\nEnter r\n";
    cin >> r;
    cout << "\nEnter number of paths\n";
    cin >> NumberOfPaths;

    PayOffCall callPayOff(Strike);

    PayOffPut putPayOff(Strike);

    double resultCall = SimpleMonteCarlo2(
        callPayOff,
        Expiry,
        Spot,
        Vol,
        r,
        NumberOfPaths
    );

    double resultPut = SimpleMonteCarlo2(
        putPayOff,
        Expiry,
        Spot,
        Vol,
        r,
        NumberOfPaths
    );

    cout << "Call price is " <<  resultCall << " and the put price is " << resultPut << "\n";

    int tmp;
    cin >> tmp;
    return 0;
}