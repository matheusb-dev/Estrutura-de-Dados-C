/*  Nome: Matheus ezerra Domingos
    RA: 166479-20224
    Data: 20/10/2024
    Objetivo:  manipulação de listas, incluindo inserção, remoção, alteração e consulta de dados, além de persistência dessas informações em disco. 

*/

//Importando as Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

//Criando a minha estrutura de dados
typedef struct{

    int codigo; //codigo da pessoa
    char nome[50]; //nome da pessoa
    char endereco[50]; //endereço da pessoa
    char cargo[50]; //carga da pessoa
    char dt_admissao[11]; //data da admissão
    char telefone[15]; //numero da pessoa
    float salario;
}reg_funcionario; //registro de funcionario tem td isso

typedef struct TipoItem *TipoApontador; //definição do tipo apontador

typedef struct TipoItem{ //tipo item
    reg_funcionario conteudo; //ai só coloco conteudo.oque eu quero
    TipoApontador proximo;
}TipoItem;

typedef struct{ //tipo lista
    TipoApontador Primeiro;
    TipoApontador Ultimo;
}TipoLista;


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

    for (lin = 1; lin < 27; lin++)
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

        gotoxy(col, 24);
        printf("-");

        gotoxy(col, 26);
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

    gotoxy(01, 24);
    printf("+");
    gotoxy(79, 24);
    printf("+");

    gotoxy(01, 26);
    printf("+");
    gotoxy(79, 26);
    printf("+");

    gotoxy(02, 02);
    printf("UNICV");

    gotoxy(54, 02);
    printf("ESTRURA DE DADOS - RODNEY");

    gotoxy(51, 03);
    printf("LISTA SIMPLESMENTE ENCADEADA");

    gotoxy(02, 25);
    printf("MSG: ");

    gotoxy(7,02);
    printf(" - Matheus B.D");

    gotoxy(02,03);
    printf("Data: 20/10/2024");
}

//Mostra a tela Funcionario Descrição
void telaFuncionario(){


            gotoxy(22, 3);
            printf("| CADASTRO FUNCIONARIO |");

            gotoxy(8, 8);
            printf("1. CODIGO FUNCIONARIO...........: ");

            gotoxy(8, 10);
            printf("2. NOME FUNCIONARIO.............: ");

            gotoxy(8, 12);
            printf("3. ENDERECO FUNCIONARIO.........: ");

            gotoxy(8, 14);
            printf("4. TELEFONE FUNCIONARIO.........: ");

            gotoxy(8, 16);
            printf("5. CARGO FUNCIONARIO............: ");

            gotoxy(8, 18);
            printf("6. SALARIO FUNCIONARIO..........: ");

            gotoxy(8, 20);
            printf("7. DATA DE ADMISSAO.............: ");
}


//Função verificador do código já existente
int codigoExiste(TipoLista *L, int codigo){
    TipoApontador p = L->Primeiro;
    while(p !=NULL){
        if(p->conteudo.codigo == codigo){
            return 1; //código já existe
        }
        p = p->proximo;
    }
    return 0; //código não existe
}


//Mostrar a tela Cadastro funcionario
void cadastraFuncionario(TipoLista *L) {

    reg_funcionario reg_func;
    
    TipoApontador p;

    int resp;

    do {
        tela();
        telaFuncionario(); //Descrição da tabela funcionarios

        gotoxy(43, 8);
        scanf("%d", &reg_func.codigo);

        //Verificação o código já foi digitado
        while(codigoExiste(L, reg_func.codigo)){
            gotoxy(7,25);
            printf("Codigo ja existe!, Digite um novo codigo: ");
            gotoxy(43,8);
            printf("  ");
            gotoxy(43,8);
            scanf("%d", &reg_func.codigo);
        }

        gotoxy(7,25);
        printf("                                               ");

        gotoxy(43, 10);
        fflush(stdin);
        fgets(reg_func.nome, 50, stdin);

        gotoxy(43, 12);
        fflush(stdin);
        fgets(reg_func.endereco, 50, stdin);

        gotoxy(43, 14);
        fflush(stdin);
        fgets(reg_func.telefone, 15, stdin);

        gotoxy(43, 16);
        fflush(stdin);
        fgets(reg_func.cargo, 15, stdin);

        gotoxy(43, 18);
        scanf("%f", &reg_func.salario);

        gotoxy(43, 20);
        fflush(stdin);
        fgets(reg_func.dt_admissao, 15, stdin);

        gotoxy(07, 25);
        printf("Deseja Gravar os Dados (1.Sim / 2.Nao) ");
        scanf("%d", &resp);
        
        if (resp == 1) {
            p = (TipoApontador)malloc(sizeof(TipoItem));
            p->proximo = NULL;
            p->conteudo = reg_func;

            if (L->Primeiro == NULL) {
                L->Primeiro = p;
                L->Ultimo = p;
            } else {
                L->Ultimo->proximo = p;
                L->Ultimo = p;
            }

            gotoxy(07, 25);
            printf("Cadastrado com sucesso                      ");
            getch();
        }

        gotoxy(07, 25);
        printf("Cadastrar novo funcionario (1.Sim / 2.Nao) ");
        scanf("%d", &resp);
    } while (resp == 1);
}

//Listar Funcionario
void listar_funcionario(TipoLista *L){
    
    TipoApontador p;
    p = L -> Primeiro;
    while(p!= NULL){

        tela();
        telaFuncionario();
        gotoxy(43, 8);
        printf("%d", p->conteudo.codigo);
        gotoxy(43, 10);
        printf("%s", p -> conteudo.nome);
        gotoxy(43, 12);
        printf("%s", p-> conteudo.endereco);
        gotoxy(43, 14);
        printf("%s", p->conteudo.telefone);
        gotoxy(43, 16);
        printf("%s", p-> conteudo.cargo);
        gotoxy(43, 18);
        printf("%f", p->conteudo.salario); //codigo, nome, endereco, telefone, cargo, salario
        gotoxy(43, 20);
        printf("%s", p->conteudo.dt_admissao);

        gotoxy(07, 25);
        printf("Pressione qualquer tecla para continuar.... ");
        getch();
        p = p->proximo;
    }
}

//Programa Principal
void main(){

    system("color 2F");
    int opc;
    TipoLista L;
    L.Primeiro = NULL;
    L.Ultimo = NULL;
    
    do{
        tela();
    
        gotoxy(26, 3);
        printf("| TELA INICIAL |");

        gotoxy(18,7);
        printf("1. Cadastrar Funcionario no Final da Lista");

        gotoxy(18, 9);
        printf("2. Cadastrar Funcionario no Inicio da Lista");

        gotoxy(18, 11);
        printf("3. Cadastrar Funcionario em uma Posicao da Lista ");

        gotoxy(18, 13);
        printf("4. Remover Funcionario no Final da Lista");

        gotoxy(18, 15);
        printf("5. Remover Funcionario no Inicio da Lista ");

        gotoxy(18, 17);
        printf("6. Remover Funcionario em uma Posicao da Lista");

        gotoxy(18, 19);
        printf("7. Alteracao do Cadastro de Funcionario ");

        gotoxy(18, 21);
        printf("8. Consultar Funcionarios");

        gotoxy(18, 23);
        printf("9. Sair do Programa");

        gotoxy(6,25);
        printf("Digite sua opcao...: ");
        scanf("%d",&opc);
        switch (opc)
        {
        case 1:
            cadastraFuncionario(&L);
            break;
        
        case 2:
            listar_funcionario(&L);
        }
  } while (opc != 3);
}