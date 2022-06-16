#include "payoff3.hpp"

//payoff call

PayOffCall2::PayOffCall2(double Strike_)
    :   Strike(Strike_)
{

}

double PayOffCall2::operator()(double Spot) const {
    return max(spot- Strike, 0.0);
}

PayOff3* PayOffCall2::clone() const {
    return new PayOffCall2(*this);
}

//payoff put

PayOffPut2::PayOffPut2(double Strike_)
    : Strike(Strike_)
{

}

double PayOffPut2::operator()(double Spot) const{
    return max(Strike-Spot, 0.0);
}

PayOff3* PayOffPut2::clone() const{
    return new PayOffPut2(this);
}
