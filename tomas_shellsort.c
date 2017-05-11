#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 6

//definicao de tipo cadastro (struct)
typedef struct
{
    char nome[30];
    int idade;

}cadastro;

//prototipo das funcoes
void cadastrar();
void imprimir();
void ordenar();
int menu();

int main()
{
    cadastro cad[N];
    int op;
    do
    {
        op = menu();
        switch(op)
        {
            case 0:
                printf("\nAte mais");
                break;
            case 1:
                cadastrar(&cad);
                break;
            case 2:
                listar(&cad);
                break;
            case 3:
                ordenar(&cad);
                break;
            default:
                printf("Opcao invalida!");
                break;
        }
    }while (op!=0);

    return 0;
}
//menu
int menu()
{
    int op;

    printf("\n..::MENU::..\n");
    printf("\n0 - SAIR");
    printf("\n1 - Cadastrar");
    printf("\n2 - Listar");
    printf("\n3 - Ordenar\n");
    printf("\nDigite uma opcao: \n");
    scanf("%d", &op);

    return (op);
}
//cadastrar
void cadastrar(cadastro * c)
{
    int i;
    for (i=0; i<N; i++)
    {
        printf("\nNome: ");
        scanf("%s", &c[i].nome);
        printf("\nIdade: ");
        scanf("%d", &c[i].idade);
    }
    system("cls");

}

//listar
void listar(cadastro * c)
{
    int i;
    for(i=0; i<N; i++)
    {
        printf("\nNome: %s", c[i].nome);
        printf("\nIdade %d\n", c[i].idade);
    }
    getch();
    system("cls");
}


//ordenar - shellsort
void ordenar(cadastro * c)

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
    printf("\nOrdenado com sucesso!");
    getch();
    system("cls");
}



