#ifndef MACIERZ_HH
#define MACIERZ_HH

#include"Wektor.hh"
#include"LZesp.hh"
#include <iostream>


#define eps 1e-12

template<class T, int ROZMIAR>
class Macierz {

  Wektor< T, ROZMIAR> tab[ROZMIAR];

public:

  Macierz();
  Macierz( const Wektor<T,ROZMIAR> *W2);

  const Wektor<T,ROZMIAR>  & operator[] (int index) const;
  Wektor<T,ROZMIAR> & operator[] (int index);


  Macierz  transpozycja() const;

  Wektor<T,ROZMIAR> operator * (const Wektor<T,ROZMIAR> &W3)const;
  Macierz<T,ROZMIAR> operator * (const Macierz<T,ROZMIAR> & W3)const;
  Macierz<T,ROZMIAR> operator + (const Macierz <T,ROZMIAR> &W3)const;
  Macierz<T,ROZMIAR> operator - (const Macierz<T,ROZMIAR>  &W3)const;
  Macierz <T,ROZMIAR>operator * (double l)const;


  Macierz<T,ROZMIAR> Zmienkolumny(int x,int y)const;
  Macierz<T,ROZMIAR> Zmienwiersze(int x, int y)const;

  T wyznacznikGauss() const;



};
 
 
template<class T,int ROZMIAR>
std::istream& operator >> (std::istream &strm, Macierz<T,ROZMIAR> &M);


template<class T,int ROZMIAR>
std::ostream& operator << (std::ostream &strm, const Macierz<T,ROZMIAR> &M);


#endif
