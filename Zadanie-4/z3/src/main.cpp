#include <iostream>
#include "Wektor.hh"
 
using namespace std;

/*
 * Tu definiujemy pozostale funkcje.
 * Lepiej jednak stworzyc dodatkowy modul
 * i tam je umiescic. Ten przyklad pokazuje
 * jedynie absolutne minimum.
 */

int main()
{

cout << endl << " Start programu " << endl << endl;
 

  Wektor<double,5> W;
  Wektor<LZesp,5> X;
  std::cin>>X;
  LZesp l;
  cin>>l;
  cout<<" " <<X*l;   
  
  cout << endl << "Koniec programu " << endl << endl ;
      }
