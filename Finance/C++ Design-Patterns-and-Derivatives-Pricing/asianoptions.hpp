#ifndef ASIAN_HPP
#define ASIAN_HPP
#include <vector>
// exercise 3.1
class AsianOption {
    protected:
        PayOff2* pay_off; // pay_off class (in this instance call/put)

    public:
        AsianOption(PayOff2* _pay_off);
        ~AsianOption(){};

        // pure virtual pay-pff operator. This will determine wether arithmetic or geometric
        virtual double pay_off_price(const std::vector<double>& spot_prices) const = 0;
};

class AsianOptionArithmetic : public AsianOption {
    public:
        AsianOptionArithmetic(PayOff2* _pay_off);
        virtual ~ AsianOptionArithmetic(){};

        //override
        virtual double pay_off_price(const std::vector<double>& spot_prices) const;
};

class AsianOptionGeometric : public AsianOption {
    public:
        AsianOptionGeometric(PayOff2* _pay_off);
        virtual ~AsianOptionGeometric(){};

        //override
        virtual double pay_off_price(const std::vector<double>& spot_prices) const;
};

#endif