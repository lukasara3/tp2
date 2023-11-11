#ifndef _GRAFO_H
#define _GRAFO_H


struct No {
    int rotulo;
    int cor;
    No* proximo;
    int* vizinhos;
    int qtdVizinhos;
};

struct ListaAdjacencia{
    int proximoNumero;
    No* primeiroVertice;

};

class Grafo {

    int numeroDeVertices;

public:
Grafo(); //construtor
~Grafo();
void InsereVertice();
// void InsereAresta(int v, int w);
// int QuantidadeVertices();
// int QuantidadeArestas();
// ListaAdjacencia* getListaAdjacencia();
No* getNos();
void AtribuirCores(No* vertices, int numeroDeVertices, int* cores);
// bool ValidarColoracao (No* v, int n);
bool ColoracaoGulosa(No* v, int n);

private:
ListaAdjacencia* nos;
};


#endif