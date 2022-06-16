// this implementation will take advantage if our payoff2 class and 
// show how we can be extended without changing any existing code.

#ifndef DOUBLEDIGITIAL_H
#define DOUBLEDIGITIAL_H

#include "payoff2.hpp"
#include "payoff3.hpp"

class PODoubleDigital : public PayOff3 {
    public:
        PODoubleDigital(double LowerLevel, double UpperLevel);

        virtual ~PODoubleDigital(){}

        virtual double operator()(double Spot) const;

        virtual PayOff3* clone() const;

    private:
        double LowerLevel;
        double UpperLevel;
};

#endif