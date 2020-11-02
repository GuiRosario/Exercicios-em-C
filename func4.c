#include <stdio.h>

int main(void){

	void teste(void);

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

	printf("%i\n",variavele);
	printf("%i\n",variavela);
}