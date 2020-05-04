#include "UkladRownanLiniowych.cpp"



template class UkladRownanL<LZesp,5>;
template std::istream & operator >> (std::istream &strm, UkladRownanL<LZesp,5> &M);
template std::ostream & operator << (std::ostream &strm, const UkladRownanL<LZesp,5> &M);


template class UkladRownanL<double,5>;
template std::istream & operator >> (std::istream &strm, UkladRownanL<double,5> &M);
template std::ostream & operator << (std::ostream &strm, const UkladRownanL<double,5> &M);




