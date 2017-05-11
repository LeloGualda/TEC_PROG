#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define N 5
#define X 12
#define Y 6

typedef struct
{
    char nome[X];
    char senha[Y];
    float saldo;
}cadastro;

//prototipo das funcoes
void ordenarInsert(cadastro * c);
int menuCliente();
int menuAdmin();
void cadastrar(cadastro * c);
void imprimir(cadastro * c);
void ordenar(cadastro * c);
cadastro * buscar(char nome_busca[X], cadastro * c);
void sacar(cadastro * c, char login[X]);
void depositar(cadastro * c, char login[X]);
void comprarAcao(cadastro * c, char login[X]);
void emprestimo(cadastro * c, char login[X]);
void consultaSaldo(cadastro * c, char login[X]);
void relatorioPorCliente(cadastro * c);
void relatorioPorSaldo(cadastro * c);
void consultaCliente(cadastro * c);
int validar(char login[X], char senha[Y], cadastro * c);

int main()
{
    system("cls");
    int validacao = 0, op, chance = 1;
    char login[X], senha[Y];
    cadastro cad[N];
    cadastro * aux = NULL;
    cadastrar(&cad);
    ordenarShell(&cad);
    do
    {
        printf("Login: ");
        scanf("%s", &login);
        printf("Senha: ");
        scanf("%s", &senha);
        validacao = validar(login, senha, &cad);
        if(validacao == 1 && strcmp(login, "saul") != 0)//cliente
        {
            do
            {
                printf("\nUsuario: %s", login);
                op = menuCliente();
                switch(op)
                {
                    case(0):
                        printf("\n\nAte mais %s!", login);
                        getch();
                        system("cls");
                        break;
                    case(1):
                        sacar(&cad, login);
                        getch();
                        system("cls");
                        break;
                    case(2):
                        depositar(&cad, login);
                        getch();
                        system("cls");
                        break;
                    case(3):
                        comprarAcao(&cad, login);
                        getch();
                        system("cls");
                        break;
                    case(4):
                        emprestimo(&cad, login);
                        getch();
                        system("cls");
                        break;
                    case(5):
                        consultaSaldo(&cad, login);
                        getch();
                        system("cls");
                        break;
                    default:
                        printf("\nOpcao invalida!");
                        break;
                }
            }while(op!=0);
        }
        else if (validacao == 1 && strcmp(login, "saul") == 0) //admin
        {
            do
            {
                printf("\nUsuario: %s", login);
                op = menuAdmin();
                switch(op)
                {
                    case(0):
                        printf("\n\nAte mais %s!", login);
                        getch();
                        system("cls");
                        break;
                    case(1):
                        relatorioPorCliente(&cad);
                        getch();
                        system("cls");
                        break;
                    case(2):
                        relatorioPorSaldo(&cad);
                        getch();
                        system("cls");
                        break;
                    case(3):
                        consultaCliente(&cad);
                        getch();
                        system("cls");
                        break;
                    default:
                        printf("\nOpcao invalida!");
                        break;
                }
            }while(op!=0);
        }
        else
        {
            printf("\n\nAcesso negado!");
            printf("\nTentativa %d", chance);
            getch();
            system("cls");
            chance +=1;
            if (chance>=4)
            {
                printf("Numero de tentativas esgotado! Procure nossa agencia para regularizar seu acesso!");
                getch();
                system("cls");
                system(0);
            }
        }
    }while(chance<4);
}

//funcao validacao
int validar(char login[X], char senha[Y], cadastro * c)
{
    int i;
    for (i=0; i<N; i++)
    {
        if(((strcmp(login, c[i].nome) == 0) && (strcmp(senha, c[i].senha)) == 0) || ((strcmp(login, "saul") == 0) && (strcmp(senha, "s000s") == 0)))
        {
            return(1);
        }

    }
    return(0);

}
//funcao menu cliente
int menuCliente()
{
    int op;
    printf("\n..::BANCO SURREAL::..\n\n");
    printf("\nModo Cliente\n\n");
    printf("0 - SAIR\n");
    printf("1 - Saque\n");
    printf("2 - Deposito\n");
    printf("3 - Compra de Acoes\n");
    printf("4 - Emprestimo Pessoal\n");
    printf("5 - Consulta de Saldo\n");
    printf("\nEscolha uma opcao: \n");
    scanf("%d", &op);
    return(op);
}

//funcao menu admin
int menuAdmin()
{
    int op;
    printf("\n..::BANCO SURREAL::..\n\n");
    printf("Modo Administrador\n\n");
    printf("0 - SAIR\n");
    printf("1 - Relatorio por Cliente\n");
    printf("2 - Relatorio por Saldo\n");
    printf("3 - Consulta por Cliente\n");
    printf("\nEscolha uma opcao: \n");
    scanf("%d", &op);
    return(op);
}

