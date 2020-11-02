#include <stdio.h>

int main(void){

	void teste(void);

	teste();

	teste();

	teste();



	return 0;
}

void teste(void){

	int variavel = 2;
	variavel *= 3;

	printf("%i\n",variavel);

}