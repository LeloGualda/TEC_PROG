#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <ctype.h>
//#include <conio.h>




typedef struct  conta 
{
		int cod;
		char nome[32];
		float saldo;
		float limite;
		struct conta * proximo;
}conta;

conta * cabecalho = NULL;
//prototipo
void Criar();
int menu();
void Imprimir(conta *);
void Listar();

int id = 0;
int main()
{
	int opcao;
conta *contAtual;


	do { 	opcao = menu();
	system ("CLS");
			switch (opcao) 
			{
				case 0:
						return(0);				
					break;
				
				case 1:
						Criar();
					break;
				case 2:
						Listar();
					break;
			}
		}while(opcao !=0);
			
}

int menu() 
{
	int opc = 0; 
	printf("\n *------------- \t Digite a operacao que deseja realizar \t -------------* \n");			
	printf("\n\n\t 1 \t Criar");
	printf("\n\t 2 \t Consultar");
	scanf("\n %d",&opc);
	return opc;
}
void Criar()
{
//-----* Aloca um espaço na memoria do tamanho de uma conta *-//
//-----* volta o ponteiro e fazemos a conversao deste espaço em ponteiro de conta (cast). *-//
	
	
	conta * novo	= 		(conta *) malloc(sizeof(conta));
	novo->cod 		= 		id++;
	novo->saldo 	=		0;
	novo->limite	=		1;
	
	char stringNome[32];	
	
		printf("Digite o nome");
		scanf("%s",&stringNome);
		
	strcpy(novo->nome,stringNome);
	
	novo->proximo 	=	NULL;
	
	if(cabecalho == NULL)
	{
		cabecalho = novo;
	}
	else
	{
		conta * atual = cabecalho;
		
		while (atual->proximo != NULL) 
		{
			atual = atual->proximo;
		}
		atual->proximo = novo;
	}
}

void Imprimir(conta * c) 
{
	printf("\n %s",c->nome);
}

void Listar()
{
		conta * atual = cabecalho;
		while(atual != NULL)
		{
			Imprimir(atual);
			atual = atual->proximo;
		}
}