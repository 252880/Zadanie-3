#ifndef WEKTOR_HH
#define WEKTOR_HH

#include <iostream>
#include"LZesp.hh"

template <class T, int ROZMIAR>
class Wektor {

  T tab[ROZMIAR];

public:

  Wektor ();


  Wektor(T *Wtab);

  Wektor<T,ROZMIAR> operator + (const  Wektor<T,ROZMIAR> & W1) const;
  Wektor<T,ROZMIAR>  operator - (const Wektor<T,ROZMIAR> & W1)const;
  T operator * (const Wektor<T,ROZMIAR> & W1)const;
  Wektor<T,ROZMIAR>  operator *  (double li)const;
  Wektor<T,ROZMIAR> operator * (LZesp li)const;
  
  double dlugosc() const; 
  double abs(int i)const;

  const T & operator [] (int index) const;
  T & operator [] (int index);

  
  

  
};


  template <class T, int ROZMIAR>
  std::istream& operator >> (std::istream &strm, Wektor<T,ROZMIAR> &W1);


  template <class T, int ROZMIAR>
  std::ostream& operator << (std::ostream &strm, const Wektor<T,ROZMIAR> &W1); 

template<>
double Wektor<LZesp,5>::dlugosc() const;

template<>
Wektor<LZesp,5> Wektor<LZesp,5> :: operator * (LZesp li) const;

template<>
double Wektor<LZesp,5>::abs(int i)const; 

#endif
