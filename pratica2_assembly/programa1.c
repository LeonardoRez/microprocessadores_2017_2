/* 
Algorítmo feito para prática 2 da matéria Microprocessadores - 2017/2
Aluno: Leonardo Rezende Costa
Professor: Maxwell Diógenes Bandeira de Melo
*/
#include<stdio.h>

int mult(int a,int b){
    int r =0;
    while(a--){
        r+=b;
    }
    return r;
}
int main(){
    int a, b;
    printf("digite a\n");
    scanf("%d", &a);
    printf("digite b\n");
    scanf("%d", &b);
    printf("resultado: %d\n", mult(a,b));
    return 0;
}