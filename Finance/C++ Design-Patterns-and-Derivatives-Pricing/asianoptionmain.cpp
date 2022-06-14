#include <iostream>
#include "payoff2.cpp"
#include "asianoptions.cpp"
#include "random1.cpp"
#include <cmath>

int main(int argc, char **argv) {
    //skipping user input for ths one.
    unsigned num_sims = 100000;
    unsigned num_intervals = 250;
    double S = 30.0; // option price
    double K = 29.0; // Strike price
    double r = 0.08; // risk free rate
    double v = 0.3; // volatility 
    double T = 1.00; // one year
    std::vector<double> spot_prices(num_intervals, S); // the vector of spot prices 

    // create the PayOff objects
    PayOff2* pay_off_call = new PayOffCall(K);

    // create the asian options object
    AsianOptionArithmetic asian(pay_off_call);

    // update the spot price vector with correct spot price paths
    // at constant intervals
    double payoff_sum = 0.0;

    for(int i = 0; i< num_sims; i++) {
        calc_path_spot_prices(spot_prices, r, v, T);
        payoff_sum += asian.pay_off_price(spot_prices);
    }

    double discount_payoff_avg = (payoff_sum / static_cast<double>(num_sims)) * exp(-r*T);

    delete pay_off_call;

    // output
    std::cout << "Number of Paths: " << num_sims << std::endl;
    std::cout << "Number of Ints:  " << num_intervals << std::endl;
    std::cout << "Underlying:      " << S << std::endl;
    std::cout << "Strike:          " << K << std::endl;
    std::cout << "Risk-Free Rate:  " << r << std::endl;
    std::cout << "Volatility:      " << v << std::endl;
    std::cout << "Maturity:        " << T << std::endl;

    std::cout << "Asian Price:     " << discount_payoff_avg << std::endl;
    return 0;
}