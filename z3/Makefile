CXXFLAGS= -c -g -std=c++14 -iquote inc -Wall -pedantic

__start__: ./test_wektora
	./test_wektora

obj:
	mkdir -p obj

./test_wektora: obj  obj/main.o obj/UkladRownanLiniowychC.o obj/MacierzC.o obj/WektorC.o obj/LZesp.o 
	g++ -o ./test_wektora obj/main.o  obj/LZesp.o obj/WektorC.o obj/MacierzC.o obj/UkladRownanLiniowychC.o

obj/main.o: src/main.cpp inc/UkladRownanLiniowych.hh inc/Macierz.hh inc/Wektor.hh inc/LZesp.hh 
	g++ -c ${CXXFLAGS} -o obj/main.o src/main.cpp


obj/UkladRownanLiniowychC.o: inc/LZesp.hh inc/Wektor.hh inc/Macierz.hh inc/UkladRownanLiniowych.hh src/UkladRownanLiniowych.cpp src/UkladRownanLiniowychC.cpp
	g++ -c ${CXXFLAGS} -o obj/UkladRownanLiniowychC.o src/UkladRownanLiniowychC.cpp

obj/MacierzC.o: inc/LZesp.hh inc/Wektor.hh inc/Macierz.hh src/Macierz.cpp src/MacierzC.cpp 
	g++ -c ${CXXFLAGS} -o obj/MacierzC.o src/MacierzC.cpp

obj/WektorC.o: inc/LZesp.hh inc/Wektor.hh src/Wektor.cpp src/WektorC.cpp
	   g++ -c ${CXXFLAGS} -o obj/WektorC.o src/WektorC.cpp


obj/LZesp.o: inc/LZesp.hh src/LZesp.cpp
	g++ -c ${CXXFLAGS} -o obj/LZesp.o src/LZesp.cpp




