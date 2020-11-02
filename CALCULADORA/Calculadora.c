#include <stdio.h>
#include <stdlib.h>
#include <string.h>
float nfloat;
int tamanho = 0;
float floatres;
char linha1[20];
char linha2[20];
int m;
int x = 0;
int v;

void main(void){
	void calc(char *n,char oper);
	void reproduzir(char *n,char oper);
	void limparbuffer(void);

	char oper = ' ';
	char *n;
	for(int i = 0;i<20;i++){
		linha1[i] = ' ';
	}		
	n = (char *) malloc(1*sizeof(char));
	while(oper != '='){
		limparbuffer();
		m = 0;
		reproduzir(n,oper);
		while((n[m] = getchar()) != '\n'){
		++m;	
		n = (char *)realloc (n,(m+1)*sizeof(char));
		}
		n[++m] = '\0';
		x = 1;
		calc(n,oper);
		reproduzir(n,oper);
		scanf(" %c",&oper);
	}
}
void limparbuffer(void){
	char b;
	while((b = getchar()) != '\n' && b != EOF);

}

void calc(char *n,char oper){
	int	intorfloat(char *n);

		nfloat = atof(n);

		if(oper == '+'){
			floatres += nfloat;
		}
		if(oper == '-'){
			floatres -= nfloat;
		}
		if(oper == '*'){
			floatres *= nfloat;
		}
		if(oper == '/'){
			floatres /= nfloat;
		}
		if(oper == ' '){
			floatres = nfloat;
        }

        if(floatres == (int)floatres){
        	v = 1;
        }else{
        	v = 0;
        }


 }
void flinha1(char *n,char oper){
	int c = 0;

	tamanho = strlen(n) - 1;
	if(oper == ' '){
		for(int i = 20-tamanho;i<20;i++){
			linha1[i] = n[c];
			c++;
		}
	}else{
			if(m == 0){
				for(int i = 1;i<20;i++){
					linha1[i - 1] = linha1[i]; 

				}
				linha1[19] = oper;
			}else{
			for(int i = tamanho;i<20;i++){
				linha1[i - tamanho] = linha1[i]; 
			}

			for(int i = 20 - tamanho;i < 20;i++){
				linha1[i] = n[c];
				c++;
			}
			}			
		}
	}

void flinha2(char *n,char oper){
int c=0;
	

	char nfloatstr[m-1];
	char nintstr[m-1];	
	int nint;

	for(int i = 0;i<20;i++){
		linha2[i] = ' ';
	}

	sprintf(nfloatstr,"%.2f",floatres);

	if(v == 0){
		int tamanho = strlen(nfloatstr);
		for(int i = 20-tamanho; i<20 ;i++){
			linha2[i] = nfloatstr[c];
			c++;
		}

	}else{
		nint = (int)floatres;
		sprintf(nintstr,"%i",nint);
		int tamanho = strlen(nintstr);
		for(int i = 20-tamanho;i<20;i++){
			linha2[i] = nintstr[c];
			c++;
		}

	}
}


void reproduzir(char *n,char oper){
	int intorfloat(char *n);

	void flinha1(char *n,char oper);
	void flinha2(char *n,char oper);

	if(oper == ' ' && x == 0){
		printf("		 ___________________________\n");
		printf("		|   ____________________    |\n");
		printf("		|  |                    |   |\n");
		printf("                |  |                    |   |\n");
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

	}else{
		printf("		 ___________________________\n");
		printf("		|   ____________________    |\n");
		printf("                |  |");
		flinha1(n,oper);
		flinha2(n,oper);
		printf("%s",linha1);
		printf("|   |\n");
		printf("                |  |");
		printf("%s",linha2);
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

}

}