#ifndef RANDOM1_HPP
#define RANDOM1_HPP
#include <vector>

double getOneGaussianBySummation();

double gaussian_box_muller();

void calc_path_spot_prices(
  std::vector<double>&,
  const double&,
  const double&,
  const double& 
);

#endif