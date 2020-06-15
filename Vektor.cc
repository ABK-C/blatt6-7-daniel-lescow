#include "Vektor.hh"
#include <cmath>

Vektor::Vektor(double nx, double ny, double nz) {
  x_ = nx;
  y_ = ny;
  z_ = nz;
}

double Vektor::betrag() { return sqrt(x_ * x_ + y_ * y_ + z_ * z_); }

std::istream &operator>>(std::istream &is, Vektor &v) {
  is >> v.x_ >> v.y_ >> v.z_;
  return is;
}

std::ostream &operator<<(std::ostream &os, Vektor v) {
  os << "(" << v.x_ << "," << v.y_ << "," << v.z_ << ")";
  return os;
}

Vektor Vektor::operator+(Vektor v) {
  Vektor sum(x_ + v.x_, y_ + v.y_, z_ + v.z_);
  return sum;
}

Vektor Vektor::operator-(Vektor v) {
  Vektor sum(x_ - v.x_, y_ - v.y_, z_ - v.z_);
  return sum;
}

Vektor Vektor::kreuz(Vektor v) {
  Vektor erg(y_ * v.z_ - z_ * v.y_, z_ * v.x_ - x_ * v.z_,
             x_ * v.y_ - y_ * v.x_);
  return erg;
}

double Vektor::mal(Vektor v) { return x_ * v.x_ + y_ * v.y_ + z_ * v.z_; }
