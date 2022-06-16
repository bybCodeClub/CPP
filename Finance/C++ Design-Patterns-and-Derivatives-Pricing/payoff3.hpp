// The problem when we encapsulated Expiry(T/time) and the payoff object in the vanillaOptions1 class
// and used a reference to our object in base class was we created a dependency issue. So instead we will 
// use a pure virtual copy constructor and override it in our inherited classes with a new pointer to
// our payoff object

#ifndef PAYOFF3_HPP
#define PAYOFF3_HPP

#include <cmath>

class PayOff3 {
    public:
        PayOff3(){};

        virtual double operator()(double Spot) const = 0;

        virtual PayOff3* clone() const = 0;

        ~virtual PayOff3(){}
    private:

};

class PayOffCall2 : public PayOff3 {
    private:
        double Strike;
    public:
        PayOffCall2(double Strike_);

        virtual double operator()(double Spot) const;

        virtual ~PayOffCall2(){}

        virtual PayOff3* clone() const;
};

class PayOffPut2 : public PayOff3 {
    private:
        double Strike;
    public:
        PayOffPut2(double Strike_);

        virtual double operator()(double Spot) const;

        virtual ~PayOffPut2(){}

        virtual PayOff3* clone() const;
};

#endif