#include "UkladRownanLiniowych.hh"
#include <cmath>



/* Metody Getter i Setter */
template<class T, int ROZMIAR>
const Wektor<T,ROZMIAR> & UkladRownanL<T,ROZMIAR>:: getwektor() const{

  return B ;
}


template<class T, int ROZMIAR>
const Macierz<T,ROZMIAR> & UkladRownanL<T,ROZMIAR> :: getmacierz() const{

  return A;
}


template<class T, int ROZMIAR>
void UkladRownanL<T,ROZMIAR> :: setwektor(const Wektor<T,ROZMIAR> & im){

  this->B=im;
}


template<class T, int ROZMIAR>
void UkladRownanL<T,ROZMIAR> :: setmacierz( const Macierz<T,ROZMIAR> & im){

  this->A=im;
}

/* Metody */
template<class T, int ROZMIAR>
Wektor<T,ROZMIAR> UkladRownanL<T,ROZMIAR> :: oblicz() const {


  Macierz<T,ROZMIAR> P(this->A);
  T i=T(0);                                                                                                                                                                  Wektor<T,ROZMIAR> rozw;                                        //Oblicza uklad rownan, zwaraca wektor
  Wektor<T,ROZMIAR> W(this->B);




  for(int x=0;x<ROZMIAR-1;x++){                                                                                                                                                   for(int y=x+1;y<ROZMIAR;y++){

      if(P[x].abs(x)> eps){
	i=P[y][x]/P[x][x];

	P[y]=P[y]-(P[x]*i);
	W[y]=W[y]-(W[x]*i);

      }

      else{

	for(int z=x+1;z<ROZMIAR;z++){
	  if(P[z].abs(x)> eps){
	    P = P.Zmienwiersze(x,z);
	    std::swap(W[x],W[z]);            //Jesli zmieniamy wiersze w macierzy to skladowe wektora takze trzeba zamienic miejscami
	    z=ROZMIAR;
	  }
	  else {
	    std::cerr << "Brak zmiennej " << x+1 <<std::endl;            //Blad jesli cala koloumna jest rowna 0
	    exit(1);
	  }
	}
      }
    }
  }
  for (int a = ROZMIAR-1; a > -eps; a--){
    if(P[a].abs(a)<eps){

      std::cerr << "Blad dzielenie przez 0 !" << std::endl;     //Blad jesli dzielimy przez  0
      exit(1);
    }
    rozw[a]=(W[a]+(P[a]*rozw)*(-1))/P[a][a];

  }
  return rozw;
}

template<class T, int ROZMIAR>
Wektor<T,ROZMIAR> UkladRownanL<T,ROZMIAR>:: wekbledu() const{                 //metoda wylicza wktor bledu zwraca wektor


  return this->A*this->oblicz()-this->B;


}

template<class T, int ROZMIAR>
double UkladRownanL<T,ROZMIAR> :: dlugoscwek() const{       //metoda wylicza dlugosc wektora bledu zrwaca wartosc typu double


  return this->wekbledu().dlugosc();
}


/* Przeciazenia operatorow in/out*/

template<class T, int ROZMIAR>
std::istream & operator >> (std::istream & strm, UkladRownanL<T,ROZMIAR> & UK){

  Macierz <T,ROZMIAR>X;
  Wektor <T,ROZMIAR>Y;
  //Przeeciazaenie in pobiera od uzytkownika najpierw macierz potem wektor

  strm>> X;
  strm>> Y;
  UK.setmacierz(X);
  UK.setwektor(Y);

  return strm;
}


template<class T, int ROZMIAR>
std::ostream & operator << ( std::ostream & strm,  const UkladRownanL<T,ROZMIAR> & UK){


  strm<<"Macierz A^T : \n"<< UK.getmacierz().transpozycja()<<"\n ";
  strm<<"Wektor wyrazow wolnych: " << UK.getwektor()<<"\n ";
  strm<<"Rozwiazanie x = : " << UK.oblicz()<<"\n ";                        //Przeciazenie out wypisuje na ekran macierz transponowana, wektor wyrazow wolnych
  strm<<"Wektor bledu: Ax-b = "<<UK.wekbledu()<<"\n ";                                //wektor bledu oraz dlugosc wektora
  strm<<"Dlugosc wektora bledu: ||Ax-b|| = "<<UK.dlugoscwek()<<"\n ";

  return strm;
}
  
