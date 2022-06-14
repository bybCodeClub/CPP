#include "random1.hpp"
#include <algorithm>    // Needed for the "max" function
#include <cmath>

// basic functions should be available in std namespace but are not in VCPP6

using namespace std;


double getOneGaussianBySummation(){
    double result = 0;
    for(unsigned int j = 0; j < 12; j++) 
        result += rand()/static_cast<double>(RAND_MAX);

    result -= 6.0;

    return result;
}

double gaussian_box_muller() {
  double x = 0.0;
  double y = 0.0;
  double euclid_sq = 0.0;

  // Continue generating two uniform random variables
  // until the square of their "euclidean distance" 
  // is less than unity
  do {
    x = 2.0 * rand() / static_cast<double>(RAND_MAX)-1;
    y = 2.0 * rand() / static_cast<double>(RAND_MAX)-1;
    euclid_sq = x*x + y*y;
  } while (euclid_sq >= 1.0);

  return x*sqrt(-2*log(euclid_sq)/euclid_sq);
}


// exercise 3.1 - c++ design patterns and derivative pricing
// this will allow our exotic/asian options
// This provides a vector containing sampled points of a geometric
// brownian motion stock price path..
void calc_path_spot_prices(
  std::vector<double>& spot_prices,
  const double& r, // risk free rate
  const double& v, // volatility
  const double& T  // Time
) {
  double dt = T/static_cast<double>(spot_prices.size());
  double drift = exp(dt*(r-0.5*v*v));
  double vol = sqrt(v*v*dt);

  for(int i = 1; i < spot_prices.size(); i++){
    double gauss_bm = gaussian_box_muller();
    spot_prices[i] = spot_prices[i-1] * drift * exp(vol*gauss_bm);
  }
}
