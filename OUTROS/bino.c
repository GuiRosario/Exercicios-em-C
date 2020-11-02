#include <stdio.h>

int main(){
	int n;
	int x;
	int P[4];
	scanf("%i",&n);

	int M[n];
	for(x = 0;x < 4; x++){
		P[x]=0;
	}

	for(x = 0;x < n;x++){
		scanf("%i",&M[x]);

		if(M[x]%2 == 0){
			P[0] = P[0] + 1;
		}
		if(M[x]%3 == 0){
			P[1] = P[1] + 1;
		}
		if(M[x]%4 == 0){
			P[2] = P[2] + 1;
		}
		if(M[x]%5 == 0){
			P[3] = P[3] + 1;
		}

	}

	printf("%i Multiplo(s) de 2\n",P[0]);
	printf("%i Multiplo(s) de 3\n",P[1]);
	printf("%i Multiplo(s) de 4\n",P[2]);
	printf("%i Multiplo(s) de 5\n",P[3]);



	return 0;
}