#include<stdio.h>

int main() {

   int num1;
   int num2;
   int num3;

   printf("Informe os numeros: ");
   scanf("%i %i %i",&num1,&num2,&num3);

    if(num1<=num2 & num1<num3){
        printf("%i\n",num1);
        if(num2<=num3){
            printf("%i\n%i\n",num2,num3);
        }else{ printf("%i\n%i\n",num3,num2);
        }
    }
    else{ if(num2<=num1 & num2<num3){
        printf("%i\n",num2);
        if(num1<=num3){
            printf("%i\n%i\n",num1,num3);
        }else{ printf("%i\n%i\n",num3,num1);
        }
    }

    else if(num3<=num2 & num3<num1){
        printf("%i\n",num3);
        if(num2<=num1){
            printf("%i\n%i\n",num2,num1);
        }else{ printf("%i\n%i\n",num1,num2);
        }
    }


}
printf("\n%i\n%i\n%i",num1,num2,num3);

return 0;

}