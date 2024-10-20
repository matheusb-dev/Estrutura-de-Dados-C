/*  Nome: Matheus ezerra Domingos
    RA: 166479-20224
    Data: 20/10/2024
    Objetivo:  manipulação de listas, incluindo 
inserção, remoção, alteração e consulta de dados, além de persistência dessas 
informações em disco. 

*/

//Importando as Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>


//Definindo Posicao do Cursor
void gotoxy(int x, int y){
    COORD coord;
    coord.X = (short)x;
    coord.Y = (short)y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//Funcão construção da tela Padrão
void tela(){

    int lin;
    int col;

    system("cls"); //limpar a tela
    system("cls"); //limpa a tela

    for (lin = 1; lin < 25; lin++)
    {
        gotoxy(01, lin);
        printf("|");
        gotoxy(79, lin);
        printf("|");
    }

    for(col = 1; col < 80; col++){

        gotoxy(col, 01);
        printf("-");

        gotoxy(col, 04);
        printf("-");

        gotoxy(col, 22);
        printf("-");

        gotoxy(col, 24);
        printf("-");
    }

    gotoxy(01, 01);
    printf("+");
    gotoxy(79, 01);
    printf("+");

    gotoxy(01, 04);
    printf("+");
    gotoxy(79, 04);
    printf("+");

    gotoxy(01, 22);
    printf("+");
    gotoxy(79, 22);
    printf("+");

    gotoxy(01, 24);
    printf("+");
    gotoxy(79, 24);
    printf("+");

    gotoxy(02, 02);
    printf("UNICV");

    gotoxy(54, 02);
    printf("ESTRURA DE DADOS - RODNEY");

    gotoxy(51, 03);
    printf("LISTA SIMPLESMENTE ENCADEADA");

    gotoxy(02, 23);
    printf("MSG: ");

    gotoxy(7,02);
    printf(" - Matheus B.D");

    gotoxy(02,03);
    printf("Data: 20/10/2024");
}

//Programa Principal
void main(){

    tela();
    gotoxy(25,20);

}


