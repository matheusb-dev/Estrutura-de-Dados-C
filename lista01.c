/*  Nome: Matheus Bezerra Domingos
    Data: 29/09/2024
    Obj: Revisão dos conteúdos
 */

//Importando biblioteca
#include <stdio.h>

//programa principal
void main(){

    //Declaração das variaveis
    int horas_extras;
    int horas_faltas;
    int horas;
    int premio;

    //Nome do programa
    printf("Programa que calcula as horas extras - horas faltadas \n");

    //Mandando o usuario digitar os valores
    printf("Digite o numero de horas extras: ");
    scanf("%d", &horas_extras);

    printf("Digite o numero de horas faltadas: ");
    scanf("%d", &horas_faltas);

    //Calculando
    horas = horas_extras - horas_faltas;

    //Verificando
    if(horas <= 10){
        premio = 20;
        printf("O premio e de: %d ", premio);
    }else if(horas > 10 && horas <=20){
        premio = 40;
        printf("O premio e de: %d", premio);
    }else if(horas > 20 && horas <= 30){
        premio = 60;
        printf("O premio e de: %d", premio);
    }else if(horas > 30 && horas <= 40){
        premio = 80;
        printf("O premio e de: %d", premio);
    }else{
        premio = 100;
        printf("O premio e de: %d", premio);
    }
}