/* 
Algorítmo feito para prática 2 da matéria Microprocessadores - 2017/2
Aluno: Leonardo Rezende Costa
Professor: Maxwell Diógenes Bandeira de Melo
*/
#include <stdio.h>

int resto_div(int a, int b)
{
    // int i=0;
    while(a > 0 ){
        a -= b;
        // i++;
    }
    printf("b: %d\n",b);
    printf("a: %d\n",a);
    if(a != 0)
        return b+a;
    return a;
}

int main()
{
    int i,a,r=1;
    scanf("%d",&a);
    for(i=2;i<a;i++){
        if ( resto_div(a,i) == 0 )
            r+=i;
    }
    if(r==a)
        printf("perfeito\n");
    else
        printf("não perfeito\n");

    return 0;
}