#include "Vektor.hh"
#include <iostream>

int main() {
  Vektor a(2, -1, 2);
  Vektor v1(1, -2, 3);
  Vektor v2(3, 1, 2);

  // teste Konstruktor
  std::cout << "x von " << a << " = 2?          "
            << (a.x() == 2 ? "ok" : "NEIN!") << '\n';
  std::cout << "y von " << a << " = -1?         "
            << (a.y() == -1 ? "ok" : "NEIN!") << '\n';
  std::cout << "z von " << a << " = 2?          "
            << (a.z() == 2 ? "ok" : "NEIN!") << '\n';

  // teste Betrag
  std::cout << "Betrag von " << a << " = 3?     "
            << (a.betrag() == 3 ? "ok" : "NEIN!") << '\n';

  // test Einlese
  Vektor b;

  std::cout << "Geben Sie 1 -3 3 ein:";
  std::cin >> b;

  std::cout << "eingebener Vektor" << b << " = (1,-3,3)? "
            << (b == Vektor(1, -3, 3) ? "ok" : "NEIN!") << '\n';

  // teste Addition und Subtraktion
  std::cout << a << " + " << v1 << " = (3,-3,5)?          "
            << (a + v1 == Vektor(3, -3, 5) ? "ok" : "NEIN!") << '\n';
  std::cout << a << " - " << v1 << " = (1,1,-1)?          "
            << (a - v1 == Vektor(1, 1, -1) ? "ok" : "NEIN!") << '\n';

  // teste Skalar- und Kreuzprodukt
  std::cout << v1 << " mal " << v2 << " = 7                "
            << (v1.mal(v2) == 7 ? "ok" : "NEIN!") << '\n';
  std::cout << v1 << " kreuz " << v2 << " = (-7,7,7)       "
            << (v1.kreuz(v2) == Vektor(-7, 7, 7) ? "ok" : "NEIN!") << '\n';

  return 0;
}
