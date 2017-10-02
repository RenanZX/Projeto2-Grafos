#include "dados.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

Grafo* InsereRegistros(Grafo *grafo){

  ifstream txtFile;
  txtFile.open("dados-trab2.txt");

  stringstream ss;

  string line;
  string x;

  int restline1, restline2, restline3;

  int qtd_elementos;

  int font, peso;

  // Loop para imprimir linha por linha
  while(!txtFile.eof()){
    getline(txtFile, line);
    
    ss << line; // variavel utilizada para fazer a contagem de elementos sep. por white spaces

    istringstream iss(line); // variavel para poder salvar os 2 primeiros elementos
    iss >> font >> peso; // os 2 primeiros valores da linha vao pra variavel fonte e peso

    // Loop para contar a quantidade de elementos separados por espaço na linha
    qtd_elementos = 0;
    while(ss >> x){
      qtd_elementos++;
    }
    x.clear();
    ss.clear();

    // Inserindo os dados no grafo.
    grafo->InsereVertice(font);

    if((qtd_elementos - 2)  == 0){
      //cout << "#0 there is no edge!" << endl;
    } else if ( (qtd_elementos-2) == 1 ){
      iss >> restline1;
      //cout << "#1 v1 = "<< restline1<< endl;
      grafo->InsereAresta(font, restline1, peso);
    } else if((qtd_elementos-2) == 2 ){
      iss >> restline1 >> restline2;
      //cout << "#2 v1 = "<< restline1 <<" v = 2"<<restline2 << endl;
      grafo->InsereAresta(font, restline1, peso);
      grafo->InsereAresta(font, restline2, peso);
    }else if ((qtd_elementos-2) == 3){
      iss >> restline1 >> restline2 >> restline3;
      //cout << "#3 v1 = "<< restline1 << " v2 = " << restline2 << " v3 = " << restline3 <<endl;
      grafo->InsereAresta(font, restline1, peso);
      grafo->InsereAresta(font, restline2, peso);
      grafo->InsereAresta(font, restline3, peso);
    }

  }

}
