#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char palavra[100];
char palavraEAP[100];
char palavraF[20][100];
char palavraO[20][100];
char palavraA[20][100];
int selec;
int selec2;
int posi[100];
int ale;
char pres[100];
int ciguais = 0;
int vciguais = 0;
int resultado = 0;

void main(void){

	void EAP();
	void Objeto();
	void Fruta();
	void Animal();

	int x = 1;
	while(x == 1){
		resultado = 0;
		system("clear");		
		printf(" ___________________________________________________________\n");
		printf("|                          |FORCA|                          |\n");
		printf("|                                                           |\n");
		printf("|Escolha uma das opcoes:                                    |\n");
		printf("|(1) Escreva a palavra.                                     |\n");
		printf("|(2) Temas.                                                 |\n");
		printf("|(3) Sair do Jogo.                                          |\n");
		printf("|-----------------------------------------------------------|\n");

		scanf("%i",&selec);

		system("clear");

		switch(selec){
			case 1:
				EAP();
				break;
			case 2:
				printf(" ___________________________________________________________\n");
				printf("|                         |FORCA|                           |\n");
				printf("|                                                           |\n");
				printf("|Escolha uma das opcoes:                                    |\n");
				printf("|(1) Objeto.                                                |\n");
				printf("|(2) Fruta.                                                 |\n");
				printf("|(3) Animal.                                                |\n");
				printf("|-----------------------------------------------------------|\n");

				scanf("%i",&selec2);

				system("clear");

				switch(selec2){
					case 1:
						Objeto();
						break;
					case 2:
						Fruta();
						break;
					case 3:
						Animal();
						break;
				}

				break;
			case 3:
				exit(0);
				break;
		}
	}
}
void EAP(){
	void sele();

	scanf("%s",palavraEAP);

	sele();
}
void Objeto(){
	void sele();

	srand(time(NULL));

	FILE *Obj;
	Obj = fopen("objeto.txt","r");

	for(int z = 0; z < 20;z++){
		fscanf(Obj,"%s",palavraO[z]);		
	}
	ale = rand() % 19;

	fclose(Obj);

	sele();
}
void Fruta(){
	void sele();

	srand(time(NULL));

	FILE *Frt;
	Frt = fopen("fruta.txt","r");

	for(int z = 0; z < 20;z++){
		fscanf(Frt,"%s",palavraF[z]);		
	}

	ale = rand() % 19;

	fclose(Frt);

	sele();		
}
void Animal(){
	void sele();

	srand(time(NULL));

	FILE *Anm;
	Anm = fopen("animal.txt","r");

	for(int z = 0; z < 20;z++){
		fscanf(Anm,"%s",palavraA[z]);		
	}

	ale = rand() % 19;

	fclose(Anm);

	sele();	

}

void sele(){

	void forca();

	if(selec == 1){
		strcpy(palavra,palavraEAP);
	}
	else if(selec == 2 && selec2 == 1){
		strcpy(palavra,palavraO[ale]);
	}
	else if(selec == 2 && selec2 == 2){
		strcpy(palavra,palavraF[ale]);
	}
	else if(selec == 2 && selec2 == 3){
		strcpy(palavra,palavraA[ale]);		
	}

	forca();	
}

void forca(){

void printar(int tamanho,int tentativa);
int analise(char letra,int tamanho);
void limparbuffer(void);
int tamanho;
int x = 1;
char letra;
tamanho = strlen(palavra);
for(int c = 0;c < 100;c++){
	posi[c] = -1;
}

	for(int tentativa = 0;tentativa < 6;tentativa++){
		while(x == 1){
			vciguais = 0;
    		ciguais = 0;					
			system("clear");			
			printar(tamanho,tentativa);
			limparbuffer();
			scanf("%c",&letra);
			if(analise(letra,tamanho) == 1){
				resultado++;
			}
			else{
				break;
			}
			resultado += vciguais;			
    		if(resultado == tamanho){
    			break;
    		}
		}
    	if(resultado == tamanho){
    		break;
    	}
	}
	system("clear");
	if(resultado == tamanho){
    	printf("Voce Ganhou!\n");
    }else{
    	printf("Voce Perdeu!\n");
    	printf("A palavra era:%s",palavra);
    }
 	limparbuffer();   
    getchar();
}
void limparbuffer(void){
	char b;
	while((b = getchar()) != '\n' && b != EOF);

}
void printar(int tamanho,int tentativa){
	int imp;
	switch(tentativa){
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
int analise(char letra,int tamanho){
	int averig = 0;
	for(int c = 0;c < tamanho;c++){
		if(palavra[c] == letra){
			posi[c] = c;
			averig = 1;
			ciguais++;
			if(ciguais >= 2){
				vciguais++;
			}			
		}	
	}

	if(averig == 1){
		return 1;
	}
	else{
		return 0;
	}

}