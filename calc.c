#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int resultado = 0;
int c = 19;
char reprodutor[20];
void main(void){
	/***********FUNÇÕES*************/
	void calc(char operacao[10],int num[10],int passador);
	void tela(char operacao[10],int num[10],int passador);
	/***********VARIAVEIS************/
	char operacao[10];
	int num[10];
	int passador;
	/***********OPERAÇÔES************/
	for(int i = 0;i < 36;i++){
		reprodutor[i] = ' ';
		operacao[i] = ' ';
	}
	for(passador = 0;passador<10;passador++){
		if(passador > 0 && operacao[passador - 1] == '='){
			break;
		}
		printf("\n");
		printf("digite um numero: ");
		scanf("%i",&num[passador]);
		system("clear");
		calc(operacao,num,passador);
		tela(operacao,num,passador);
		printf("digite a operacao: ");
		scanf(" %c",&operacao[passador]);
		system("clear");
		tela(operacao,num,passador);

	}


}
void calc(char operacao[10],int num[10],int passador){
	if(passador == 0){
		resultado = num[0];
	}else{
		if(operacao[passador-1] == '+'){
			resultado += num[passador];
		}
		if(operacao[passador-1] == '-'){
			resultado -= num[passador];
		}
		if(operacao[passador-1] == '/'){
			resultado /= num[passador];
		}
		if(operacao[passador-1] == '*'){
			resultado *= num[passador];
		}
		if(passador == 9){
			operacao[9] = '=';
		}
	}	

}
void tela(char operacao[10],int num[10],int passador){
	printf("		 ___________________________\n");
	printf("		|   ____________________    |\n");
	printf("		|  |");


	for(int i = 0;i < 36;i++){
		reprodutor[i - 2] = reprodutor[i];
	}

	if(operacao[passador] == ' '){
	reprodutor[c] = num[passador]+'0';	
	}else{
	reprodutor[c] = operacao[passador];
	reprodutor[c - 1] = num[passador]+'0';		
	}


	for(int i = 0;i < 20;i++){
		printf("%c",reprodutor[i]);
	}
	printf("|   |\n");
	printf("		|  |");
	if(resultado/10 == 0){
		printf("                   ");
	}
	else if(resultado/10 > 0 && resultado/10 < 10){
		printf("                  ");
	}
	else if(resultado/10 > 10 && resultado/10 < 100){
		printf("                 ");
	}
	else if(resultado/10 > 100 && resultado/10 < 1000){
		printf("                ");
	}
	else if(resultado/10 > 1000 && resultado/10 < 10000){
		printf("               ");
	}
	else if(resultado/10 > 10000 && resultado/10 < 100000){
		printf("              ");
	}
	else if(resultado/10 > 100000 && resultado/10 < 1000000){
		printf("             ");
	}
	else if(resultado/10 > 1000000 && resultado/10 < 10000000){
		printf("            ");
	}
	else if(resultado/10 > 10000000 && resultado/10 < 100000000){
		printf("           ");
	}
	else if(resultado/10 > 100000000 && resultado/10 < 1000000000){
		printf("          ");
	}
	else if(resultado/10 > 1000000000 && resultado/10 < 10000000000){
		printf("         ");
	}
	printf("%i",resultado);
	printf("|   |\n");
	printf("		|  |____________________|   |\n");
	printf("		|   ___   ___   ___   ___   |\n");
	printf("		|  |   | |   | |   | |   |  |\n");
	printf("		|  | 1 | | 2 | | 3 | | + |  |\n");
	printf("		|  |___| |___| |___| |___|  |\n");
	printf("		|   ___   ___   ___   ___   |\n");
	printf("		|  |   | |   | |   | |   |  |\n");
	printf("	        |  | 4 | | 5 | | 6 | | - |  |\n");
	printf(" 		|  |___| |___| |___| |___|  |\n");
	printf("		|   ___   ___   ___   ___   |\n");
	printf("  		|  |   | |   | |   | |   |  |\n");
	printf("		|  | 7 | | 8 | | 9 | | * |  |\n");
	printf("		|  |___| |___| |___| |___|  |\n");
	printf("                |   _________   ___   ___   |\n");
	printf("                |  |         | |   | |   |  |\n");
	printf("                |  |    =    | | 0 | | / |  |\n");
	printf("                |  |_________| |___| |___|  |\n");
	printf("		|___________________________|\n");
	if(operacao[passador] == ' '){
	reprodutor[c] = ' ';	
	}
}