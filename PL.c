#include <stdio.h>

int main(){

	int T;
	int L;
	int C;
	int M[5][5];

	scanf("%i",&T);

	int RES[T];

	for(int rodada = 0;rodada < T;rodada++){

		printf("\n");


		for(int L = 0; L < 5;L++ ){
			for(int C = 0; C < 5; C ++){
				scanf("%i",&M[L][C]);
			}
		}

		if(M[0][0] == 0){
			M[0][0] = 2;
			for(int repet = 0; repet < 5;repet++){
				for(L = 0;L < 5;L++){
					for(int C = 0; C < 5; C ++){
						if(M[L][C] == 2){
							if(M[L][C+1] == 0){
								M[L][C+1] = 2;
							}
							if(M[L][C-1] == 0){
								M[L][C-1] = 2;
							}
							if(M[L+1][C] == 0){
								M[L+1][C] = 2;
							}
							if(M[L-1][C] == 0){
								M[L-1][C] = 2;
							}
						}
					}
				}			
			}
		}

		if(M[4][4] == 2){
			RES[rodada] = 1; 
		}else{
			RES[rodada] = 0;
		}

	    
		printf("\n");
		for(int L = 0; L < 5;L++ ){
			for(int C = 0; C < 5; C ++){
				printf("%i ",M[L][C]);
			}
			printf("\n");
		}
		
	}

	for(int emprimir = 0;emprimir < T;emprimir++){
		if(RES[emprimir] == 1){
			printf("COPS\n");
		}else if(RES[emprimir] == 0){
			printf("ROBBERS\n");	
		}
	}

return 0;
}