#include "Zylindermantel.hh"

#include <cmath>
#include <cstdlib>

Zylindermantel::Zylindermantel(double nr, double nl, double nm) {
  r_ = nr;
  l_ = nl;
  m_ = nm;
}

Vektor Zylindermantel::punkt() {
  double R = r_;
  double phi = 2 * M_PI * rand() / (double)RAND_MAX;
  double z = l_ * (rand() / (double)RAND_MAX - 0.5);

  double x = R * cos(phi);
  double y = R * sin(phi);
  return Vektor(x, y, z);
};

double Zylindermantel::J_an() {
  return m_*pow(r_,2);
}

double Zylindermantel::M() {
  return m_;
}
