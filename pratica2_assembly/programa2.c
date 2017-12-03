/* 
Algorítmo feito para prática 2 da matéria Microprocessadores - 2017/2
Aluno: Leonardo Rezende Costa
Professor: Maxwell Diógenes Bandeira de Melo
*/
#include<stdio.h>

int main(){

    int a,x;
    printf("digite o numero:\n");
    scanf("%d",&x);
    for(a=0;a<=x;a++){
        if(a*a == x)
            break;
    }
    printf("resultado: %d\n",a);
    return 0;
}