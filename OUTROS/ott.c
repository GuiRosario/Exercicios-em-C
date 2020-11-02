#include <stdio.h>

int main(){
	int NumT;
	int Possibili;
	scanf("%i",&NumT);
	char Palavra[NumT][6];

	for(int L = 0;L<NumT;L++){
		scanf("%s",Palavra[L]);
	}

	for(Possibili = 0;Possibili < NumT;Possibili++){
		if((Palavra[Possibili][1] == 'n' && Palavra[Possibili][2] == 'e' ) || (Palavra[Possibili][0] == 'o' && Palavra[Possibili][2] == 'e' ) || (Palavra[Possibili][0] == 'o' && Palavra[Possibili][1] == 'n' )){
			printf("1\n");

		}
		if((Palavra[Possibili][1] == 'w' && Palavra[Possibili][2] == 'o' ) || (Palavra[Possibili][0] == 't' && Palavra[Possibili][2] == 'o' ) || (Palavra[Possibili][0] == 't' && Palavra[Possibili][1] == 'w' )){
			printf("2\n");
		}
		if((Palavra[Possibili][1] == 'h' && Palavra[Possibili][2] == 'r' && Palavra[Possibili][3] == 'e' && Palavra[Possibili][4] == 'e') || (Palavra[Possibili][0] == 't' && Palavra[Possibili][2] == 'r' && Palavra[Possibili][3] == 'e' && Palavra[Possibili][4] == 'e') || (Palavra[Possibili][0] == 't' && Palavra[Possibili][1] == 'h' && Palavra[Possibili][3] == 'e' && Palavra[Possibili][4] == 'e') || (Palavra[Possibili][0] == 't' && Palavra[Possibili][1] == 'h' && Palavra[Possibili][2] == 'r' && Palavra[Possibili][4] == 'e') || (Palavra[Possibili][0] == 't' && Palavra[Possibili][1] == 'h' && Palavra[Possibili][2] == 'r' && Palavra[Possibili][3] == 'e')){
			printf("3\n");
		}

	}
	return 0;
}