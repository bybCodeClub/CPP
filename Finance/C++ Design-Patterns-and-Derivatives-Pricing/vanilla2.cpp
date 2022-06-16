#include "vanilla2.hpp"

VanillaOption2::VanillaOption2(const PayOff3& ThePayOff_, double Expiry)
    :
{
    ThePayOffPtr = ThePayOff_.clone();
}

double VanillaOption2::GetExpiry() const{
    return Expiry;
}

double VanillaOption2::OptionPayoff(double Spot) const {
    return (*ThePayOffPtr)(Spot);
}

VanillaOption2::VanillaOption2(const VanillaOption2& original) {
    Expiry = original.Expiry;
    ThePayOffPtr = original.TheyPayOffPtr->clone();
}

VanillaOption2& VanillaOption2::operator=(const VanillaOption2& original) {
    if(this != original) {
        Expiry = original.Expiry;
        delete ThePayOffPtr;
        ThePayOffPtr = original.ThePayOffPtr->clone();
    }
    return *this;
}

VanillaOption2::VanillaOption2(){
    delete ThePayOffPtr;
}

