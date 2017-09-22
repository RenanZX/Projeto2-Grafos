#CPPFLAGS=-g -pthread -I/sw/include/root 
#LDFLAGS=-g
#LDLIBS=-L/sw/lib/root -lCore -lCint -lRIO -lNet -lHist -lGraf -lGraf3d -lGpad -lTree -lRint \
       -lPostscript -lMatrix -lPhysics -lMathCore -lThread -lz -L/sw/lib -lfreetype -lz \
       -Wl,-framework,CoreServices -Wl,-framework,ApplicationServices -pthread -Wl,-rpath,/sw/lib/root \
       -lm -ldl
all:Executar limpar
Executar: main.o grafo.o dado.o
	g++ -f -Wall -std=c++11 -o Projeto2 main.o grafo.o dado.o

main.o:main.cpp grafos.cpp grafos.h dados.cpp dados.h
	g++ -c main.cpp

grafo.o:grafos.cpp grafos.h
	g++ -c grafos.cpp

dado.o:dados.cpp dados.h
	g++ -c dados.cpp

limpar:
	rm -rf *.o