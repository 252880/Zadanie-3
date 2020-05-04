#include <iostream>
#include"LZesp.hh"
#include "Wektor.hh"
#include "Macierz.hh" 
#include "UkladRownanLiniowych.hh"

using namespace std;

/*
 * Tu definiujemy pozostale funkcje.
 * Lepiej jednak stworzyc dodatkowy modul
 * i tam je umiescic. Ten przyklad pokazuje
 * jedynie absolutne minimum.
 */

int main()
{

  char a;
  cin>>a;

  switch(a){

  case 'r':
    {    UkladRownanL<double,5> X;
   cin>>X;
    cout<<X;
    break;
    }
    case 'z':
      { UkladRownanL<LZesp,5> Y;
    cin>>Y;
    cout<<Y;
    break;
      }
  default:
    cerr << "Podano zly parametr" << endl;
    break;
  }
  return 0;

}
