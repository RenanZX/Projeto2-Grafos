#ifndef GRAFOS_H
#define GRAFOS_H
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Vertice{
private:
	~Vertice();
	int valor;
	int peso;
	vector<Vertice> listaAdjArest;
};

class Grafo{
private:
	vector<Vertice> lista_v;
public:
	Grafo();
	~Grafo();
	void InsereVertice(int valor);
	void InsereAresta(int valor,int peso);
	void ImprimirGrafo();
	void ImprimirTopologicamente();
	void ImprimirCaminhoCritico();
};

#endif