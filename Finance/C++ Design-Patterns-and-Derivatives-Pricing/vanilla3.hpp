#ifndef VANILLA3_HPP
#define VANILLA3_HPP

#include "payoffbridge.hpp"

class VanillaOption3 {
    private: 
        double Expiry;
        PayOffBridge ThePayOff;
    public:
        VanillaOption3(const PayOffBridge& TheyPayOff_, double Expiry);
        double OptionPayOff(double Spot) const;
        double GetExpiry() const;

};

#endif