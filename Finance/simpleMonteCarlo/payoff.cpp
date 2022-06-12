#include "payoff.hpp"
#include <cmath>


PayOff::PayOff(double Strike_, OptionType TheOptionsType_)
    :
        Strike(Strike_), TheOptionsType(TheOptionsType_)
    {}


double PayOff::heavey_side(const double& val) const {
    if( val >= 0 ){
        return 1.0;
    } else {
        return 0.0;
    }
} 

double PayOff::payoff_double_digital(double K_L, double K_U, double x) const {
    if( x >= K_L && x <= K_U ) {
        return 1.0;
    } else {
        return 0.0;
    }
}

double PayOff::operator()(double spot) const {
    switch(TheOptionsType) {
        case call : return std::max(spot - Strike, 0.0);
        case put : return std::max(Strike - spot, 0.0); 
        case digital : return heavey_side(spot - Strike);
        case double_digital: return payoff_double_digital(Strike, Strike+20.0, spot);
        default: throw("Uknown option type found");
    }
} 