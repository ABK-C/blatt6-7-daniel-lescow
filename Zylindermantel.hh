#ifndef ZYLINDERMANTEL_HH
#define ZYLINDERMANTEL_HH

#include "Vektor.hh"
#include "Koerper.hh"

class Zylindermantel : public Koerper {
public:
  Zylindermantel(double nr, double nl, double nm);

  Vektor punkt();

  std::string name(){return "Zylindermantel";}

  double M();

  double J_an();

private:
  double r_, l_, m_;
};

#endif