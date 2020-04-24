#include "Wektor.hh"
#include<iostream>
#include<cmath>
#include"LZesp.hh"


/* Konstruktory */

template<class T, int ROZMIAR>
Wektor<T,ROZMIAR>::Wektor()                           // ustawienie wszystkich skladowych wektora na zera
{

  for(int x=0;x<ROZMIAR;x++)           
        this[x]=0;
}
 

template<class T, int ROZMIAR>
Wektor<T,ROZMIAR>::Wektor(T *tab)           // ustawienie odpowiednich skladowych wektora elementami tablicy
{
  
  for(int x=0;x<ROZMIAR;x++)           
    (*this)[x]=tab[x];
}
/*

template<class T, int ROZMIAR>
Wektor<T,ROZMIAR>::Wektor(T x,T y,T z)          // konstruktor przyjmujacy 3 argumenty typu double
{
  (*this)[0] = x;
  (*this)[1] = y;
  (*this)[2] = z;
}


*/
/* Metody operatorow arytmetycznych */


 template<class T, int ROZMIAR>
 Wektor<T,ROZMIAR>  Wektor<T,ROZMIAR> :: operator  + (const Wektor<T,ROZMIAR> & W1) const {               // metoda dodajaca dwa wektory, zwracajaca  wektor               
   Wektor<T,ROZMIAR> W=0;
  for(int x=0;x<ROZMIAR;x++){
    
    W[x]= (*this)[x]+W1[x];
}
  
  return W;
}


 template<class T, int ROZMIAR>
 Wektor<T,ROZMIAR>  Wektor<T,ROZMIAR> :: operator - ( const Wektor<T,ROZMIAR> & W1)const{               // metoda odejmujaca dwa wektory, zwraca wektor
   Wektor<T,ROZMIAR> W=0;  
  for(int x=0;x<ROZMIAR;x++){
    
    W[x]= (*this)[x]-W1[x];
}

  return W;
}


template<class T, int ROZMIAR>
T Wektor<T,ROZMIAR> :: operator * (const Wektor<T,ROZMIAR> & W1) const{                     // metoda mnozaca dwa wektory, zwraca wektor
     T  i;

   for(int x=0;x<ROZMIAR;x++){
    
    i= i + (*this)[x]*W1[x];
}

  return i;
}


template<class T, int ROZMIAR>
 Wektor<T,ROZMIAR>  Wektor<T,ROZMIAR> :: operator * ( T li)const{                      // metoda mozaca wektor z liczba typu double, zwraca wektor
  Wektor<T,ROZMIAR> W=0;

 for(int x=0;x<ROZMIAR;x++){
    
    W[x]= (*this)[x]*li;
}

  return W;
}



/* Metody Getter i Setter */

template<class T, int ROZMIAR>
const T & Wektor<T,ROZMIAR> :: operator[] (int index)const { 
  if (index < 0 || index >= ROZMIAR){ 
    std::cerr << "poza zakresem" << std::endl;
    exit(1);
}
  else{
    return this->tab[index];
  }
}

template<class T, int ROZMIAR> 
T & Wektor<T,ROZMIAR> :: operator[] (int index) {


  if (index < 0 || index >= ROZMIAR)
    {
      std::cerr << "poza zakresem" << std::endl;
      exit(1);
    }
  else{
  return this->tab[index];
  }
  }


/*  Przeciazenia in i out */
template<class T, int ROZMIAR>
std::ostream & operator << (std::ostream & strm, const Wektor<T,ROZMIAR> & W1){    // Przeciazenie out wypisuje na ekran skladowe wektora


  for(int i=0;i<ROZMIAR;i++){
    
    strm<<W1[i]<<" ";
}
  return strm;
}

template<class T, int ROZMIAR>
std::istream & operator >> (std::istream & strm, Wektor <T,ROZMIAR> & W1){           // Przeciazenie in pobiera od uzytkownika skladowe wektora

  
  for(int i=0;i<ROZMIAR;i++){
    strm>>W1[i];
  }
  return strm;
}






template<>
double Wektor<LZesp,5>::dlugosc() const {
  double s=0;

  for(int i=0;i<5;i++)
    s= s + (*this)[i].mnoz();    

  
  return sqrt(s);
}
 


template<class T , int ROZMIAR>
double Wektor<T,ROZMIAR>::dlugosc() const{

  double i=0;

  for(int x=0;x<ROZMIAR;x++){
    i+=(*this)[x]*(*this)[x];
  }
  i=sqrt(i);

  return i;
}
