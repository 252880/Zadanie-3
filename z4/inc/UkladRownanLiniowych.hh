#ifndef UKLADROWNANLINIOWYCH_HH
#define UKLADROWNANLINIOWYCH_HH

#include <iostream>
#include "Wektor.hh"
#include "Macierz.hh"


template<class T, int ROZMIAR>
class UkladRownanL{

  Macierz <T,ROZMIAR> A;
  Wektor<T,ROZMIAR> B;

public:

  Wektor<T,ROZMIAR>  oblicz() const;
  Wektor<T,ROZMIAR>  wekbledu()const;
  double dlugoscwek() const;

  UkladRownanL(){};
  UkladRownanL(Macierz<T,ROZMIAR>  AA, Wektor<T,ROZMIAR>  BB): A(AA), B(BB){};


  const Macierz<T,ROZMIAR>  & getmacierz() const;
  const Wektor<T,ROZMIAR>  & getwektor() const;


  void setmacierz(const Macierz<T,ROZMIAR>  & im);
  void setwektor(const Wektor<T,ROZMIAR>  & im);

};
template<class T,int ROZMIAR>
std::istream& operator >> (std::istream &Strm, UkladRownanL<T,ROZMIAR>  &UklRown);


template<class T,int ROZMIAR>
std::ostream& operator << ( std::ostream &Strm, const UkladRownanL<T,ROZMIAR>  &UklRown);


#endif
