#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define TAMANHO 10000

// ---------------------------
// -- Funções Auxiliares
// ---------------------------

static char * my_strsep(char **stringp, const char *delim) {
  char *s;
  const char *spanp;
  int c, sc;
  char *tok;

  if ((s = *stringp) == NULL)
    return NULL;

  for (tok = s;;) {
    c = *s++;
    spanp = delim;
    do {
      if ((sc = *spanp++) == c) {
        if (c == 0) {
          *stringp = NULL;
          return tok;
        }
        s[-1] = '\0';
        *stringp = s;
        return tok;
      }
    } while (sc != 0);
  }
}

void trim(char *str, const char *trim_chars) {
  char *end;

  // trim inicio
  while (*str && strchr(trim_chars, *str)) {
    str++;
  }

  // se virou string vazia
  if (*str == 0)
    return;

  // trim final
  end = str + strlen(str) - 1;
  while (end > str && strchr(trim_chars, *end)) {
    *end-- = '\0';
  }
}

void tolower_string(char *str) {
  for (int i = 0; str[i] != '\0'; i++) {
    str[i] = tolower(str[i]);
  }
}

int counting_lines(FILE * f) {
  char c;
  int count = 1;

  // conta cada '\n'
  do {
    c = fgetc(f);
    if (c == '\n') count++;
  } while (c != EOF);

  // volta para o início do arquivo
  rewind(f);

  return count;
}

// ---------------------------
// -- Função principal
// ---------------------------

int main(int argc, char ** argv){

	FILE * in;
	char * linha;
	char * copia_ponteiro_linha;
	char * quebra_de_linha;
	char * palavra;	
	int contador_linha;

	if(argc < 3) {
    printf("Insira o caminho do arquivo!");
    return 1;
  }

  in = fopen(argv[1], "r");

  if (in == NULL) {
    printf("Arquivo inválido!");
    return 1;
  }

  printf(">>>>> Carregando arquivo...\n");

  contador_linha = counting_lines(in);
  linha = (char *) malloc((TAMANHO + 1) * sizeof(char));
  contador_linha = 0;

  while(in && fgets(linha, TAMANHO, in)){
    
    if( (quebra_de_linha = strrchr(linha, '\n')) ) *quebra_de_linha = 0;

    printf("linha %03d: '%s'\n", contador_linha + 1, linha);

    // fazemos uma copia do endereço que corresponde ao array de chars 
    // usado para armazenar cada linha lida do arquivo pois a função 'strsep' 
    // modifica o endereço do ponteiro a cada chamada feita a esta função (e 
    // não queremos que 'linha' deixe de apontar para o inicio do array).

    copia_ponteiro_linha = linha;

    while ( (palavra = my_strsep(&copia_ponteiro_linha, " -/")) ) {
      // antes de guardar a palavra em algum tipo de estrutura usada
      // para implementar o índice, será necessário fazer uma copia
      // da mesma, uma vez que o ponteiro 'palavra' aponta para uma 
      // substring dentro da string 'linha', e a cada nova linha lida
      // o conteúdo da linha anterior é sobreescrito.
      tolower_string(palavra);
      trim(palavra, ".,?:;!");
      printf("\t\t'%s'\n", palavra);
    }

    contador_linha++;
  }

  printf(">>>>> Arquivo carregado!\n");
  printf("Arquivo: '%s'\n", argv[1]);
  printf("Tipo de indice: '%s'\n", argv[2]);
  printf("Número de linhas no arquivo: %d", contador_linha);

  return 0;
}