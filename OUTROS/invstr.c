#include <stdio.h>
#include <string.h>

int main(){
	char palavra[20];
	char palavracopia[20];
	int tamanho;

	scanf("%s",palavra);

	strcpy(palavracopia,palavra);
	tamanho = strlen(palavra);
	printf("%i\n",tamanho);

	for(int i = 0;i < tamanho;i++){
		palavra[tamanho - (i+1)] = palavracopia[i];
	}

	printf("%s\n",palavra);
	return 0;

}