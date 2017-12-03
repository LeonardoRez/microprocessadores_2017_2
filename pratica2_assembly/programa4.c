/* 
Algorítmo feito para prática 2 da matéria Microprocessadores - 2017/2
Aluno: Leonardo Rezende Costa
Professor: Maxwell Diógenes Bandeira de Melo
*/
#include <stdio.h>

int mult(int a, int b)
{
    int r = 0;
    while (a--)
    {
        r += b;
    }
    return r;
}
int fat(int a){     
    int t=1;
    int i = 1;
    for(;i <= a;i++){
        t = mult(i,t);
    }

    return t;
}
int main()
{
    int a=9;
    printf("fat de %d = %d\n",a,fat(a));
    
    return 0;
}