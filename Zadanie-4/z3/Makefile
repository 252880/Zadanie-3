CXXFLAGS= -c -g -std=c++11 -iquote inc -Wall -pedantic

__start__: ./test_wektora
	./test_wektora

obj:
	mkdir -p obj

./test_wektora: obj  obj/main.o obj/WektorC.o
	g++ -o ./test_wektora obj/main.o obj/WektorC.o

obj/main.o: src/main.cpp inc/Wektor.hh inc/LZesp.hh
	g++ -c ${CXXFLAGS} -o obj/main.o src/main.cpp


obj/WektorC.o: src/WektorC.cpp  src/Wektor.cpp inc/Wektor.hh
	   g++ -c ${CXXFLAGS} -o obj/WektorC.o src/WektorC.cpp

obj/LZesp.o: inc/LZesp.hh src/LZesp.cpp
	g++ -c ${CXXFLAGS} -o obj/LZesp.o src/LZesp.cpp
