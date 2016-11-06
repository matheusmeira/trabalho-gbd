#include <stdio.h>
#include <stdlib.h>

typedef struct atributo
{
	char nomeDoAtributo;
	char tipoDoAtributo;
}TipoAtributo;

typedef struct tabela
{
	char nomeDaTabela;
	int numDeAtributos;
	char chavePrimaria;
	//atributos
	TipoAtributo * atributos;
}TipoTabela;

typedef struct catalogo
{
	char nomeCatalogo;
	char nomeDoBancoDeDados;
	char enderecoDoBanco;
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
int Aloca_Area_BD ();
void Desaloca_Area_BD (BancoDeDados * BD);