
#include "LZesp.cpp"
#include "Wektor.cpp"

template class Wektor<double,5>;
template std::istream & operator>>(std::istream &strm, Wektor<double,5> &W1);
template std::ostream & operator<< (std::ostream &strm, const Wektor<double,5> &W1);


template class Wektor<LZesp,5>;
template <> std::istream & operator>>(std::istream &strm, Wektor<LZesp,5> &W1);
template <> std::ostream & operator<< (std::ostream &strm, const Wektor<LZesp,5> &W1);

 
