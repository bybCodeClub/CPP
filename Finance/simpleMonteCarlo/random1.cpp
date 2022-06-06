#include "random1.hpp"
#include <cstdlib>
#include <cmath>

// basic functions should be available in std namespace but are not in VCPP6
#if !defined(_MSC_VER)
using namespace std;
#endif

double getOneGaussianBySummation(){
    double result = 0;
    for(unsigned int j = 0; j < 12; j++) 
        result += rand()/static_cast<double>(RAND_MAX);

    result -= 6.0;

    return result;
}

double getOneGaussianByBoxMuller(){
    double result;
    double x, y;
    double sizedSquared;

    do {
        x = 2*rand()/static_cast<double>(RAND_MAX)-1;
        y = 2*rand()/static_cast<double>(RAND_MAX)-1;
        sizedSquared = x*x + y*y;
    } while(sizedSquared >= 1.0);

    result = x*sqrt(-2*log(sizedSquared/sizedSquared));

    return result;
}