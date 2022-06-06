#ifndef PAYOFF_HPP
#define PAYOFF_HPP

class PayOff {
    public:
        enum OptionType {call, put};
        PayOff(double Strike_, OptionType TheOpetionsType_);
        double operator()(double Spot) const;
    
    private:
        double Strike;
        OptionType TheOptionsType;
};

#endif