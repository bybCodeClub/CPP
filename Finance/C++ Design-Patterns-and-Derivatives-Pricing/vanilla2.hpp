#ifndef VANILLA_2_H
#define VANILLA_2_H

#include "payoff3.hpp"

class VanillaOption2 : public PayOff3 {
    private:
        double Expiry;
        PayOff3* ThePayOffPtr;
    public:
        VanillaOption2(const VanillaOption2& original);

        VanillaOption2& operator=(const VanillaOption2& original);

        double GetExpiry() const;

        double OptionPayoff(double Spot) const;

};

#endif