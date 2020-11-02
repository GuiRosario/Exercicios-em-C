#include <stdio.h>

void fibo(int cont, int max, long current, long ant){

	if(cont > max){
		return;
	}

	printf("%li\n", current + ant);
	cont ++;

	fibo(cont, max, current + ant, current);
	return;
}


int main(){
	int num;
	scanf("%i",&num);

	fibo(0, num, 1, 0);
     
	return 0;
	
}