#include "vanilla3.hpp"

VanillaOption3::VanillaOption3(const PayOffBridge&  ThePayOff_, double Expiry_)
        : ThePayOff(ThePayOff_), Expiry(Expiry_)
    {

    }

double VanillaOption3::GetExpiry() const {
    return Expiry;
}

double VanillaOption3::OptionPayOff(double Spot) const {
    return ThePayOff(Spot);
}