/* 
Algorítmo feito para prática 2 da matéria Microprocessadores - 2017/2
Aluno: Leonardo Rezende Costa
Professor: Maxwell Diógenes Bandeira de Melo
*/
#include <stdio.h>

int resto_div(int a, int b)
{
    while (a > 0)
    {
        a -= b;
    }
    if (a != 0)
        return b + a;
    return a;
}
int primo(int a){
    int i;
    if (a < 2)
        return 0;
    else
    {
        for (i = 2; i < a; i++)
        {
            if (resto_div(a, i) == 0)
                return 0;
        }
        return 1;
    }
}

int main()
{
    int a;
    scanf("%d", &a);
    if(primo(a))
        printf("primo!\n");
    else
        printf("não primo!\n");
    return 0;
}