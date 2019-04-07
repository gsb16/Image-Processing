
// GRR 20166812 -- Gabriel de Souza Barreto

#include "parametros.h"
#include "estrutfuncpgm.h"


FILE *entrada, *saida;

int main(int argc, char **argv)
{
	imagepgm figura, espelho;
	int total;

	
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

	
	//Calcula a media dos termos do meio

	for (int i = 1; i < (figura.linha-1); i++)
	{
		for (int j = 1; j < (figura.coluna-1); j++)
		{
			total = 0;
			total += figura.matrizpgm[i-1][j-1];  
			total += figura.matrizpgm[i-1][j];  
			total += figura.matrizpgm[i-1][j+1]; 
			total += figura.matrizpgm[i][j-1]; 
			total += figura.matrizpgm[i][j]; 
			total += figura.matrizpgm[i][j+1]; 
			total += figura.matrizpgm[i+1][j-1]; 
			total += figura.matrizpgm[i+1][j];  
			total += figura.matrizpgm[i+1][j+1];

			//Novo valor daquele termo

			espelho.matrizpgm[i][j] = total/9; 
		}
	}

	
	//Calcula a media dos termos dos cantos

	//Superior esquerdo

	total = 0;
	total += figura.matrizpgm[0][0];  
	total += figura.matrizpgm[0][1];  
	total += figura.matrizpgm[1][0]; 
	total += figura.matrizpgm[1][1];
	espelho.matrizpgm[0][0] = total/4;

	//Superior direito

	total = 0;
	total += figura.matrizpgm[0][figura.coluna-2];  
	total += figura.matrizpgm[0][figura.coluna-1];  
	total += figura.matrizpgm[1][figura.coluna-2]; 
	total += figura.matrizpgm[1][figura.coluna-1];
	espelho.matrizpgm[0][figura.coluna-1] = total/4;

	//Inferior direito

	total = 0;
	total += figura.matrizpgm[figura.linha-2][figura.coluna-2];  
	total += figura.matrizpgm[figura.linha-2][figura.coluna-1];  
	total += figura.matrizpgm[figura.linha-1][figura.coluna-2]; 
	total += figura.matrizpgm[figura.linha-1][figura.coluna-1];
	espelho.matrizpgm[figura.linha-1][figura.coluna-1] = total/4;

	//Inferior esquerdo

	total = 0;
	total += figura.matrizpgm[figura.linha-1][0];  
	total += figura.matrizpgm[figura.linha-1][1];  
	total += figura.matrizpgm[figura.linha-2][0]; 
	total += figura.matrizpgm[figura.linha-2][1];
	espelho.matrizpgm[figura.linha-1][0] = total/4;


	//Calcula a media dos termos nas bordas sem os cantos

	//Esquerda

	for (int k = 1; k < figura.linha-1; k++)
	{
		total = 0;
		total += figura.matrizpgm[k-1][0];
		total += figura.matrizpgm[k][0];
		total += figura.matrizpgm[k+1][0];
		total += figura.matrizpgm[k-1][1];
		total += figura.matrizpgm[k][1];
		total += figura.matrizpgm[k+1][1];

		//Novo valor daquele termo

		espelho.matrizpgm[k][0] = total/6;
	}

	//Direita

	for (int k = 1; k < figura.linha-1; k++)
	{
		total = 0;
		total += figura.matrizpgm[k-1][figura.coluna-2];
		total += figura.matrizpgm[k][figura.coluna-2];
		total += figura.matrizpgm[k+1][figura.coluna-2];
		total += figura.matrizpgm[k-1][figura.coluna-1];
		total += figura.matrizpgm[k][figura.coluna-1];
		total += figura.matrizpgm[k+1][figura.coluna-1];

		//Novo valor daquele termo

		espelho.matrizpgm[k][figura.coluna-1] = total/6;
	}

	//Topo

	for (int k = 1; k < figura.coluna-1; k++)
	{
		total = 0;
		total += figura.matrizpgm[0][k-1];
		total += figura.matrizpgm[0][k];
		total += figura.matrizpgm[0][k+1];
		total += figura.matrizpgm[1][k-1];
		total += figura.matrizpgm[1][k];
		total += figura.matrizpgm[1][k+1];

		//Novo valor daquele termo

		espelho.matrizpgm[0][k] = total/6;
	}

	//Embaixo

	for (int k = 1; k < figura.coluna-1; k++)
	{
		total = 0;
		total += figura.matrizpgm[figura.linha-2][k-1];
		total += figura.matrizpgm[figura.linha-2][k];
		total += figura.matrizpgm[figura.linha-2][k+1];
		total += figura.matrizpgm[figura.linha-1][k-1];
		total += figura.matrizpgm[figura.linha-1][k];
		total += figura.matrizpgm[figura.linha-1][k+1];

		//Novo valor daquele termo

		espelho.matrizpgm[figura.linha-1][k] = total/6;
	}


	PGMprint(&espelho, saida);

	return 0;

}
