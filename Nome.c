#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h> 





 

void main (void)
{
	
	/* Desafio:
			Em um cadastro de autoescola, constam o nome e a idade de 10 alunos, 
			criar um programa que ordene pela idade e ao final apresente a idade 
			e os respectivos nomes. 
	*/ 
	
//******************* declarando meus construtores 

	int qntAulunos = 10;
	char nomes[qntAulunos][50];
	int idades[qntAulunos][50];
	int i; //loop
	
//****************** Inicio da funcao
	
	for (i = 0; i<qntAulunos;i++)
	{
		printf("\n Digite o nome do aluno: \n");
		scanf("%s",&nomes[i]); 
		printf("\n Digite a idade do aluno: \n");
		scanf("%d",&idades[i]); 
		
	}
	
	
	
	

}




int ordenar_selecao_nome() 
{
    int i,j,indmin;
    string min, aux;
    for(i=0; i< (tam-1); i++) {
        strcpy(min,vetor[i]);
        indmin = i;
        for(j=i+1; j<tam; j++) {
            if(strcmp(vetor[j],min)<0)
                strcpy(min,vetor[j]);
                indmin = j;
        }
        if(strcmp(vetor[i], min)>0) {
            strcpy(aux, vetor[i]);
            strcpy(vetor[i], vetor[indmin]);
            strcpy(vetor[indmin], aux);
        }
    }
	return(0);
}
