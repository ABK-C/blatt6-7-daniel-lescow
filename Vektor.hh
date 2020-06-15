#ifndef VEKTOR_HH
#define VEKTOR_HH

#include <iostream>

/*
  Klasse fuer einen Punkt oder Vektor in drei Dimensionen
 */
class Vektor {
public:
  Vektor(double nx = 0, double ny = 0, double nz = 0);

  double betrag();

  double x() { return x_; }
  double y() { return y_; }
  double z() { return z_; }

  friend std::istream &operator>>(std::istream &is, Vektor &v);
  friend std::ostream &operator<<(std::ostream &os, Vektor v);

  Vektor operator+(Vektor v);
  Vektor operator-(Vektor v);

  double mal(Vektor v);
  Vektor kreuz(Vektor v);

  bool operator==(Vektor v) {
    return ((x_ == v.x_) && (y_ == v.y_) && (z_ == v.z_));
  }

private:
  double x_, y_, z_;
};

#endif
