#include <stdio.h>

int main(){
	int N;
	int x;
	int c;
	scanf("%i",&N);

	int V[N];


	for(int i = 0; i < N;i++){
		V[i] = i + 1;
		printf("%i",V[i]);

	}
	printf("\n");
	x = (N/2) + 1;
	for(int i = 0; i < x; i++){
		c = N - (i+1);
		V[i] = 0;
		V[c] = 0;
		for(int z = 0;z < N; z++){
			if(V[z] == 0){
				if(V[z] > 10){
					printf("  ");
				}else
					printf(" ");
			}else{
				printf("%i",V[z]);
			}

		}
		printf("\n");
	}

	return 0;
}