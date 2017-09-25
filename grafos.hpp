#ifndef GRAFOS_H
#define GRAFOS_H
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Vertice{
private:
	int valor;
	int peso;
	std::vector<Vertice> listaAdjArest;
};

class Grafo{
private:
	std::vector<Vertice> lista_v;
public:
	Grafo();
	~Grafo();
	void InsereVertice(int valor);
	void InsereAresta(int v1,int v2,int peso);
	void ImprimirGrafo();
	void ImprimirTopologicamente();
	void ImprimirCaminhoCritico();
};

#endif
