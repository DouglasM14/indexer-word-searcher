#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "lista_sequencial.h"
#include "comandos.h"
#include "utils.h"

#define TAMANHO 10000

ListaSequencial * listaComandos;
char TIPO_INDICE[32];

void gaurdar_palavras(char * palavra) {
  tolower_string(palavra);
  trim(palavra, ".,?:;!");

  if (strcmp(TIPO_INDICE, "arvore") == 0) {

  } else if (strcmp(TIPO_INDICE, "arvore") == 0) {

  }
}

int main(int argc, char ** argv){
	FILE * in;
	char * linha;
	char * copia_ponteiro_linha;
	char * quebra_de_linha;
	char * palavra;	
	int contador_linha;

	if (argc < 2) {
    printf("Invalido! Insira o caminho do arquivo e o tipo de indice!\n");
    return 1;
  }

  if (strcmp(argv[2], "arvore") != 0 && strcmp(argv[2], "lista") != 0) {
    printf("Tipo de indice inválido!\n");
    return 1;
  } else {
    strcpy(TIPO_INDICE, argv[2]);
  }

  in = fopen(argv[1], "r");

  if (in == NULL) {
    printf("Arquivo inválido!");
    return 1;
  }

  printf(">>>>> Carregando arquivo...\n");

  contador_linha = counting_lines(in);
  linha = (char *) malloc((TAMANHO + 1) * sizeof(char));

  preenche_comandos();
  ListaSequencial * linhas = cria_lista(contador_linha);
  contador_linha = 0;

  while(in && fgets(linha, TAMANHO, in)){
    if( (quebra_de_linha = strrchr(linha, '\n')) ) *quebra_de_linha = 0;

    push(linhas, linha);
    copia_ponteiro_linha = linha;

    while ( (palavra = my_strsep(&copia_ponteiro_linha, " -/")) ) {
      guardar_palavra(palavra);
    }

    contador_linha++;
  }

  printf(">>>>> Arquivo carregado!\n");
  printf("Arquivo: '%s'\n", argv[1]);
  printf("Tipo de indice: '%s'\n", argv[2]);
  printf("Numero de linhas no arquivo: %d\n", contador_linha);
  printf("Total de palavras unicas indexadas: XXXXX\n");
  if (strcmp(TIPO_INDICE, "arvore") == 0) 
    printf("Altura da arvore: XXXX\n");
  
  pede_comando();

  // libera na memoria
  destroi_sequencial(linhas);
  destroi_sequencial(listaComandos);
  free(linha);

  return 0;
}