#ifndef VOLLZYLINDER_HH
#define VOLLZYLINDER_HH

#include "Vektor.hh"
#include "Koerper.hh"

class Vollzylinder : public Koerper {
public:
  Vollzylinder(double nr, double nl, double nm);

  Vektor punkt();

  std::string name(){return "Vollzylinder";}

  double M();

  double J_an();

private:
  double r_, l_, m_;
};

#endif