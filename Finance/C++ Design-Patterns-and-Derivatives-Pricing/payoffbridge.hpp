#ifndef PAYOFFBRIDGE_HPP
#define PAYOFFBRIDGE_HPP
#include "payoff3.hpp"

class PayOffBridge {
    public:
        PayOffBridge(const PayOffBridge& original);
        PayOffBridge(const PayOff& innerPayOff);

        inline double operator=(dpuble Spot);
        ~PayOffBridge();
        PayOffBridge& operator=(const PayOffBridge& original);
    private:
        PayOff3* TheyPayOffPtr;
};

inline double PayOffBridge::operator()(double Spot) const {
    return ThePayoffPtr->operator()(Spot);
}

#endif