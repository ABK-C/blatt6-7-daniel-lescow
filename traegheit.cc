#include "Vektor.hh"
#include "Zylindermantel.hh"
#include "Vollzylinder.hh"
#include "Koerper.hh"
#include <iostream>
#include <memory>
#include <fstream>
#include <cmath>

std::ofstream fout("tabelle.txt");

const int N = 10000;     // Anzahl Integrationspunkte

void traegheit(Koerper* k, Vektor a, Vektor u) {

  double m = (k->M())/N;
  double J_be = 0;
  for (int i = 0; i < N; ++i) {
    Vektor x = k->punkt();
    // Abstand Punkt x und Gerade a + t*u
    Vektor n = (x-a+a).kreuz(u); // Vektor n = ...;//Normalenvektor x-a kreuz u  //+a?
    double r = n.betrag() / u.betrag(); 
    J_be += m * r * r; // addiere Beitrag des Massenpunktes zum Traegheitsmoment
  }
  fout<<" ||        "<<k->J_an()<<"        |        "<<J_be ;
}



void schreiben(double R, double L, double M, Vektor a, Vektor u) {

  fout<< R <<"m | "<< L <<"m | "<< M <<"kg | "<< a <<" | "<< u ;
  std :: unique_ptr < Koerper > k( new Zylindermantel (R , L , M));
  traegheit (k.get (),a,u);
  fout<<"      " ;
  std :: unique_ptr < Koerper > j( new Vollzylinder (R , L , M));
  traegheit (j.get (),a,u);
  fout<<std::endl;
  
}

int main() {
  
  fout<<" R | L  |  M  |    a    |    u    || J(ZM)analytisch | J(ZM)berechnet || J(VZ)analytisch | J(VZ)berechnet" << std::endl;

  Vektor a = Vektor(0,0,0);
  Vektor u = Vektor(0,0,1);

  schreiben(1,1,1,a,u);
  schreiben(1,1,2,a,u);
  schreiben(2,1,1,a,u);

  a = Vektor(0,1,0);

  schreiben(1,1,1,a,u);
  schreiben(1,1,2,a,u);

  a = Vektor(0,2,0);

  schreiben(2,1,1,a,u);



  fout.close();

}
