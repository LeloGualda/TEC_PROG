

//bibliotecas
#include "stdio.h"
#include "string.h"
#include "stdlib.h"

//global
#define _lugar 15
#define _poltrona 4
#define _nome 30
#define _Passageiros 5 
int qnt =0;
//estruturas

typedef struct 
{ char dia[1];
  char mes[1];
  char ano[3];  
}Data;

typedef struct 
{ char hora[1];
  char min[1];  
}Hora;

typedef struct Passageiro{
  int  id;
  char origem[_lugar];  
  Data data;
  char poltrona [_poltrona];
  char nome[_nome];
  char destino[_lugar];
  Hora hora;
  int  distancia;
  struct Passageiro * prox;
}Passageiro;

//prototipos

void 	Registrar	(Passageiro *);
void 	Imprimir	(Passageiro *);
int 	Menu();
char 	Pergunta	(char c[]);

char *	PerC		(char[]); 
int 	PerI		(char[]);



int main(){
	
	Passageiro * p = (Passageiro *)malloc(sizeof(Passageiro));
    p->id =0;
	
  int opcao;

  do{
      opcao = Menu();
      switch(opcao){
        case 1: Registrar(p); 
                break;
		case 2:break;
        case 0: opcao =0;
        
                break;
        default: printf("OPCAO INVALIDA. \n");
      }
    }while(opcao != 0);
}

int Menu(){
  int r;
    printf("\t 1 \t PARA REGISTRAR \n");
    printf("\t 2 \t PARA BUSCAR \n");
    printf("\t 0 \t PARA SAIR \n");
    scanf("%d",&r);
}

char * PerC(char c[]){
	char * r = (char *) malloc(sizeof(char) * 30);
	printf("%s \n",c);
	scanf("%s",r);
	return(r);
}
int PerI(char c[]){
	int r;
	printf("%s \n",c);
	scanf("%d",&r);
	return(r);
}
void Registrar(Passageiro * pas){
	 

	
	Passageiro * aux  = (Passageiro *)malloc(sizeof(Passageiro));
	aux->id = 0;

	if(pas->id == 0){
			qnt ++;
			pas->id = qnt;
			strcpy(pas->nome,PerC("Digite o nome do Passageiro"));
			pas->prox = aux;	
			Imprimir(pas);
			
		 }
	else{
		Passageiro * novo = (Passageiro *)malloc(sizeof(Passageiro));
		novo = pas->prox;
		Imprimir(pas);
		do{
			if(novo->id == 0){
				qnt ++;
				novo->id = qnt;
				strcpy(novo->nome,PerC("Digite o nome do Passageiro"));
				novo->prox = aux;	
				Imprimir(novo);
			}
			else
			{ 
				novo = novo->prox;
				Imprimir(novo);
			}
		}while(novo->id !=0);
		
	}
			
		 			// novo->id = 1;
			// novo->prox->id = 0;
			// strcpy(novo->nome,PerC("Digite o nome do Passageiro"));
			// pas = novo;
		 return;
	//	 Imprimir(novo);
	 
/* 
int  id;
  char origem[_lugar];  
  Data data;
  char poltrona [_poltrona];
  char passageiro[_nome];
  char destino[_lugar];
  Hora hora;
  int  distancia;
  struct Passageiro * prox;
  */
}
void Imprimir(Passageiro * pa){
	
	printf("\n --- \n");
	printf("%d \n", pa->id);
	printf("%s \n", pa->nome);
    printf("\n --- \n");

}