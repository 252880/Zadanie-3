#include "Macierz.hh"
#include <cmath>

   

/* konstruktory */


template<class T,int ROZMIAR>
Macierz<T,ROZMIAR>::Macierz(){                            // Ustawienie wszystkich skladowych macierzy na 0

  for (int x=0;x < ROZMIAR; ++x)
    for (int z=0;z < ROZMIAR; ++z)
      tab[z][x] = 0;
}


template<class T,int ROZMIAR>
Macierz<T,ROZMIAR>::Macierz(const Wektor<T,ROZMIAR> *W2){                           // ustawienie poszczegolnych wierszy macierzy obiektami klasy Wektor


  for (int x=0;x<ROZMIAR; x++)
    tab[x] = W2[x];
}



/* Metody operatorow arytmetycznych */


template<class T,int ROZMIAR>
Macierz<T,ROZMIAR> Macierz<T,ROZMIAR>:: transpozycja() const{                    // transpozycja macierzy, zwraca macierz

  Macierz<T,ROZMIAR> W;
 

  for(int x=0;x<ROZMIAR;x++)
    for(int y=0;y<ROZMIAR;y++)
      W[y][x]=(*this)[x][y];

  return W;

}


template<class T,int ROZMIAR>
Wektor<T,ROZMIAR> Macierz<T,ROZMIAR> :: operator * ( const Wektor<T,ROZMIAR> &W3) const {                  // metoda mnozenia macierzy przez wektor, zwraca wektor
  Wektor<T,ROZMIAR> M;

  for(int x=0;x<ROZMIAR;x++)

    M[x]=(*this)[x]*W3;

  return M;
}


template<class T,int ROZMIAR>
Macierz<T,ROZMIAR> Macierz<T,ROZMIAR>:: operator * (const Macierz<T,ROZMIAR> & W3) const{                    // metoda mnozenia macierzy przez macierz, zwraca macierz
  Macierz <T,ROZMIAR> W,X;

  X=W3.transpozycja();

  for(int x=0;x<ROZMIAR;x++)
    for(int y=0;y<ROZMIAR;y++)
      W[x][y]=(*this)[x]*X[y];

  return W;
}


template<class T,int ROZMIAR>
Macierz<T,ROZMIAR> Macierz<T,ROZMIAR>:: operator + (const Macierz<T,ROZMIAR> &W3)const{                      // metoda dodawania dwoch macierzy, zwraca macierz

  Macierz<T,ROZMIAR> D;

  for(int x=0;x<ROZMIAR;x++)
    D[x]=W3[x]+(*this)[x];

  return D;
}


template<class T,int ROZMIAR>
Macierz<T,ROZMIAR> Macierz<T,ROZMIAR>::operator - (const Macierz<T,ROZMIAR> &W3)const{                        // metoda odejmowania dwoch macierzy, zwraca macierz

  Macierz<T,ROZMIAR> O;

  for(int x=0;x<ROZMIAR;x++)
    O[x]=(*this)[x]-W3[x];

  return O;
}


template<class T,int ROZMIAR>
Macierz<T,ROZMIAR> Macierz<T,ROZMIAR>:: operator * (double l)const{                              // metoda mnzoenia macierzy z liczba, zwraca macierz

  Macierz <T,ROZMIAR> M;

  for(int x=0;x<ROZMIAR;x++)
    M[x]=(*this)[x]*l;

  return M;
}


template<class T,int ROZMIAR>
Macierz<T,ROZMIAR> Macierz<T,ROZMIAR>::Zmienkolumny(int x, int y)const{                   // metoda zamiany kolumn, zwraca macierz

  Macierz<T,ROZMIAR> K,Y;

  K=(*this).transpozycja();
  Y=(*this).transpozycja();
  K[x]=Y[y];
  K[y]=Y[x];

  Y=K.transpozycja();

  return Y;
}


template<class T,int ROZMIAR>
Macierz<T,ROZMIAR> Macierz<T,ROZMIAR> :: Zmienwiersze(int x, int y)const {                         // metoda zamiany wierszy, zwraca macierz

  Macierz<T,ROZMIAR> K=*this,W=*this;

  K[y]=W[x];
  K[x]=W[y];

  return K;
}


template<class T,int ROZMIAR>
T Macierz<T,ROZMIAR>:: wyznacznikGauss() const{                            // metoda liczenia wyznacznika metoda Gaussa, zwraca liczbe typu double

  Macierz<T,ROZMIAR> P= *this;
  T i=T(0);
  T W=T(0);

  for(int x=0;x<ROZMIAR-1;x++){
    for(int y=x+1;y<ROZMIAR;y++){

      if(P[x].abs(x)> eps){

	i=P[y][x]/P[x][x];

	P[y]=P[y]-(P[x]*i);

      }

      else{

	for(int z=x+1;z<ROZMIAR;z++){
	  if(P[x].abs(z)> eps){
	    P = P.Zmienkolumny(x,z);
	    z=ROZMIAR;
	  }
	  else{
	    std::cerr<<"Blad brak parametru!!"<<x+1;
	    exit(1);	    
	  }

	}
      }

    }
  }

  for(int e=0;e<ROZMIAR;e++){
    if(e==0)
      W=P[e][e];
    else
    W=W*P[e][e];

  }
  return W;
}



/* Metody Getter i Setter */


template<class T,int ROZMIAR>
const Wektor<T,ROZMIAR>  & Macierz<T,ROZMIAR>::operator[] (int index) const{

  if (index < 0 || index >= ROZMIAR){

    std::cerr << "poza zakresem" << std::endl;
    exit(1);
  }

  return this->tab[index];
}


template<class T,int ROZMIAR>
Wektor<T,ROZMIAR> & Macierz<T,ROZMIAR>::operator[] (int index){

  if (index < 0 || index >= ROZMIAR){

    std::cerr << "poza zakresem" << std::endl;
    exit(1);
  }

  return this->tab[index];
}



/* Przeciazenia operatorow in i out */


template<class T,int ROZMIAR>
std::istream& operator >> (std::istream &strm, Macierz<T,ROZMIAR> &M){                // przeciazenie in pobiera od uzytkownika macierz

  for (int i = 0; i < ROZMIAR; i++)
    {
      strm>>M[i];
    }
  return strm;
}


template<class T,int ROZMIAR>
std::ostream& operator << (std::ostream &strm, const Macierz<T,ROZMIAR> &M){                       // przeciazenie out wypisuje na ekran macierz


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
