#include <stdio.h>

struct pessoa{
	char nome[50],rua[50];
	int idade, numero;

};

void main(){
	struct pessoa p;

	p.idade = 18;

	printf("%i",p.idade);



}