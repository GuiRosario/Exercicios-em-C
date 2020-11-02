#include <stdio.h>
#include <stdlib.h>
void main(void){
	char palavra[5][100];

	FILE *file;
	file = fopen("String.txt","r");
	
	if(file == NULL){
		printf("nao foi possivel abrir o arquivo");
		getchar();
		exit(0);
	}

	for(int x = 0; x < 5;x++){
		fscanf(file,"%s",palavra[x]);		
	}


	printf("%s",palavra[1]);

	fclose(file);

}