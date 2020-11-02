#include <stdio.h>

int main(){
	int N = 1;
	int M;
	int NT = 0;
	int contq;
	int somador = 0;
	int Res[100];
	int printador;
	while(N != 0){
		scanf("%i",&N);

		for(contq = 0;contq < N;contq++){
			somador = (contq+1) * (contq+1) + somador;
		}

		Res[NT] = somador;
		somador = 0;
		NT += 1;
	}

	for(printador = 0;printador < NT;printador++){
		if(Res[printador] != 0){
			printf("%i\n",Res[printador]);			
		}else{
			break;
		}

	}

	return 0;
}