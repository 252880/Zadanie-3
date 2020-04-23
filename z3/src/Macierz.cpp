#include "Macierz.hh"
#include"Wektor.hh"
#include <cmath>



/* konstruktory */



Macierz::Macierz(){                            // Ustawienie wszystkich skladowych macierzy na 0
  
  for (int x=0;x < ROZMIAR; ++x)
    for (int z=0;z < ROZMIAR; ++z)
      (*this)[z][x] = 0; 
  }



Macierz::Macierz(const Wektor *W2){                           // ustawienie poszczegolnych wierszy macierzy obiektami klasy Wektor
  
  
  for (int x=0;x<ROZMIAR; x++)
    (*this)[x] = W2[x];
}



/* Metody operatorow arytmetycznych */



Macierz Macierz:: transpozycja() const{                    // transpozycja macierzy, zwraca macierz

  Macierz T;
 

  for(int x=0;x<ROZMIAR;x++)
    for(int y=0;y<ROZMIAR;y++)
      T[y][x]=(*this)[x][y];

  return T;
  
}



Wektor Macierz :: operator * ( const Wektor &W3) const {                  // metoda mnozenia macierzy przez wektor, zwraca wektor
  Wektor M;

  for(int x=0;x<ROZMIAR;x++)
  
    M[x]=(*this)[x]*W3;

  return M;
}



Macierz Macierz:: operator * (const Macierz & W3) const{                    // metoda mnozenia macierzy przez macierz, zwraca macierz
  Macierz T,X;

  X=W3.transpozycja();

  for(int x=0;x<ROZMIAR;x++)
    for(int y=0;y<ROZMIAR;y++)
      T[x][y]=(*this)[x]*X[y];

  return T;
}


    
Macierz Macierz:: operator + (const Macierz &W3)const{                      // metoda dodawania dwoch macierzy, zwraca macierz

  Macierz D;

  for(int x=0;x<ROZMIAR;x++)
    D[x]=W3[x]+(*this)[x];

  return D;
}
  


Macierz Macierz::operator - (const Macierz &W3)const{                        // metoda odejmowania dwoch macierzy, zwraca macierz

  Macierz O;

  for(int x=0;x<ROZMIAR;x++)
    O[x]=(*this)[x]-W3[x];
  
  return O;
}



Macierz Macierz:: operator * (double l)const{                              // metoda mnzoenia macierzy z liczba, zwraca macierz

  Macierz M;

  for(int x=0;x<ROZMIAR;x++)
    M[x]=(*this)[x]*l;

  return M;
}



const Macierz Macierz::Zmienkolumny(int x, int y){                   // metoda zamiany kolumn, zwraca macierz

  Macierz K;

  K=(*this).transpozycja();
  
  K[x]=(*this)[y];
  K[y]=(*this)[x];

  *this=K.transpozycja();

  return *this;
}



const Macierz Macierz :: Zmienwiersze(int x, int y){                         // metoda zamiany wierszy, zwraca macierz

  Macierz W=*this;

  (*this)[y]=W[x];
  (*this)[x]=W[y];

    return *this;
}



double Macierz:: wyznacznikGauss() const{                            // metoda liczenia wyznacznika metoda Gaussa, zwraca liczbe typu double
  
  Macierz P= *this;
  double i=0;
  double W=1;
  
  for(int x=0;x<ROZMIAR-1;x++){
    for(int y=x+1;y<ROZMIAR;y++){
      
      if(std::abs(P[x][x])> eps){

	i=P[y][x]/P[x][x];

	P[y]=P[y]-(P[x]*i); 
	
      }

      else{
	 
	for(int z=x+1;z<ROZMIAR;z++){
	  if(std::abs(P[x][z])> eps){ 
	     P = P.Zmienkolumny(x,z);
	     z=ROZMIAR;
	  }
	
	}       
      }

    }
  }

  for(int e=0;e<ROZMIAR;e++){
    W= W*P[e][e];
  }
	return W;
}



/* Metody Getter i Setter */



const Wektor  & Macierz::operator[] (int index) const{

  if (index < 0 || index >= ROZMIAR){
    
      std::cerr << "poza zakresem" << std::endl;
      exit(1);
    }

  return this->tab[index];
}



Wektor & Macierz::operator[] (int index){
  
  if (index < 0 || index >= ROZMIAR){
    
      std::cerr << "poza zakresem" << std::endl;
      exit(1);
    }

  return this->tab[index];
}



/* Przeciazenia operatorow in i out */



std::istream& operator >> (std::istream &strm, Macierz &M){                // przeciazenie in pobiera od uzytkownika macierz

  for (int i = 0; i < ROZMIAR; i++)
    {
      strm>>M[i];
    }
  return strm;
}



std::ostream& operator << (std::ostream &strm, const Macierz &M){                       // przeciazenie out wypisuje na ekran macierz

  
  for (int i = 0; i < ROZMIAR; i++)
    {
      strm<<"|";
 
      for (int z = 0; z < ROZMIAR; z++)
	{
	
	  strm << M[i][z]<<" ";
	  
	  if(z==ROZMIAR-1){
	    strm<<"|";
	  }


	}
      strm  << std::endl;
    }
  return strm;
}
