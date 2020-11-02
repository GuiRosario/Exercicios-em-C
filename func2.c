#include <stdio.h>

int main() {
	float calcularAreaRetang(float x,float y);

	float area = calcularAreaRetang(10.0,20.0);

	printf("A area eh: %f",area);

	return 0;
}

float calcularAreaRetang(float base,float altura){

	float area = base * altura;

	return area;
}
