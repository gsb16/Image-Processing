
// GRR 20166812 -- Gabriel de Souza Barreto

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void argumentoEntrada(int quantos, char **comandos, FILE **entra)
{
	for (int k = 1; k < (quantos - 1); k++)
	{
		if (!strcmp(comandos[k], "-i"))
		{
			*entra = fopen(comandos[k+1], "r");
			if (!*entra)
			{
				perror("Erro na abertura do arquivo");
				exit(1);
			}
		}
	}
	if (!*entra)
	{
		*entra = stdin;

		//Usa a entrada padrao na ausencia de arquivo
	}
}



//Funcao leitura de limiar

double lelimiar(int quantos, char **comandos)
{
	double li = 0.5;

	//Limiar padrao

	for (int k = 1; k < (quantos-1); k++)
	{
		if (!strcmp(comandos[k], "-l"))
		{
			sscanf(comandos[k+1], "%lf", &li);
		}
	}

	return li;
}



void argumentoSaida(int quantos, char **comandos, FILE **sai)
{
	for (int k = 1; k < (quantos-1); k++)
	{
		if (!strcmp(comandos[k], "-o"))
		{
			*sai = fopen(comandos[k+1], "w");
			if (!*sai)
			{
				perror("Erro ao criar arquivo");
				exit(1);
			}
		}
	}

	if (!*sai)
	{
		*sai = stdout;

		//Usa a saida padrao na ausencia de arquivo
	}
}
