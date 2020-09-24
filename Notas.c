#include <stdio.h>

int main(){
	int n, nota100, nota50, nota20, nota10, nota5, nota2, nota1; 
	nota100 = nota50 = nota20 = nota10 = nota5 = nota2 = nota1 = 0;


	scanf("%i",&n);

	printf("%i\n",n);

	if(n > 0 & n < 1000000){

		while(n >= 100){
			n = n - 100;
			nota100 = nota100 + 1; 

		}
		printf("%i nota(s) de R$ 100,00\n",nota100);
		while(n >= 50 & n < 100){
			n = n - 50;
			nota50 = nota50 + 1; 



		}
		printf("%i nota(s) de R$ 50,00\n",nota50);
		while(n >= 20 & n < 100 & n < 50){
			n = n - 20;
			nota20 = nota20 + 1; 


		}
		printf("%i nota(s) de R$ 20,00\n",nota20);
		while(n >= 10 & n < 100 & n < 50 & n < 20){
			n = n - 10;
			nota10 = nota10 + 1; 
		}
		printf("%i nota(s) de R$ 10,00\n",nota10);
		while(n >= 5 & n < 100 & n < 50 & n < 20 & n < 10){
			n = n - 5;
			nota5 = nota5 + 1; 

		}
		printf("%i nota(s) de R$ 5,00\n",nota5);
		while(n >= 2 & n < 100 & n < 50 & n < 20 & n < 10 & n < 5){
			n = n - 2;
			nota2 = nota2 + 1; 

		}
		printf("%i nota(s) de R$ 2,00\n",nota2);
		while(n >= 1 & n < 100 & n < 50 & n < 20 & n < 10 & n < 5 & n < 2){
			n = n - 1;
			nota1 = nota1 + 1; 

		}
		printf("%i nota(s) de R$ 1,00\n",nota1);

	}



	return 0;
}