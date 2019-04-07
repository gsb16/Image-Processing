
// GRR 20166812 -- Gabriel de Souza Barreto

#include <stdio.h>
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

	for (int i = 0; i < figura.linha; i++)
	{
		for (int j = 0; j < figura.coluna; j++)
		{
			//Troca o valor pelo seu complemento na escala de cinza

			figura.matrizpgm[i][j] = figura.Maxgrey - figura.matrizpgm[i][j];
		}
	}

	PGMprint(&figura, saida);

	return 0;
}
