#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>

int main (void)
{
	
	int i;	
	system("CLS");
	printf("Quanto s digitos vai ter sua senha? \n"); 
	scanf("%i",&i);
	 	
	
		if( i > 0) 
		{ 
			char senha [i][i];
			
			
				
			for(int k = 0; k <= i; k++)
			{   system("CLS");
				printf("Digite sua senha \n");

				scanf("%s", &senha[k]);
			}
		}
		else 
		{
			printf("Thau!"); 
		}

	
	return(0);
}