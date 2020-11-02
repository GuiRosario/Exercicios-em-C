#include <stdio.h>

int main()
{
	int n1;
	int n2;
	int n3;

	scanf("%i %i %i", &n1, &n2, &n3);

	if(n1 >= n2 & n1 >= n3){

		if(n2>n3){

			printf("%i\n%i\n%i\n",n3,n2,n1);

		}else{

			printf("%i\n%i\n%i\n",n2,n3,n1);
		}

	}else if(n2 >= n1 & n2 >= n3){

		if(n1>n3){

			printf("%i\n%i\n%i\n",n3,n1,n2);

		}else{

			printf("%i\n%i\n%i\n",n1,n3,n2);
		}

	}else if(n3 >= n2 & n3 >= n1){

		if(n1>n2){

			printf("%i\n%i\n%i\n",n2,n1,n3);

		}else{

			printf("%i\n%i\n%i\n",n1,n2,n3);
		}

	}

	printf("\n%i\n%i\n%i\n",n1,n2,n3);




	return 0;
}