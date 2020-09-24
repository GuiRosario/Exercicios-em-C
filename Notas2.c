#include <stdio.h>
int main()
    {

    double n;
    int nf;
    int x;

    scanf("%lf", &n);

    nf = n;
    x = nf;
    n = n - x;
    n = n*100;
    x = n;
    
    printf("NOTAS:\n");
    printf("%d nota(s) de R$ 100.00\n", nf/100);
    nf %= 100;
    printf("%d nota(s) de R$ 50.00\n", nf/50);
    nf %= 50;
    printf("%d nota(s) de R$ 20.00\n", nf/20);
    nf %= 20;
    printf("%d nota(s) de R$ 10.00\n", nf/10);
    nf %= 10;
    printf("%d nota(s) de R$ 5.00\n", nf/5);
    nf %= 5;
    printf("%d nota(s) de R$ 2.00\n", nf/2);
    nf %= 2;
    printf("MOEDAS:\n");
    printf("%d moeda(s) de R$ 1.00\n",nf);
    printf("%d moeda(s) de R$ 0.50\n",x/50);
    x %= 50;
    printf("%d moeda(s) de R$ 0.25\n",x/25);
    x %= 25;
    printf("%d moeda(s) de R$ 0.10\n",x/10);
    x %= 10;
    printf("%d moeda(s) de R$ 0.05\n",x/5);
    x %= 5;
    printf("%d moeda(s) de R$ 0.01\n",x);


    return 0;

}