//funcao cadastrar
void cadastrar(cadastro * c)
{
    strcpy(c[0].nome, "xavier");
    strcpy(c[0].senha, "x111x");
    c[0].saldo = 5000.00;

    strcpy(c[1].nome, "silvia");
    strcpy(c[1].senha, "s222s");
    c[1].saldo = 2350.00;

    strcpy(c[2].nome, "celio");
    strcpy(c[2].senha, "c333c");
    c[2].saldo = 10200.00;

    strcpy(c[3].nome,"adao");
    strcpy(c[3].senha, "a444a");
    c[3].saldo = 7350.00;

    strcpy(c[4].nome, "ester");
    strcpy(c[4].senha, "e555e");
    c[4].saldo = -2500,00;
}

//funcao sacar
void sacar(cadastro * c, char login[X])
{
    float valorSaque;
    printf("\nValor de saque:");
    scanf("%f", &valorSaque);
    cadastro * aux = buscar(login, c);
    aux->saldo -= valorSaque;
    printf("\nSaque realizado com sucesso!");
    printf("\nNome: %s", aux->nome);
    printf("\nSaldo Atual: %0.2f", aux->saldo);
}

//funcao depositar
void depositar(cadastro * c, char login[X])
{
    float valorDeposito;
    printf("\nValor de deposito:");
    scanf("%f", &valorDeposito);
    cadastro * aux = buscar(login, c);
    aux->saldo += valorDeposito;
    printf("\nDeposito realizado com sucesso!");
    printf("\nNome: %s", aux->nome);
    printf("\nSaldo Atual: %0.2f", aux->saldo);
}

//funcao comprarAcao
void comprarAcao(cadastro * c, char login[X])
{
    float valorAcao;
    printf("\nValor da Acao:");
    scanf("%f", &valorAcao);
    cadastro * aux = buscar(login, c);
    aux->saldo -= valorAcao;
    printf("\nAcao comprada com sucesso!");
    printf("\nNome: %s", aux->nome);
    printf("\nSaldo Atual: %0.2f", aux->saldo);
}

//funcao emprestimo pessoal
void emprestimo(cadastro * c, char login[X])
{
    float valorEmprestimo;
    printf("\nValor de emprestimo:");
    scanf("%f", &valorEmprestimo);
    cadastro * aux = buscar(login, c);
    aux->saldo += (valorEmprestimo * 0.9);
    printf("\nEmprestimo realizado com sucesso!");
    printf("\nNome: %s", aux->nome);
    printf("\nSaldo Atual: %0.2f", aux->saldo);
}

//consulta de saldo
void consultaSaldo(cadastro * c, char login[X])
{
    cadastro * aux = buscar(login, c);
    printf("\nNome: %s", aux->nome);
    printf("\nSaldo: %0.2f", aux->saldo);
}

//funcao relatorio por cliente
void relatorioPorCliente(cadastro * c)
{
    ordenarShell(c);
    imprimir(c);
}

//funcao relatorio por saldo
relatorioPorSaldo(cadastro * c)
{
    ordenarInsert(c);
    imprimir(c);
}

//funcao consulta por cliente
void consultaCliente(cadastro * c)
{
    char nome_busca[X];
    printf("\nBusca por cliente: ");
    scanf("%s", &nome_busca);
    cadastro * aux = buscar(nome_busca, c);
    printf("\nNome: %s", aux->nome);
    printf("\nSaldo: %0.2f", aux->saldo);
}

//funcao imprimir
void imprimir(cadastro * c)
{
    int i;
    for (i=0; i<N; i++)
    {
        printf("\nNome: %s\n", c[i].nome);
        printf("Saldo: %0.2f\n", c[i].saldo);
    }
}

//funcao ordenar SHELLSORT
void ordenarShell(cadastro * c)
{
    int i , j, h = N;
    cadastro aux;
    do
    {
        h = h / 2;
        for (i = h; i < N; i++)
        {
            j = i;
            aux = c[i];
            while ((j >= h) && (strcmp(c[j-h].nome, aux.nome) > 0))
            {
                c[j] = c[j-h];
                j = j - h;
            }
            c[j] = aux;
        }

    }while (h > 1);
}

//funca ordenar INSERTSORT
void ordenarInsert(cadastro * c)
{
    int i, j;
    cadastro aux;
    for (j = 1; j < N; ++j)
    {
        aux = c[j];
        for (i = j-1; i >= 0 && c[i].saldo < aux.saldo; --i)
        {
            c[i+1] = c[i];
        }
        c[i+1] = aux;
    }
}

//funcao busca sequencial
cadastro * buscar(char nome_busca[X], cadastro * c)
{
    int i;
    for(i=0; i<N; i++)
    {
        if(strcmp(nome_busca, c[i].nome) == 0)
        {
            return &c[i];
        }
    }
    return (NULL);
}
