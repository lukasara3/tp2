#include "ordenacao.hpp"
// #include "grafo.hpp"
#include <iostream>
using namespace std;

void Bolha(No *v, int n) {
  int i, j;
  bool trocou;

  for (i = 0; i < n - 1; i++) {
    trocou = false;
    for (j = 0; j < n - i - 1; j++) {
      if (v[j].cor > v[j + 1].cor) {
        Troca(v[j], v[j + 1]);
        trocou = true;
      }
    }
    if (!trocou)
      break; // Se não houve troca, o vetor já está ordenado
  }
}

void Selecao(
    No *v, int n) { // TESTAR PARA VER SE TA CERTO, MAS A BASE E LOGICA EH ESSA
  int i, j, Min;

  for (i = 0; i < n - 1; i++) {
    Min = i;
    for (j = i + 1; j < n; j++) {
      if (v[j].cor < v[Min].cor) {
        Min = j;
      }
    }
    Troca(v[i], v[Min]);
  }
}

void Insercao(No *v, int n) {
  int i, j;
  No aux;
  for (i = 1; i < n; i++) {
    aux = v[i];
    j = i - 1;
    while ((j >= 0) && (aux.cor < v[j].cor)) {
      v[j + 1] = v[j];
      j--;
    }
    v[j + 1] = aux;
  }
}

void MergeSort(No *v, int inicio, int fim) {
  if (inicio < fim) {
    int meio = (inicio + fim) / 2;

    MergeSort(v, inicio, meio);
    MergeSort(v, meio + 1, fim);

    No *temp = new No[fim - inicio + 1];
    int i = inicio, j = meio + 1, k = 0;

    while (i <= meio && j <= fim) {
      if (v[i].cor < v[j].cor ||
          (v[i].cor == v[j].cor && v[i].rotulo < v[j].rotulo)) {
        temp[k++] = v[i++];
      } else {
        temp[k++] = v[j++];
      }
    }

    while (i <= meio) {
      temp[k++] = v[i++];
    }

    while (j <= fim) {
      temp[k++] = v[j++];
    }

    for (i = 0; i < k; ++i) {
      v[inicio + i] = temp[i];
    }

    delete[] temp;
  }
}

void Particao(int Esq, int Dir, int *i, int *j, No *v) {
  No x, w;
  *i = Esq;
  *j = Dir;
  x = v[(*i + *j) / 2]; /* obtem o pivo x */
  do {
    while (x.cor > v[*i].cor || (x.cor == v[*i].cor && x.rotulo > v[*i].rotulo))
      (*i)++;
    while (x.cor < v[*j].cor || (x.cor == v[*j].cor && x.rotulo < v[*j].rotulo))
      (*j)--;
    if (*i <= *j) {
      w = v[*i];
      v[*i] = v[*j];
      v[*j] = w;
      (*i)++;
      (*j)--;
    }
  } while (*i <= *j);
}

void Ordena(int Esq, int Dir, No *v) {
  int i, j;
  Particao(Esq, Dir, &i, &j, v);
  if (Esq < j)
    Ordena(Esq, j, v);
  if (i < Dir)
    Ordena(i, Dir, v);
}

void QuickSort(No *v, int n) { Ordena(0, n - 1, v); }

// HEAP

void Constroi(No *v, int n) {
  int Esq;

  Esq = n / 2;
  while (Esq >= 0) {
    Refaz(Esq, n - 1, v);
    Esq--;
  }
}

void Refaz(int Esq, int Dir, No *v) {
  int i, j;
  No x;
  i = Esq;
  j = i * 2 + 1;
  x = v[i];
  while (j <= Dir) {
    if (j < Dir && v[j].cor < v[j + 1].cor)
      j++;

    if (x.cor >= v[j].cor)
      break;

    v[i] = v[j];
    i = j;
    j = i * 2 + 1;
  }
  v[i] = x;
}

No RetiraMax(No *v, int *n) {
  No Maximo;
  if (*n < 1) {
    // Tratar erro ou retornar um valor especial
    // Aqui estou apenas printando uma mensagem
    printf("Erro: heap vazio\n");
    // Retornando um nó "vazio" para indicar erro
    return No{-1, -1, nullptr, 0};
  }

  Maximo = v[0];
  v[0] = v[*n - 1];
  (*n)--;
  Refaz(0, *n - 1, v);

  return Maximo;
}

void Heapsort(No *v, int n) {
  int Esq, Dir;
  No x;
  Constroi(v, n); /* constroi o heap */
  Esq = 0;
  Dir = n - 1;
  while (Dir > 0) { /* ordena o vetor */
    x = v[0];
    v[0] = v[Dir];
    v[Dir] = x;
    Dir--;
    Refaz(Esq, Dir, v);
  }
}

void MeuMetodo(No *v, int n) {
  // Encontrar o número máximo de cores
  int maxCor = 0;
  for (int i = 0; i < n; i++) {
    if (v[i].cor > maxCor) {
      maxCor = v[i].cor;
    }
  }

  // Criar arrays para cada cor
  No **verticesPorCor = new No *[maxCor + 1];
  int *qtdVerticesPorCor = new int[maxCor + 1]();

  // Inicializar arrays
  for (int i = 0; i <= maxCor; i++) {
    verticesPorCor[i] = new No[n];
  }

  // Classificar os vértices por cor
  for (int i = 0; i < n; i++) {
    int cor = v[i].cor;
    verticesPorCor[cor][qtdVerticesPorCor[cor]++] = v[i];
  }

  // Juntar os vértices ordenados
  int index = 0;
  for (int cor = 0; cor <= maxCor; cor++) {
    for (int i = 0; i < qtdVerticesPorCor[cor]; i++) {
      v[index++] = verticesPorCor[cor][i];
    }
  }

  // Liberar memória alocada
  for (int i = 0; i <= maxCor; i++) {
    delete[] verticesPorCor[i];
  }
  delete[] verticesPorCor;
  delete[] qtdVerticesPorCor;
}
