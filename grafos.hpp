#ifndef GRAFOS_H
#define GRAFOS_H
#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>

using namespace std;

class Vertice{ /*classe do vertice*/
friend class Grafo;
private:
  int valor; /*valor do vertice*/
  int peso; /*peso da aresta*/
  std::vector<Vertice> listaAdjArest; /*lista de Adjacencia*/
};

class Caminho{ /*classe contendo um caminho do grafo*/
friend class Grafo;
private:
  int somapesos; /*somatorio dos pesos das arestas do caminho*/
  std::vector<int> path; /*caminho*/
};

class Grafo{
private:
  std::vector<int> Ordenado; /*lista ordenada de vertices*/
  std::vector<int> marcados; /*lista de vertices marcados*/
  std::vector<Vertice> lista_v; /*lista de vertices do grafo*/
  bool EstaMarcado(int v);/*indica se um vertice esta marcado ou nao*/
  void Marcar(int v); /*marca um vertice*/
  void LimparMarcas(); /*limpa o vertor de marcas*/
  Caminho getMaiorCaminho(int v)throw(runtime_error); /*retorna o CPM do grafo apartir de um vertice*/
  bool ExistemArestas(int v); /*verifica se existem arestas no vertice v*/
  void VisitaNo(Vertice n); /*Visita um no n no grafo*/
  void Ordem_Topologica(); /*ordena o grafo em ordem topologica*/
public:
  Grafo(); /*construtor e destrutor do grafo*/
  ~Grafo();
  void InsereVertice(int valor); /*Insere um novo vertice no grafo com um valor recebido como parametro*/
  void InsereAresta(int v1,int v2,int peso); /*cria a aresta (v1,v2) e insere o peso correspondente*/
  void ImprimirGrafo(); /*imprime o grafo*/
  void ImprimirTopologicamente(); /*imprime o grafo topologicamente*/
  void ImprimirCaminhoCritico(); /*imprime o caminho crítico CPM do grafo*/
};

#endif