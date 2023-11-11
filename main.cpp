#include "grafo.hpp"
#include "ordenacao.hpp"
#include <iostream>
using namespace std;

void ImprimirRotulos(No *vertices, int tamanho) {
  for (int i = 0; i < tamanho; i++) {
    cout << vertices[i].rotulo << " ";
  }
  cout << endl;
}

int main() {

  Grafo meuGrafo;
  int n; // vertices
  // char c; //ordenação

  cin >> n; // primeira linha

  for (int i = 0; i < n; i++) {
    int m; // quantidade de vizinhos
    std::cin >> m;
    meuGrafo.InsereVertice();
    meuGrafo.getNos()[i].rotulo = i;

    // Preenche o array de vizinhos para o vértice atual
    meuGrafo.getNos()[i].vizinhos = new int[m];
    meuGrafo.getNos()[i].qtdVizinhos = m;

    for (int j = 0; j < m; j++) {
      int vizinho;
      std::cin >> vizinho;
      meuGrafo.getNos()[i].vizinhos[j] = vizinho;
    }
  }

  int cores[n];
  for (int i = 0; i < n; i++) {
    int cor;
    cin >> cor;
    cores[i] = cor;
  }

  meuGrafo.AtribuirCores(meuGrafo.getNos(), n, cores);

  No *vertice = meuGrafo.getNos();

  // Bolha(vertice, n);

  // Selecao(vertice, n); OK

  // Insercao(vertice, n); OK

  // MergeSort(vertice, 0, n - 1);

  // QuickSort(vertice, n);

  // HeapSort(vertice, n);

  MeuMetodo(vertice, n);

  ImprimirRotulos(vertice, n);

  return 0;
}