#ifndef _ORDENACAO_H
#define _OREDENACAO_H
#include "grafo.hpp"

#define Troca(A, B)  {No c = A; A = B; B = c; }

void Bolha (No* v, int n);

void Selecao(No* v,int n);

void Insercao(No *v,int n);

void MergeSort(No* v, int inicio, int fim);

// QUICKSORT

void Particao(int Esq, int Dir, int *i, int *j, No* v);
void Ordena(int Esq, int Dir, No *v);
void QuickSort(No *v, int n);

//HEAP

void Constroi(No *v, int n);
void Refaz(int Esq, int Dir, No* v);
No RetiraMax(No *v, int *n);
void Heapsort(No *v, int n);


void MeuMetodo(No *v, int n);







#endif