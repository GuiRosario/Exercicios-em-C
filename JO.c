#include <stdio.h>

int main(){
	int NLC;
	scanf("%i",&NLC);
	int M1[NLC][NLC];
	int M2[NLC][NLC];
	int soma  = 0;
	int R[NLC][NLC];
	for(int L = 0;L < NLC;L++){	
		for(int C = 0; C < NLC; C++){
			scanf("%i",&M1[L][C]);
		}

	}

	for(int L = 0;L < NLC;L++){	
		printf("|");
		for(int C = 0; C < NLC; C++){
			printf("%i",M1[L][C]);
		}
		printf("|\n");
	}

	for(int L = 0;L < NLC;L++){	
		for(int C = 0; C < NLC; C++){
			scanf("%i",&M2[L][C]);
		}

	}

	for(int L = 0;L < NLC;L++){	
		printf("|");
		for(int C = 0; C < NLC; C++){
			printf("%i",M2[L][C]);
		}
		printf("|\n");
	}

	for(int L = 0;L < NLC; L++ ){
		for(int LM2 = 0; LM2 < NLC; LM2++){
			printf("0 ");
			soma = 0;
			for(int C = 0; C < NLC;C++){
				soma = soma + (M1[L][C]*M2[C][LM2]);
				printf("+ (%i*%i) ", M1[L][C], M2[C][LM2]);
			
			}

			R[L][LM2] = soma;
			printf(" = %i => R[%i][%i]\n",soma, L,LM2);
		}
	}

	for(int L = 0;L < NLC;L++){	
		printf("|");
		for(int C = 0; C < NLC; C++){
			printf("%i",R[L][C]);
		}
		printf("|\n");
	}

return 0;
}
