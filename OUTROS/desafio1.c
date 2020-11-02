#include <stdio.h>

int main()
{
	int n;
	int resultado = 1;

	scanf("%i",&n);

	while(n >= 1){

	resultado = resultado * n;
	n = n - 1;

	}
	
	printf("%i\n",resultado);

	return 0;
}