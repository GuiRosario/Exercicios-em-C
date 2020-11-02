#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 #include<stdio_ext.h>

void main(void){
	char *c;
	int m = -1;
	c = (char *) malloc(1*sizeof(char));
	do{
	m++;
	c = (char *)realloc (c,(m+1)*sizeof(char));
	c[m] = getchar();
	}while(c[m] != 10);
	char f[m];
	for(int i = 0;i < m;i++){
		f[i] = c[i];
	}
	printf("%sa",f);
}