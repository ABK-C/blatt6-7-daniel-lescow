#ifndef VOLLZYLINDER_HH
#define VOLLZYLINDER_HH

#include "Vektor.hh"

class Vollzylinder {
public:
  Vollzylinder(double nr, double nl);

  Vektor punkt();

private:
  double r_, l_;
};

#endif
