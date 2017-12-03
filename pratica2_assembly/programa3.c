/* 
Algorítmo feito para prática 2 da matéria Microprocessadores - 2017/2
Aluno: Leonardo Rezende Costa
Professor: Maxwell Diógenes Bandeira de Melo
*/
#include<stdio.h>
void bubble_cresc(int a[], int tam){
    int flag = 0;
    int i,j;
    while(1){
        flag = 0;
        for(i = 0; i < tam-1; i++){
            if(a[i] > a[i+1]){
                flag = 1;
                a[i] += a[i + 1];
                a[i + 1] = a[i] - a[i + 1];
                a[i] -= a[i + 1];
            }
        }
        if(!flag)
            break;
        for(i=0;i<tam;i++){
            printf("a[%d]: %d\t", i, a[i]);
        }
        printf("\n");
    }
}

void bubble_decr(int a[], int tam){
    int flag = 0;
    int i,j;
    while(1){
        flag = 0;
        for(i = 0; i < tam-1; i++){
            if(a[i] < a[i+1]){
                flag = 1;
                a[i] += a[i + 1];
                a[i + 1] = a[i] - a[i + 1];
                a[i] -= a[i + 1];
            }
        }
        if(!flag)
            break;
        for(i=0;i<tam;i++){
            printf("a[%d]: %d\t", i, a[i]);
        }
        printf("\n");
    }
    
}

int main(){
    int a[10] = {9,8,7,6,5,4,3,2,1,0};
    bubble_cresc(a,10);
    int i;
    for (i = 0; i < 10; i++)
    {
        printf("a[%d]: %d\t", i, a[i]);
    }
    printf("\n\n\n\n");

    bubble_decr(a, 10);
    for (i = 0; i < 10; i++)
    {
        printf("a[%d]: %d\t", i, a[i]);
    }
    printf("\n");
    return 0;
}