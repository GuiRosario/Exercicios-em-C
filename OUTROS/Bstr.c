#include <stdio.h>

int main(){

	char P[30];


	scanf(" %[^\n]s", P);

	setbuf(stdin, NULL);

	printf("%s",P);

	return 0;
}