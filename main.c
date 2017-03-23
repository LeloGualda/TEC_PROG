#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

int main(int argc, char *argv[])
{ 
    

    int i;
    boolean ou;
	char nome [5][5], pesq[5], resp;
	char acha;

  // Amarzenando nomes  
  
	for (i=0; i<=5; i++)
	{
		system ("CLS");
		
		printf ("\n Escreva um nome: \n");
		scanf ("%s", &nome[i]);
	
     }
//
  resp = 'S';
  
  while (resp == 'S')
  {
	printf ("digite o nome a ser pesquisado: \n ");
	scanf ("%s", &pesq);
	
	i=0;
	acha='F';
	while (i<5 && acha == 'F'){
		if (strcmp (pesq, nome[i])==0)
		acha='V';
		
		else
		i=i+1;
		}
	
	if (acha == 'V')
	printf("%s, foi localizado na linha %d \n", nome[i], i);
	else
	printf("%s, não foi localizado \n", pesq);
	
printf("deseja continuar responde S ou N?\n");
scanf("%c", &resp);
}

	system("PAUSE");

}
