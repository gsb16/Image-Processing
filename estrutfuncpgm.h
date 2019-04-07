
// GRR 20166812 -- Gabriel de Souza Barreto

#include <stdio.h>


//Estrutura PGM

typedef struct imagem_pgm
{
	unsigned char **matrizpgm;
	unsigned char type;
	unsigned char Maxgrey;
	int linha;
	int coluna;
} imagepgm;

//Funcao aloca memoria

void PGMaloc(imagepgm *image);

//Funcao leitura imagem

void PGMleitura(imagepgm *image, FILE *fpont);

//Funcao print imagem

void PGMprint(imagepgm *image, FILE *fpont);

void ignoracoment(FILE *fpont);
