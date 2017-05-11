e: ⁠⁠⁠/*Em uma pesquisa foram entrevistadas 10 pessoas entre homens e mulheres, que forneceram seus nomes e telefones.
Utilizando o sistema de ordenação, ordene os nomes por ordem alfabetica e crie uma pesquisa sequencial, que apresente
os nomes identicos ao fornecido pelo usuario e seus respectivos telefones. Ao final informar quantos foram identicos e
quantos foram diferentes.*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>


#define N 10
//definicao da estrutura cadastro
typedef struct
{
    char nome[10];
    int tel;
}cadastro;

//instancia cadastro
cadastro c[N];
cadastro c_aux;

//prototipo das funcoes
void cadastrar();
void pesquisar();
void ordenar();
void exibir();

int main()
{
    char pesquisa[10];

    //chamada de cadastro
    cadastrar();
    printf("\n..::Cadastros SEM ordenacao::..\n\n");
    exibir();
    getch();

    //chamada de ordenacao
    ordenar();
    printf("\n..::Cadastros COM ordenacao::..\n\n");
    exibir();
    getch();
    system("cls");

    //chamada de pesquisa
    printf("\n..::Pesquisa::..\n\n");
    printf("Nome: ");
    scanf("%s", &pesquisa);
    pesquisar(pesquisa);
    return 0;
}

//funcao cadastrar
void cadastrar()
{
    int i;
    for (i=0; i<N; i++)
    {
        printf("\nNome: ");
        scanf("%s", &c[i].nome);
        printf("\nTel.: ");
        scanf("%d", &c[i].tel);
    }
    system("cls");
}

//funcao pesquisar
void pesquisar(char pesq[10])
{
    int i, cont=0;
    system("cls");
    //nomes identicos
    printf("\n..::Nomes identicos ao fornecido::..");
    for (i=0; i<N; i++)
    {
        if (strcmp(pesq, c[i].nome)==0)
        {
            cont +=1 ;
            printf("\nNome: %s", c[i].nome);
            printf("\nTel.: %d\n", c[i].tel);
        }
    }
    printf("\nQtd: %d", cont);

    //nomes diferentes
    printf("\n\n..::Nomes diferentes::..");
    for (i=0; i<N; i++)
    {
        if (strcmp(pesq, c[i].nome)!=0)
        {
            printf("\nNome: %s", c[i].nome);
            printf("\nTel.: %d\n", c[i].tel);
        }
    }
    printf("\nQtd: %d\n", (N-cont));
}

//funcao ordenar alfabeticamente
void ordenar()
{
    int i, j;
    for (i=0; i<N; i++)
    {
        for (j=i+1; j<N; j++)
        {
            if((strcmp(c[i].nome,c[j].nome))>0)
            {
                c_aux = c[i];
                c[i] = c[j];
                c[j] = c_aux;
            }
        }
    }
    system("cls");
}

//funcao exibir
void exibir()
{
    int i;
    for (i=0; i<N; i++)
    {
        printf("\nNome: %s", c[i].nome);
        printf("\nTel: %d\n", c[i].tel);
    }
}