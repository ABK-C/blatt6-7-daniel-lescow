#ifndef ZYLINDERMANTEL_HH
#define ZYLINDERMANTEL_HH

#include "Vektor.hh"

class Zylindermantel {
public:
  Zylindermantel(double nr, double nl);

  Vektor punkt();

private:
  double r_, l_;
};

#endif
