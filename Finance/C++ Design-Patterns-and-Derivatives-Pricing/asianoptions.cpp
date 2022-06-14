#include "asianoptions.hpp"
#include "payoff2.hpp"
#include <cmath>
#include <numeric>

// asian option 
AsianOption::AsianOption(PayOff2* _pay_off) : pay_off(_pay_off) {}

// asian option arithmetic
AsianOptionArithmetic::AsianOptionArithmetic(PayOff2* _pay_off) : AsianOption(_pay_off) {}

    // arithmertic mean price
double AsianOptionArithmetic::pay_off_price( const std::vector<double>& spot_prices) const {
    unsigned num_times = spot_prices.size();
    double sum = std::accumulate(spot_prices.begin(), spot_prices.end(), 0);
    double arith_mean = sum / static_cast<double>(num_times);
    return (*pay_off)(arith_mean);
}


// asian option geometric
AsianOptionGeometric::AsianOptionGeometric(PayOff2* _pay_off) : AsianOption(_pay_off) {}

    // geometric mean pay-off price
double AsianOptionGeometric::pay_off_price( const std::vector<double>& spot_prices) const {
    unsigned num_times = spot_prices.size();
    double log_sum = 0.0;
    for(int i = 0; i < spot_prices.size(); i++) {
        log_sum += log(spot_prices[i]);
    }
    double geo_mean = exp(log_sum / static_cast<double>(num_times) );
    return (*pay_off)(geo_mean);
}