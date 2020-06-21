#include "Vollzylinder.hh"

#include <cmath>
#include <cstdlib>

Vollzylinder::Vollzylinder(double nr, double nl) {
  r_ = nr;
  l_ = nl;
}

Vektor Vollzylinder::punkt() {
  double R = r_ * sqrt(rand() / (double)RAND_MAX);
  double phi = 2 * M_PI * rand() / (double)RAND_MAX;
  double z = l_ * (rand() / (double)RAND_MAX - 0.5);

  double x = R * cos(phi);
  double y = R * sin(phi);
  return Vektor(x, y, z);
};
