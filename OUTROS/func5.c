#include <stdio.h>
int gVariavelGLobal = 2;
int main(void){

	void teste(void);
	printf("%i\n",gVariavelGLobal);

	teste();

	teste();

	teste();



	return 0;
}

void teste(void){

	static int variavele = 2;
	int variavela = 2;

	variavele *= 3;
	variavela *=3;
	gVariavelGLobal *=2;

	printf("%i\n",variavele);
	printf("%i\n",variavela);
	printf("%i\n",gVariavelGLobal);
}