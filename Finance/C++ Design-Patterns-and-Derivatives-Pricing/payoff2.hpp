#ifndef PAYOFF2_HPP
#define PAYOFF2_HPP

class PayOff2 {
    public:
        PayOff2(){};
        virtual double operator()(double Spot) const = 0;
        virtual ~PayOff2(){};
    private:
};

class PayOffCall : public PayOff2 {
    public:
        PayOffCall(double Strike_);
        virtual double operator()(double Spot) const;
        virtual ~PayOffCall(){};
    private:
        double Strike;
};

class PayOffPut : public PayOff2 {
    public:
        PayOffPut(double Strike_);
        virtual double operator()(double Spot) const;
        virtual ~PayOffPut(){};
    private:
        double Strike;
};

#endif