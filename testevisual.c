#include <stdio.h> 
#include <stdlib.h> 

#define t 7

int main()
{
	int aux,i,j,h=t,vetor[t];
		
	for(i=0;i<t;i++)
	{		printf(" numero \t %d \n",i+1);
			scanf("%d",&vetor[i]);	
	}
	do
	{
		h = h/2;
		for(i=h;i<t;i++)
		{
			j=i;
			aux = vetor[i];
			while((j>=h) && (vetor[j-h] >aux))
			{	
				vetor[j] = vetor[j-h];
				j=j-h;
			}
			vetor[j]=aux;
		}
		
	} while(h>1);
	
	for(i=0;i<t;i++)printf("%d \n",vetor[i]);
    return(0);
}