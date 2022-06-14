// chapter 4. At this point we have two peices of data. Expiry and the Payoff
// it would be more natural to have 1, the Option. Well encapsulate these ina class
// and use a refference to our PayOff object. Then explore the problems of this approach.

#ifndef VANILLA_1_HPP
#define VANILLA_1_HPP

#include "payoff2.hpp"

class VanillaOption {
    public:
        VanillaOption(PayOff2& ThePayOff_, double Expiry_);
        double GetExpiry() const;
        double OptionPayOff(double Spot) const;
    private:
        double Expiry;
        PayOff2& ThePayOff;
};

#endif