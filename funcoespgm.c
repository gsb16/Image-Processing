
// GRR 20166812 -- Gabriel de Souza Barreto

#include <stdlib.h>
#include "estrutfuncpgm.h"
#include <ctype.h>


//Funcao leitura imagem

void PGMleitura(imagepgm *image, FILE *fpont)
{
	//Leitura do cabecalho PGM ignorando os comentarios

	ignoracoment(fpont);
	fscanf(fpont, "P%u", (unsigned int *)&image->type);
	ignoracoment(fpont);
	fscanf(fpont, "%u %u", (unsigned int *)&image->coluna, (unsigned int *)&image->linha);
	ignoracoment(fpont);
	fscanf(fpont, "%u", (unsigned int *)&image->Maxgrey);
	ignoracoment(fpont);

	//Libera memoria para imagem

	PGMaloc(image);

	//Leitura da imagem P2

	if (image->type == 2)
	{
		for (int i = 0; i < image->linha; i++)
		{
			for (int j = 0; j < image->coluna; j++)
			{
				fscanf(fpont, "%u", (unsigned int *)&image->matrizpgm[i][j]);
			}
		}

	//Leitura da imagem P5

	} else if (image->type == 5)
	{
		for (int k = 0; k < image->linha; k++)
		{
			fread(image->matrizpgm[k], sizeof(unsigned char), image->coluna, fpont);
		}
	
	//Formato nao reconhecido
	
	} else 
	{
		perror("Erro no formato da imagem. \n");
		exit(1);
	}
}



//Funcao aloca memoria

void PGMaloc(imagepgm *image)
{
	
	//Alocacao de vetor para as linhas

	image->matrizpgm = (unsigned char **)malloc(image->linha * sizeof(unsigned char *));
	for (int k = 0; k < image->linha; k++)
	{

		//Alocacao de vetor para colunas
		
		image->matrizpgm[k] = (unsigned char *)malloc(image->coluna * sizeof(unsigned char *));
	}
}



//Funcao print imagem

void PGMprint(imagepgm *image, FILE *fpont)
{
	
	//Parte do cabecalho
	
	fprintf(fpont, "P2\n");
	fprintf(fpont, "%d %d\n", image->coluna, image-> linha);
	fprintf(fpont, "%hd\n", image->Maxgrey);

	//Parte da imagem -- Matriz PGM

	for (int i = 0; i < image->linha; i++)
	{
		for (int j = 0; j < image->coluna; j++)
		{
			fprintf(fpont, "%u ", image->matrizpgm[i][j]);
		}
		fprintf(fpont, "\n");
	}

}



//Funcao ignora comentario

void ignoracoment(FILE *fpont)
{
	
	//Quando recebe "#" no inicio, espera o final da linha

	char cha = fgetc(fpont); 
	while(cha == '#' || isspace(cha))
	{
		while(cha != '\n')
		{
			cha = fpont?fgetc(fpont):fgetc(stdin);
		}
		cha = fpont?fgetc(fpont):fgetc(stdin);
	}

	fseek(fpont, -1, SEEK_CUR);

	//Char extra lido, retorna uma posicao

}
