
// GRR 20166812 -- Gabriel de Souza Barreto

#include "parametros.h"
#include "estrutfuncpgm.h"


FILE *entrada, *saida;

int main(int argc, char **argv)
{
	imagepgm figura;

	//Abre, salva na memoria e fecha o arquivo

	argumentoEntrada(argc, argv, &entrada);
	PGMleitura(&figura, entrada);
	fclose(entrada);
	argumentoSaida(argc, argv, &saida);

	double li = lelimiar(argc, argv) * figura.Maxgrey;
	
	//O limiar foi escolhido

	for (int i = 0; i < figura.linha; i++)
	{
		for (int j = 0; j < figura.coluna; j++)
		{
			figura.matrizpgm[i][j] = figura.matrizpgm[i][j]>li?figura.Maxgrey:0;

			//Coloca 0 para valor abaixo do limiar e branco para valor acima ou igual ao limiar
		}
	}

	PGMprint(&figura, saida);

	return 0; 	
}
