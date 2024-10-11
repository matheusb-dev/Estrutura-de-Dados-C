//Importanto as bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <windows.h>

//Definindo a estrutura de dados
typedef struct{

    int codigo; //codigo da pessoa
    char nome[50]; //nome da pessoa
    char endereco[50]; //endereço da pessoa
    char cargo[50]; //carga da pessoa
    char dt_admissao[11]; //data da admissão
    char telefone[15]; //umero da pessoa
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


//Definindo a posição do cursor
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

    gotoxy(63, 02);
    printf("ESTRURA DE DADOS");

    gotoxy(69, 03);
    printf("Matheus B.");

    gotoxy(02, 23);
    printf("MSG: ");

    gotoxy(02,03);
    printf("Lista Simplesmete Encadeada");
}

//Mostra a tela Funcionario
void telaFuncionario(){
    
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


//Mostrar a tela Cadastro funcionario
void cadastraFuncionario(TipoLista *L){

    reg_funcionario reg_func;

    TipoApontador p;

    int resp;

    do{

        tela(); //chama o desenho da tela
        telaFuncionario(); //chama a tela funcionario descrição

        gotoxy(30, 03);
        printf("CADASTRAR FUNCIONARIO");

        gotoxy(27, 07);
        printf("                   ");

        gotoxy(27, 07);
        scanf("%d", &reg_func.codigo); //revisar dps

        gotoxy(27, 9);
        fflush(stdin); //pesquisar dps
        fgets(reg_func.nome,50,stdin);

        gotoxy(27, 11);
        fflush(stdin);
        fgets(reg_func.cargo, 50, stdin);

        gotoxy(27, 15);
        fflush(stdin);
        fgets(reg_func.dt_admissao,11,stdin);

        gotoxy(27, 17);
        fflush(stdin);
        fgets(reg_func.telefone,15,stdin);

        gotoxy(27, 19);
        scanf("%f", &reg_func.salario);

        gotoxy(07,23);
        printf("Deseja Gravar os Dados (1.Sim / 2.Nao)" );
        scanf("%d", &resp);
        if(resp == 1){
            p = (TipoApontador)malloc(sizeof(TipoItem));
            p->proximo = NULL;

            p->conteudo = reg_func;
            if(L->Primeiro == NULL){
                L->Primeiro = p;
                L->Ultimo = p;
            }else{
                L->Ultimo->proximo = p;
                L->Ultimo = p;
            }
            
            gotoxy(07,23);
            printf("                                    ");
            gotoxy(07,23);
            printf("Cadastrado com sucesso");

            getch();
        }

        gotoxy(07,23);
        printf("Cadastrar novo funcionario (1.Sim / 2.Nao)");
        scanf("%d", &resp);
    }while(resp==1);

}


//Listar os funcionarios
void listar_funcionario(TipoLista *L){
    
    TipoApontador p;
    p = L -> Primeiro;
    while(p!= NULL){

        tela();
        telaFuncionario();
        gotoxy(27, 07);
        printf("%d", p->conteudo.codigo);
        gotoxy(27, 9);
        printf("%s", p -> conteudo.nome);
        gotoxy(27, 11);
        printf("%s", p-> conteudo.endereco);
        gotoxy(27, 13);
        printf("%s", p-> conteudo.cargo);
        gotoxy(27, 15);
        printf("%s", p->conteudo.dt_admissao);
        gotoxy(27, 17);
        printf("%s", p->conteudo.telefone);
        gotoxy(27, 19);
        printf("%f", p->conteudo.salario);

        gotoxy(07, 23);
        printf("Pressione qualquer tecla para continuar.... ");
        getch();
    }
}

//Programa Principals, 
void main(){

   system("color 1F");
   int opc;
   TipoLista L;
   L.Primeiro = NULL;
   L.Ultimo = NULL;

  do
  {
        tela();
        gotoxy(30, 03);
        printf("Folha de pagamento");
        gotoxy(10,10);
        printf("1. Cadastrar funcionario");
        gotoxy(10, 12);
        printf("2. Listar funcionario");
        gotoxy(10, 14);
        printf("3. sair");
        gotoxy(07, 23);
        printf("Digite sua opcao: ");
        scanf("%d", &opc);
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