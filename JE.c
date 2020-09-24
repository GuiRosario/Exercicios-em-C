#include <stdio.h>

int main(){
	int N;
	int i;
	int natc;
	int cnr;
	int x;
	cnr=0;
	natc = 0;

	scanf("%i",&N);

	int atq[N];
	int c[N];

	for( i = 0; i < N; i++ ){
		scanf("%i",&c[i]);

	}

	i = 0;
	while((i >= 0) & (i < N)){
		
		if(c[i] > 0){
			if(c[i]%2 > 0){
				i = i + 1;
				c[i]= c[i] - 1;
				atq[i] = 1;

			}else{
				i = i - 1; 
				c[i]= c[i] - 1;
				atq[i] = 1;

			}



		}else{

		i = i - 1;

		}
		
	}
	for(x = 0;x<8;x++){
		if(atq[x]==1){
		 natc= natc + 1;
		}else{
		 natc= natc + 0;
		}
		cnr= cnr + c[x];

	}

	printf("%i %i\n",natc,cnr);

	return 0;
}