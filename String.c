#include <stdio.h>
#include <stdlib.h>


char[] entrada(){
    char c;
    int cont=0;
    char ent[100];
    c=getchar();
    if(c!='\n') {
        ent[cont]=c;
        cont++;
        c=getchar();
        while (c != '\n') {
            ent[cont]=c;
            cont++;
            c=getchar();
        }
    }
    return ent;
}


int main(){
	char nome1[100] ;
	char nome2[100] ;
	char Letra;
	int nome1num1;
	int nome1num2;
	int nome2num1;
	int nome2num2;
	int ordalfab[27] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27};
	char alfabM[28] = "ABCDEFGHIJKLMNOQPQRSTUVWXYZ ";
	char alfabm[28]	= "abcdefghijklmnopqrstuvwxyz ";

	scanf(" %s",nome1);
	scanf(" %s",nome2);
	nome1 = entrada();
	nome2 = entrada();

	for(int i = 0;i < 100;i++){
		for(int x = 0;x < 26;x++){
			if(nome1[i] == alfabM[x] || nome1[i] == alfabm[x]){
				nome1num1 = x;
				break;

			}
		}
		for(int c = 0;c < 26;c++){
			if(ordalfab[c] == nome1num1){
				nome1num2 = c; 
			   	break;	
			}
		}
		for(int x = 0;x < 26;x++){
			if(nome2[i] == alfabM[x] || nome2[i] == alfabm[x]){
				nome2num1 = x;
				break;

			}
		}
		for(int c = 0;c < 26;c++){
			if(ordalfab[c] == nome2num1){
				nome2num2 = c; 
			   	break;	
			}
		}

		if(nome1num2 == nome2num2){
			continue;
		}

		else if(nome1num2 < nome2num2){
			printf("%s\n",nome1);
			printf("%s\n",nome2);
			break;
		}
		else if(nome2num2 < nome1num2){
			printf("%s\n",nome2);
			printf("%s\n",nome1);
			break;
		}	



	}



return 0;
}
 