
// GRR 20166812 -- Gabriel de Souza Barreto

#include "parametros.h"
#include "estrutfuncpgm.h"
#include <stdlib.h>
#include <string.h>


FILE *entrada, *saida;

//Funcao para comparar os termos no quicksort
int comparador(const void *a, const void *b)
{
    return *(unsigned char *)a - *(unsigned char *)b;
}


int main(int argc, char **argv)
{
	imagepgm figura, espelho;
	
	
	//Abre, salva na memoria e fecha o arquivo

	argumentoEntrada(argc, argv, &entrada);
	PGMleitura(&figura, entrada);
	fclose(entrada);
	argumentoSaida(argc, argv, &saida);

	
	//Faz a copia dos atributos da imagem para um espelho

	espelho.Maxgrey = figura.Maxgrey;
	espelho.coluna = figura.coluna;
	espelho.linha = figura.linha;
	PGMaloc(&espelho);

	//Calcula a mediana dos termos do meio

	for (int i = 1; i < (figura.linha-1); i++)
	{
		for (int j = 1; j < (figura.coluna-1); j++)
		{
			unsigned char valores[9];

			valores[0] += figura.matrizpgm[i-1][j-1];  
			valores[1] += figura.matrizpgm[i-1][j];  
			valores[2] += figura.matrizpgm[i-1][j+1]; 
			valores[3] += figura.matrizpgm[i][j-1]; 
			valores[4] += figura.matrizpgm[i][j]; 
			valores[5] += figura.matrizpgm[i][j+1]; 
			valores[6] += figura.matrizpgm[i+1][j-1]; 
			valores[7] += figura.matrizpgm[i+1][j];  
			valores[8] += figura.matrizpgm[i+1][j+1];

			//Novo valor daquele termo

			qsort(valores, strlen((const char *)valores), sizeof(unsigned char), comparador);
			espelho.matrizpgm[i][j] = valores[4]; 
		}
	}

	
	//Calcula a mediana dos termos dos cantos

	//Superior esquerdo
	
	unsigned char valores[4];
	
	valores[0] += figura.matrizpgm[0][0];  
	valores[1] += figura.matrizpgm[0][1];  
	valores[2] += figura.matrizpgm[1][0]; 
	valores[3] += figura.matrizpgm[1][1];
	
	qsort(valores, strlen((const char *)valores), sizeof(unsigned char), comparador);
	espelho.matrizpgm[0][0] = (valores[1] + valores[2])/2; 

	
	//Superior direito

	
	valores[0] += figura.matrizpgm[0][figura.coluna-2];  
	valores[1] += figura.matrizpgm[0][figura.coluna-1];  
	valores[2] += figura.matrizpgm[1][figura.coluna-2]; 
	valores[3] += figura.matrizpgm[1][figura.coluna-1];
	
	qsort(valores, strlen((const char *)valores), sizeof(unsigned char), comparador);
	espelho.matrizpgm[0][figura.coluna-1] = (valores[1] + valores[2])/2;


	//Inferior direito

	
	valores[0] += figura.matrizpgm[figura.linha-2][figura.coluna-2];  
	valores[1] += figura.matrizpgm[figura.linha-2][figura.coluna-1];  
	valores[2] += figura.matrizpgm[figura.linha-1][figura.coluna-2]; 
	valores[3] += figura.matrizpgm[figura.linha-1][figura.coluna-1];
	
	qsort(valores, strlen((const char *)valores), sizeof(unsigned char), comparador);
	espelho.matrizpgm[figura.linha-1][figura.coluna-1] = (valores[1] + valores[2])/2;


	//Inferior esquerdo

	
	valores[0] += figura.matrizpgm[figura.linha-1][0];  
	valores[1] += figura.matrizpgm[figura.linha-1][1];  
	valores[2] += figura.matrizpgm[figura.linha-2][0]; 
	valores[3] += figura.matrizpgm[figura.linha-2][1];
	
	qsort(valores, strlen((const char *)valores), sizeof(unsigned char), comparador);
	espelho.matrizpgm[figura.linha-1][0] = (valores[1] + valores[2])/2;



	//Calcula a mediana dos termos nas bordas sem os cantos

	//Esquerda

	for (int k = 1; k < figura.linha-1; k++)
	{
		unsigned char valores[6];

		valores[0] += figura.matrizpgm[k-1][0];
		valores[1] += figura.matrizpgm[k][0];
		valores[2] += figura.matrizpgm[k+1][0];
		valores[3] += figura.matrizpgm[k-1][1];
		valores[4] += figura.matrizpgm[k][1];
		valores[5] += figura.matrizpgm[k+1][1];

		//Novo valor daquele termo

		qsort(valores, strlen((const char *)valores), sizeof(unsigned char), comparador);
		espelho.matrizpgm[k][0] = (valores[2] + valores[3])/2;

	}

	//Direita

	for (int k = 1; k < figura.linha-1; k++)
	{
		unsigned char valores[6];

		valores[0] += figura.matrizpgm[k-1][figura.coluna-2];
		valores[1] += figura.matrizpgm[k][figura.coluna-2];
		valores[2] += figura.matrizpgm[k+1][figura.coluna-2];
		valores[3] += figura.matrizpgm[k-1][figura.coluna-1];
		valores[4] += figura.matrizpgm[k][figura.coluna-1];
		valores[5] += figura.matrizpgm[k+1][figura.coluna-1];

		//Novo valor daquele termo

		qsort(valores, strlen((const char *)valores), sizeof(unsigned char), comparador);
		espelho.matrizpgm[k][figura.coluna-1] = (valores[2] + valores[3])/2;

	}

	//Topo

	for (int k = 1; k < figura.coluna-1; k++)
	{
		unsigned char valores[6];

		valores[0] += figura.matrizpgm[0][k-1];
		valores[1] += figura.matrizpgm[0][k];
		valores[2] += figura.matrizpgm[0][k+1];
		valores[3] += figura.matrizpgm[1][k-1];
		valores[4] += figura.matrizpgm[1][k];
		valores[5] += figura.matrizpgm[1][k+1];

		//Novo valor daquele termo

		qsort(valores, strlen((const char *)valores), sizeof(unsigned char), comparador);
		espelho.matrizpgm[0][k] = (valores[2] + valores[3])/2;

	}

	//Embaixo

	for (int k = 1; k < figura.coluna-1; k++)
	{
		unsigned char valores[6];

		valores[0] += figura.matrizpgm[figura.linha-2][k-1];
		valores[1] += figura.matrizpgm[figura.linha-2][k];
		valores[2] += figura.matrizpgm[figura.linha-2][k+1];
		valores[3] += figura.matrizpgm[figura.linha-1][k-1];
		valores[4] += figura.matrizpgm[figura.linha-1][k];
		valores[5] += figura.matrizpgm[figura.linha-1][k+1];

		//Novo valor daquele termo

		qsort(valores, strlen((const char *)valores), sizeof(unsigned char), comparador);
		espelho.matrizpgm[figura.linha-1][k] = (valores[2] + valores[3])/2;		

	}

	PGMprint(&espelho, saida);

	return 0;

}
	