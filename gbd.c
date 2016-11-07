#include "gbd.h"

int main(int argc, char const *argv[])
{
	BancoDeDados * BD;
	FILE * arq;
	char nomeDaBaseDeDados[MAX], enderecoDaBase[MAX], url[] = "arquivo.txt";
	int itemMenu = 0, tamanhoDaBase = 0, numDeCatalogos = 0;
	/*
	Inicialmente estamos abrindo o arquivo e verificando se existe 
	algum banco de dados já criado.
	*/
	arq = fopen(url, "a+");
	numDeCatalogos = VerificaArquivo(arq);
	if (numDeCatalogos != 0) {
		/*
		Caso o retorno da função VerificaArquivo seja diferente de 0, teremos que ler as informações do arquivo
		e armazenar na memória. 
		Sugestão: utilizar a função de nome LeituraDeArquivo para tal função.
		Após a leitura, podemos entrar no laço e criar novos bacos se necessário.
		*/
	}
	while(1) {
		printf("1- Criar novo banco de dados.\n");
		printf("2- Listar bancos de dados existentes.\n");
		printf("3- Excluir um banco de dados.\n");
		printf("Escolha um item no menu: \n");
		scanf("%d", &itemMenu);
		switch (itemMenu) {
			case 1:
				/*
					A seguir, configurei um teste para identificar se as strings estão sendo salvas
				*/
				// scanf("%s", nomeDaBaseDeDados);
				// scanf("%s", enderecoDaBase);
				// BD = Cria_BD(nomeDaBaseDeDados, enderecoDaBase, tamanhoDaBase);
				// printf("%s\n", BD->catalogo->nomeDoBancoDeDados);
				// printf("%s\n", BD->catalogo->enderecoDoBanco);
				// --------------------------------------------------------------------------------
				break;
			case 2:
				break;
			case 3:
				break;
			default:
				printf("Opção invalida.\n");
		}
	}
	return 0;
}

// --------------------------------------------------------

BancoDeDados * Aloca_Area_BD () {
	// O objetivo eh alocar uma área para criar o banco de dados
	BancoDeDados * BD = malloc(sizeof(BancoDeDados));

	return BD;
}
// --------------------------------------------------------

void Desaloca_Area_BD (BancoDeDados * BD) {
	free (BD);
	BD = NULL;
}
// --------------------------------------------------------

BancoDeDados * Cria_BD (char nomeDaBaseDeDados[], char enderecoDaBase[], int tamanhoDaBase, int numDeCatalogos) {
	// Variáveis necessárias
	BancoDeDados * BD;
	// Alocando area na memoria para o Banco de dados
	BD = Aloca_Area_BD();
	// Necessario verificar se a alocação ocorreu como esperado 
	if (BD == NULL) {
		printf("Problemas para alocar o espaco de memoria.\n");
		return NULL;
	}
	/*
	O próximo if se faz necessário por que não sabemos se já existem BD criados.
	Caso não existam, é necessário zerar essa variável de controle.
	*/
	if (numDeCatalogos == 0) {
		BD->numDeCatalogos = 0;
	}
	// Necessário alocar um catálogo para o novo banco de dados
	BD->catalogo = malloc (sizeof(TipoCatalogo));
	if (BD->catalogo == NULL) {
		printf("Problemas para alocar o espaco de memoria necessario para o catalogo.\n");
		return NULL;
	}
	// Setando a quantidade de catálogos
	BD->numDeCatalogos++;
	// Nome da base de dados recebido como parâmetro da função
	strcpy(BD->catalogo->nomeDoBancoDeDados, nomeDaBaseDeDados);
	// Endereço da base de dados recebido como parâmetro da função
	strcpy(BD->catalogo->enderecoDoBanco, enderecoDaBase);
	// Por enquanto, vamos definir que o nome do catálogo é o mesmo que o do banco
	strcpy(BD->catalogo->nomeCatalogo, nomeDaBaseDeDados);

	return BD;
}
// -----------------------------------------------------------
int ArmazenaCatalogoNoAquivo (BancoDeDados * BD) {

	/*
	Objetivo: Para cada novo BD criado, devemos gravar as informações no arquivo.
	Tais como: nome do banco de dados, endereço do banco, nome do catálogo, tamanho do banco
	*/

}
// -----------------------------------------------------------
int VerificaArquivo (FILE * arq) {
	/*
	Entrada: endereço arq para um arquivo
	Saida: 0 se não existe catálogo criado ou 1 caso contrário
	*/
	char ch1;
	fscanf(arq,"%c\n", &ch1);
	int valor = atoi(&ch1);
	if (valor != 0) {
		return 1;
	}
	return 0;
}
// -----------------------------------------------------------
void LeituraDeArquivo (FILE * arq, BancoDeDados * BD) {
	/*
	Entrada: endereço arq para um arquivo
	Objetivo: Ler o arquivo e colocando os dados na memória através do BD
	*/

}