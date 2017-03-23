                        /*Integrantes:  Alypher Mansano     RA 16000
                Tomás Herculano     RA 15003706
                Aurélio Gualda      RA 16000183                                */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char nome[5][10], aux_nome[5][10];
    int idade[5], i, x=0, j, aux_idade;

    for (i=0; i<5; i++)
    {
        printf("\nDigite um nome: ");
        scanf("%s", &nome[i]);
        printf("\nDigite a idade do %s: ",nome[i]);
        scanf("%d", &idade[i]);
        system("cls");
        x += 1;

        if (x>1)
        {
            for(j=0; j<i; j++)
            {
                if(idade[i]<idade[j])
                {
                    aux_idade = idade[i];
                    idade[i] = idade[j];
                    idade[j] = aux_idade;

                    strcpy(aux_nome[i],nome[i]);
                    strcpy(nome[i],nome[j]);
                    strcpy(nome[j],aux_nome[i]);

                }
            }

        }

    }
    for (i=0; i<5; i++)
    {
        printf("\nNome: %s", nome[i]);
        printf("\nIdade: %d\n", idade[i]);

    }
    return 0;
}