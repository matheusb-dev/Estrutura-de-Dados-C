#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

void main(){

    //Declarando as variaveis
    int sorteio[6];
    int palpite[6];

    int j;
    int flag;
    int i;
    int num;

    //Pedindo os numeros
    for(i = 0; i < 6; i++){
        printf("digite um valor para o %d. palpite: ", i);
        scanf("%d", &num);
        //system("cls");

        //Verificando se o palpite ja foi digitado

        flag = 1;

        for(j = 0; j < 6; j++){
            if(palpite[j]== num){
                printf("Este numero ja fo digitado\n");
                getch();
                flag = 0;
            }
        }

    if(num <1 || num > 60){
        printf("digite um valor entre 1 a 60\n");
        getch();
        flag = 0;
    }

    
    //aarmazena o palpite
    if(flag == 1){
        palpite[i] = num;
    }else{
        i--;
    }
}
    //reseta o buffer dos numeros latorios
    srand(time(NULL));

    //sorteio os numeros da megaSena
    for(i = 0; i < 6; i++){
        num = rand() % 60 + 1;
        flag = 1;

        for(j = 0; j < 6; j++){
            if(sorteio[j] == num){
                flag = 0;
            }
        }

        //armazena o palpipe
        if(flag == 1){
            sorteio[i] = num;
        }else{
            i--;
        }
    }

    //Mostra os numeros sorteados
    for(j = 0; j < 6; j++){
        printf("Sorteado: %d palpite: %d\n", sorteio[j],palpite[j]);
    }
}