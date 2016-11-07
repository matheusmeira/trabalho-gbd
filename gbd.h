#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50

typedef struct atributo
{
	char nomeDoAtributo[MAX];
	char tipoDoAtributo;
}TipoAtributo;

typedef struct tabela
{
	char nomeDaTabela[MAX];
	int numDeAtributos;
	char chavePrimaria[MAX];
	//atributos
	TipoAtributo * atributos;
}TipoTabela;

typedef struct catalogo
{
	char nomeCatalogo[MAX];
	char nomeDoBancoDeDados[MAX];
	char enderecoDoBanco[MAX];
	int tamanhoDoBanco;
	//tabelas do banco
	TipoTabela * tabelas;
}TipoCatalogo;

typedef struct bancoDeDados
{
	//catálogo
	TipoCatalogo * catalogo;
	int numDeCatalogos;
}BancoDeDados;

// ----------------------------------------------
BancoDeDados * Aloca_Area_BD ();
void Desaloca_Area_BD (BancoDeDados * BD);
BancoDeDados * Cria_BD (char nomeDaBaseDeDados[], char enderecoDaBase[], int tamanhoDaBase, int numDeCatalogos);
int ArmazenaCatalogoNoAquivo (BancoDeDados * BD);
int VerificaArquivo (FILE * arq);
void LeituraDeArquivo (FILE * arq, BancoDeDados * BD);