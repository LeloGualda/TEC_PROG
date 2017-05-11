#include "stdio.h"
#define N 5
#include"string.h"
#include"stdlib.h"
#define false 0
#define true 1

 typedef struct{
    int numero;
    int poltrona;
    float distancia;
    char passageiro[30];
    char origem[30];
    char destino[30];
    char horario[10];
    char data[10];
  }pass;
  
void bubblesort(pass *p);
void imprimir(pass *p);
void buscabinaria(pass *p);
void ordenar_alfabetico(pass *p);
  
int main(void) {
  
  pass pessoa[N];
  
  int i;
  
  for (i=0;i<N;i++){
    
    pessoa[i].numero=i+1;
    printf ("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");
    printf ("\nBilhete de embraque numero %i \n", pessoa[i].numero);
    printf ("\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");
    
    printf ("\nData de embarque: ");
    scanf("%s",& pessoa[i].data);
    
    printf ("Lugar de origem: ");
    scanf("%s",& pessoa[i].origem);
    
    printf ("Numero da poltrona: ");
    scanf("%i",&pessoa[i].poltrona);
    
    printf ("Nome do passageiro: ");
    scanf("%s",& pessoa[i].passageiro);
    
    printf ("Lugar de destino: ");
    scanf("%s", &pessoa[i].destino);
    
    printf ("Horario de saida: ");
    scanf("%s", &pessoa[i].horario);
  
    printf ("Distancia do trageto em km");
    scanf("%f", &pessoa[i].distancia);
  }
  
  bubblesort (pessoa);
  imprimir(pessoa);
  buscabinaria(pessoa);
  
  return 0;
}

  void imprimir(pass *p){
    
    int i=0;
    
     for (i=0;i<N;i++){
       
    printf ("\nmilhete de embraque numero %i \n", p[i].numero);
    
    printf ("\n %s \n",p[i].data);
    printf ("\n %s \n",p[i].origem);
    printf ("\n %i \n",p[i].poltrona);
    printf ("\n %s \n",p[i].passageiro);
    printf ("\n %s \n",p[i].destino);
    printf ("\n %s \n",p[i].horario);
    printf ("\n %.2f\n",p[i].distancia);
  }
  }
  

void bubblesort (pass *p){
  
  pass aux;
  int i=0,j, K=(N-1);
  
   for (i=0;i<N;i++){
     
     for (j=0;j<K;j++){
       
      if (p[j].poltrona > p[j+1].poltrona){
      
        aux = p[j];
        p[j]=p[j+1];
        p[j+1]=aux;}
       }
   }
}

void buscabinaria(pass *p)
{
  
   ordenar_alfabetico(p);

  int i=0, cont=0;
  int pesquisado = 0;
  int inicial = 0, final = N;
  char busca[30];
  int encontrado = false;
  
  
  printf ("Digite o nome do passageiro");
  scanf("%s", &busca);

  while (inicial <= final && encontrado == false) {
    
      int meio = (inicial + final)/2;

          if (strcmp (p[meio].passageiro,busca)==0)
          {
            
 
    printf ("\n milhete de embraque numero %i \n", p[meio].numero);

    printf ("\n %s \n",p[meio].data);
    printf ("\n %s \n",p[meio].origem);
    printf ("\n %i \n",p[meio].poltrona);
    printf ("\n %s \n",p[meio].passageiro);
    printf ("\n %s \n",p[meio].destino);
    printf ("\n %s \n",p[meio].horario);
    printf ("\n %.2f\n",p[meio].distancia);
    
             encontrado = true;
          }
         
          if (strcmp (p[meio].passageiro,busca)>0)
            {
              final = meio - 1;
            }
              else
            { 
              inicial = meio + 1;
            }
            cont++;
  }

  if (encontrado == false)
  printf("\n numero pesquisado nao foi encontrado\n",);
  else 
  printf("\n foi encontrado\n");
  
}

void ordenar_alfabetico(pass *p){
    
  int i=0;
  int j=0;
  int t=0;
  pass aux;
  int k = N - 1 ;

  for(i = 0; i < N; i++)
  {
     for(j = 0; j < k; j++)
     {
       if (strcmp(p[j].passageiro, p[j+1].passageiro)>0)
        {
        aux = p[j];
        p[j]=p[j+1];
        p[j+1]=aux;
        }
      
     }
     k--;
  }
}
