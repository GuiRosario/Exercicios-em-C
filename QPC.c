#include <stdio.h>


int main()
{
	int base;
	int altura;
	int area;

	printf("Digite o valor da base:");
	scanf("%i", &base);

	printf("Digite o valor da altura:");
	scanf("%i", &altura);

	printf("Digite o valor da area:");
	scanf("%i", &area);

	printf("O valor da base e = %i.\nO valor da altura e = %i.\nO valor da area e = %i.\n", base, altura, area);

	return 0;
}