#ifndef PAYOFF_HPP
#define PAYOFF_HPP

class PayOff {
    public:
        enum OptionType {call, put, digital, double_digital};
        PayOff(double Strike_, OptionType TheOpetionsType_);

        double operator()(double Spot) const;

        double heavey_side(const double&) const;

        double payoff_double_digital(double, double, double) const;
    
    private:
        double Strike;
        double Strike_U;
        OptionType TheOptionsType;
};

#endif