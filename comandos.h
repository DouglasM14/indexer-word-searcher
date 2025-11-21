#ifndef COMANDOS_H
#define COMANDOS_H

#include "lista_sequencial.h"

#define NUM_COMANDOS 10

// importa variáveis globais
extern char TIPO_INDICE[];
extern ListaSequencial * listaComandos;

Boolean valida_comando(char * comando);
void executa_comando(char * comando, char * argumento);
void preenche_comandos();
void pede_comando();

#endif