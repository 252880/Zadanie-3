#include "LZesp.hh"
#include<cmath>
#include<iostream>

LZesp::LZesp(){
  re = 0;
  im = 0;
}

LZesp LZesp::operator = (double l){
  this->re=l;
  this->im=0;
  return *this;
}




LZesp LZesp::operator + (const LZesp & Z) const {
  LZesp  W;
  W.re = this->re + Z.re;
  W.im = this->im + Z.im;
  return W;
}

LZesp LZesp::operator += (const LZesp & Z) const {
  LZesp W;
  W.re = this->re + Z.re;
  W.im = this->im + Z.im;
  return W;
}

LZesp LZesp::operator - (const LZesp & Z) const {
  LZesp  W;
  W.re = this->re - Z.re;
  W.im = this->im - Z.im;
  return W;
}

LZesp LZesp::operator * (const LZesp & Z) const {
  LZesp  W;
  W.re = (this->re * Z.re) - (this->im * Z.im);
  W.im = (this->re * Z.im) + (this->im * Z.re);
  return W;
}
LZesp LZesp::operator * (double l) const{
  LZesp W;
  W.re=this->re*l;
  W.im=this->im*l;
  return W;
}


bool LZesp::operator == (const LZesp & W) const {
  if (this->re == W.re){
    if (this->im == W.im)
      return true;
  }
  return false;
}

LZesp LZesp::sprzezenie()const{
  LZesp X;
  X.re=this->re;
  X.im=(-1)*this->im;

  return X;
}

LZesp LZesp::operator / (const LZesp & Z)const  {
  double i=0;
  LZesp X;
  i=(Z.re*Z.re)+(Z.im*Z.im);

  if(i==0){
    std::cerr<<"Dzielenie przez zero!!";
} else
      {
	X.re=(this->re*Z.re+this->im*Z.im)/i;
    X.im=(this->im*Z.re-this->re*Z.im)/i;
}
return X;
}
 



double LZesp :: mnoz() const{                      //Lzesp razy sprzezenie zwraca liczbe typu double
  LZesp x;
  x=*this*(*this).sprzezenie();
  
  return x.re+x.im;
}


std::ostream & operator << (std::ostream &strm, const LZesp & Z){

  strm << '(' << Z.re << std::showpos << Z.im << std::noshowpos << "i" <<")";
  return strm;
}


std::istream & operator >> (std::istream &strm, LZesp &Z) {
  char znak;
  strm >> znak;
  if (znak != '(')
    strm.setstate(std::ios::failbit);

  strm >> Z.re >> Z.im >> znak;
  if (znak != 'i')
    strm.setstate(std::ios::failbit);

  strm >> znak;
  if (znak != ')')
    strm.setstate(std::ios::failbit);
  return strm;
}





