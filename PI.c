#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(void){
	int *p;
	int m = 1;
	int e = 1;
	int i;
	int v;
	char c[10];
	p = (int *) malloc(m*sizeof(int));
	while(e == 1){
		scanf(" %s",c);
		v = strcmp("end",c);
		if(v == 0){
			break;
		}
		else{
			p[m - 1] = atoi(c);
		}
        m++;
        p = (int *) realloc(p,m*sizeof(int));
	}
	for(i = 0;i < m - 1;i++){
		printf("%i\n",p[i]);
	}

}
