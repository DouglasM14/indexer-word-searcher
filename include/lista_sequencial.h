#ifndef LISTA_SEQUENCIAL_H
#define LISTA_SEQUENCIAL_H

#define FALSE 0
#define TRUE 1

typedef int Boolean;
typedef char* Elemento;

typedef struct {
	Elemento * a;
	int livre;
	int capacidade;

} ListaSequencial;

ListaSequencial * cria_lista(int n);
void destroi_sequencial(ListaSequencial * lista);
void imprime(ListaSequencial * lista);
void imprime_indice(ListaSequencial * lista, int index);
int tamanho(ListaSequencial * lista);
int busca_sequencial(ListaSequencial * lista, Elemento e);
Boolean push(ListaSequencial * lista, Elemento e);

#endif