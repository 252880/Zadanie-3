#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH
#include <iostream>
#include<cmath>




struct  LZesp {
  double   re;
  double im;



  LZesp();
  LZesp(double x, double yi) : re(x) , im(yi) {} ;
  explicit LZesp (double l) : re(l) , im(0) {};

  LZesp operator = (double l);
      

  LZesp sprzezenie() const;  
  LZesp operator +  (const LZesp & Z) const;
  LZesp operator -  (const LZesp & Z) const;
  LZesp operator *  (const LZesp & Z) const;
  LZesp operator / (const LZesp & Z) const;
  LZesp operator += (const LZesp & Z) const;
  LZesp operator * (double l) const;
  
  double  mnoz () const;

  bool operator ==(const LZesp & Z)const;

  

};
std::istream & operator >> (std::istream &strm, LZesp & Z);
std::ostream & operator << (std::ostream &strm, const LZesp & Z);
  


#endif
