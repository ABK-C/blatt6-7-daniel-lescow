#include "Vektor.hh"
#include "Zylindermantel.hh"
#include "Vollzylinder.hh"
#include <iostream>
#include <memory>
#include <fstream>
#include <cmath>

std::ofstream fout("tabelle.txt");



int berechne(int N, double M, double ZM_R, Vektor a , Vektor u, double ZM_L){

  /*
  Vektor a; // Punkt auf der Rotationsachse
  std::cout << "Aufpunkt:";
  std::cin >> a;
  Vektor u; // Richtung der Rotationsachse
  std::cout << "Richtung:";
  std::cin >> u;
  */

  std::unique_ptr<Zylindermantel> zm(new Zylindermantel(ZM_R, ZM_L));

  double ZM_J_an = 0;
  double ZM_J_be = 0;     // Massentraegheitsmoment
  double m = M / N; // Masse eines Massenpunktes
  for (int i = 0; i < N; ++i) {
    Vektor x = zm->punkt();
    // Abstand Punkt x und Gerade a + t*u
    Vektor n = (x-a+a).kreuz(u); // Vektor n = ...;//Normalenvektor x-a kreuz u
    double r = n.betrag() / u.betrag(); //|n|/|u|
    //std::cout << x << " :" << r << std::endl;
    ZM_J_be += m * r * r; // addiere Beitrag des Massenpunktes zum Traegheitsmoment
  }
  ZM_J_an = M * pow(ZM_R,2);

  
  std::unique_ptr<Vollzylinder> vz(new Vollzylinder(ZM_R, ZM_L));
  
  double VZ_J_an = 0;
  double VZ_J_be = 0;     // Massentraegheitsmoment
   m = M / N; // Masse eines Massenpunktes
  for (int i = 0; i < N; ++i) {
    Vektor x = vz->punkt();
    // Abstand Punkt x und Gerade a + t*u
    Vektor n = (x-a+a).kreuz(u); // Vektor n = ...;//Normalenvektor x-a kreuz u
    double r = n.betrag() / u.betrag(); //|n|/|u|
    //std::cout << x << " :" << r << std::endl;
    VZ_J_be += m * r * r; // addiere Beitrag des Massenpunktes zum Traegheitsmoment
  }
  VZ_J_an = 0.5*ZM_J_an;

  fout << ZM_R <<"m | "<< ZM_L <<"m | "<< M <<"kg | "<< a <<" | "<< u <<" ||        "<< ZM_J_an <<"        |        "<< ZM_J_be<<"       ||       "<< VZ_J_an <<"       |   " << VZ_J_be << std::endl;
  /*
  std::cout << "Massentraegheitsmoment fuer einen Zylindermantel"
            << " mit a = " << a << " und u = " << u << ": " << J << std::endl;
            
  return 0;
  */
}

int main() {
  const int N = 10000;     // Anzahl Integrationspunkte
  /*
  const double M = 1;      // Masse des Zylindermantels
  const double ZM_R = 1.0; // Radius der Zylindermantels
  const double ZM_L = 1.0; // Laenge des Zylindermantels
  */
  
  fout<<" R | L  |  M  |    a    |    u    || J(ZM)analytisch | J(ZM)berechnet || J(VZ)analytisch | J(VZ)berechnet" << std::endl;
  Vektor a = Vektor(0,0,0);
  Vektor u = Vektor(0,0,1);
  berechne(N, 1, 1, a, u, 1);
  berechne(N, 2, 1, a, u, 1);
  berechne(N, 1, 2, a, u, 1);

  fout<<""<<std::endl;
  a = Vektor(0,1,0);
  berechne(N, 1, 1, a, u, 1);
  berechne(N, 2, 1, a, u, 1);
  a = Vektor(0,2,0);
  berechne(N, 1, 2, a, u, 1);

  fout.close();

}

