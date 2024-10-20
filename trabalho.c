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


//Programa Principal
void main(){

    gotoxy(20,5);
    printf("Hello World");

}


