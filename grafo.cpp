#include "grafo.hpp"
#include <iostream>
using namespace std;

Grafo::Grafo() {
  numeroDeVertices = 0;
  nos = new ListaAdjacencia(); // Aloca a estrutura de lista de adjacência
  nos->primeiroVertice = nullptr;
}

No *Grafo::getNos() {
  if (nos && nos->primeiroVertice) {
    return nos->primeiroVertice;
  } else {
    return nullptr;
  }
} // CERTO PODE IR PARA O VS

void Grafo::InsereVertice() {
  No *novoVertice = new No;
  novoVertice->rotulo = this->nos->proximoNumero;
  novoVertice->proximo = nullptr;
  novoVertice->vizinhos = nullptr;
  novoVertice->qtdVizinhos = 0; //  IGUAL O DO ALLAN

  if (this->nos->primeiroVertice == nullptr) {
    // this->nos->proximoNumero = 0;
    this->nos->primeiroVertice = novoVertice;
  } else {
    No *tmp = this->nos->primeiroVertice;

    while (tmp->proximo != nullptr) {
      tmp = tmp->proximo;
    }

    tmp->proximo = novoVertice;
  }

  this->nos->proximoNumero += 1;
}

void Grafo::AtribuirCores(No *vertices, int numeroDeVertices, int *cores) {
  for (int i = 0; i < numeroDeVertices; i++) {
    vertices[i].cor = cores[i];
  }
} // CERTO PODE IR PRO VS - MUDAR O NOME DO NO PARA v E numerodevertices para n

bool Grafo::ColoracaoGulosa(No *v, int n) {
  for (int i = 0; i < n; i++) {
    int corVertice = v[i].cor;

    // Variável para rastrear se encontrou pelo menos um vizinho para cada cor
    // menor que a cor do vértice
    bool encontrouVizinhoParaCadaCorMenor = true;

    for (int j = 1; j < corVertice; j++) {
      bool encontrouVizinho = false;

      for (int k = 0; k < v[i].qtdVizinhos; k++) {
        int indiceVizinho = v[i].vizinhos[k];

        // Verifica se o índice do vizinho está dentro dos limites válidos
        if (indiceVizinho >= 0 && indiceVizinho < n) {
          int corVizinho = v[indiceVizinho].cor;

          // Verifica se encontrou pelo menos um vizinho com a cor menor
          if (corVizinho != corVertice && corVizinho == j) {
            encontrouVizinho = true;
            break;
          } else {
            return false;
          } // TENTEI VALIDAR A COLORACAO AQUI E NAO DEU CERTO
        }
      }

      // Se não encontrou um vizinho para a cor atual, então o vértice não é
      // guloso
      if (!encontrouVizinho) {
        encontrouVizinhoParaCadaCorMenor = false;
        break;
      }
    }

    // Se não encontrou pelo menos um vizinho para cada cor menor, o vértice não
    // é guloso
    if (!encontrouVizinhoParaCadaCorMenor) {
      return false;
    }
  }

  // Todos os vértices atendem à condição, a coloração é gulosa
  return true;
}

Grafo::~Grafo() {
  No *atual = nos->primeiroVertice;
  while (atual != nullptr) {
    No *proximo = atual->proximo;

    // Desaloca a lista de vizinhos
    delete[] atual->vizinhos;

    // Desaloca o vértice
    delete atual;

    atual = proximo;
  }

  // Desaloca a estrutura da lista de adjacência
  delete nos;
}
