#include <stdio.h>
#include <string.h> 
#include <stdlib.h>

int posi[30];
int ciguais = 0;
int vciguais = 0;
void main(void){
	int averig(char palavra[30],char letra,int tamanho);
	void forca(char palavra[30],char letra,int tamanho,int chances);
	char palavra[30];
	int chances;
	int tamanho;
	int comp;
	char letra;
	int	niveis = 0;
	int resultado = 0;
    scanf("%s",palavra);
    setbuf(stdin, NULL);
    tamanho = strlen(palavra);
    for(comp = 0;comp < tamanho;comp++){
    	posi[comp] = -1;
    }
    for(chances = 0;chances < 6;chances++){
    	printf("\e[H\e[2J");
    	forca(palavra,letra,tamanho,chances);
    	for(;niveis < tamanho-vciguais;niveis++){
    		ciguais = 0;
    		scanf(" %c",&letra);
    		if(averig(palavra,letra,tamanho) == 1){
    			printf("\e[H\e[2J");
    			forca(palavra,letra,tamanho,chances);
    			resultado++;
    		}else{
    			printf("Voce errou!\n");
    			break;
    		}

    	}

    	resultado += vciguais;

    	if(resultado == tamanho){
    		printf("Voce Ganhou!");
    		exit(1);
    	}

    }
    printf("Voce Perdeu!");
}
int averig(char palavra[30],char letra,int tamanho){
	int tester;
	int anali1 = 0;
	int anali2 = 0;

	for(tester = 0;tester < tamanho;tester++){
		if(palavra[tester] == letra){
			posi[tester] = tester;
			anali1 = 1;
			ciguais++;
			if(ciguais == 2){
				vciguais++;
			}
		}else{
				anali2 = 1;		
		}
	}

	if(anali1 == 1 && anali2 == 1){
		return 1;
	}
	else if(anali1 == 0 && anali2 == 1){
		return 0;
	}

}
void forca(char palavra[30],char letra,int tamanho,int chances){
	int imp;
	switch(chances){
		case 0:
			printf("------\n|    |\n|    @\n|   /|\\ \n|    |\n|   / \\    ");
			for(imp = 0;imp < tamanho;imp++){
				if(posi[imp] >= 0){
					printf("%c ",palavra[imp]);
				}else{
					printf("0 ");
				}
			}
			printf("\n");
			printf("|_____     ");
			for(imp = 0;imp<tamanho;imp++){
				printf("_ ");
			}
			printf("\n");
			break;
		case 1:
			printf("------\n|    |\n|    @\n|   /|\\ \n|    |\n|   /      ");
			for(imp = 0;imp < tamanho;imp++){
				if(posi[imp] >= 0){
					printf("%c ",palavra[imp]);
				}else{
					printf("0 ");
				}
			}
			printf("\n");
			printf("|_____     ");
			for(imp = 0;imp<tamanho;imp++){
				printf("_ ");
			}
			printf("\n");
			break;
		case 2:
			printf("------\n|    |\n|    @\n|   /|\\ \n|    |\n|         ");
			for(imp = 0;imp < tamanho;imp++){
				if(posi[imp] >= 0){
					printf("%c ",palavra[imp]);
				}else{
					printf("0 ");
				}
			}
			printf("\n");
			printf("|_____    ");
			for(imp = 0;imp<tamanho;imp++){
				printf("_ ");
			}
			printf("\n");
			break;
		case 3:
			printf("------\n|    |\n|    @\n|   /|\\ \n|    \n|          ");
			for(imp = 0;imp < tamanho;imp++){
				if(posi[imp] >= 0){
					printf("%c ",palavra[imp]);
				}else{
					printf("0 ");
				}
			}
			printf("\n");
			printf("|_____     ");
			for(imp = 0;imp<tamanho;imp++){
				printf("_ ");
			}
			printf("\n");
			break;
		case 4:
			printf("------\n|    |\n|    @\n|   /|   \n|     \n|          ");
			for(imp = 0;imp < tamanho;imp++){
				if(posi[imp] >= 0){
					printf("%c ",palavra[imp]);
				}else{
					printf("0 ");
				}
			}
			printf("\n");
			printf("|_____     ");
			for(imp = 0;imp<tamanho;imp++){
				printf("_ ");
			}
			printf("\n");
			break;
		case 5:
			printf("------\n|    |\n|    @\n|        \n|     \n|          ");
			for(imp = 0;imp < tamanho;imp++){
				if(posi[imp] >= 0){
					printf("%c ",palavra[imp]);
				}else{
					printf("0 ");
				}
			}
			printf("\n");
			printf("|_____    ");
			for(imp = 0;imp<tamanho;imp++){
				printf("_ ");
			}
			printf("\n");
			break;
	}
}