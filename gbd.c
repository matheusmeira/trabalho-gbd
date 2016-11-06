#include "gbd.h"

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}

// --------------------------------------------------------

int Aloca_Area_BD () {
	// O objetivo eh alocar uma área para criar o banco de dados
	BancoDeDados * BD = malloc(sizeof(BancoDeDados));

	if (BD == NULL) {
		printf("Problemas para alocar o espaco de memoria.\n");
		return 0;
	}
	printf("Endereco alocado com sucesso.\n");
	return 1;
}
// --------------------------------------------------------

void Desaloca_Area_BD (BancoDeDados * BD) {
	free (BD);
	BD = NULL;
}