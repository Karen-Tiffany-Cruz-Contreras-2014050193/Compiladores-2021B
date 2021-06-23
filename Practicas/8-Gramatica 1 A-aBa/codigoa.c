//Autor: Karen Tiffany Cruz Contreras
#include<stdio.h>
#include <stdlib.h>
#include <string.h>

/*
	A->aBa
	B->bAb
	B->c
*/

void FuncionA(char cadena[]);
void FuncionB(char cadena[]);
void Consumir(int veredicto, char cadena[]);

int indice = 0;
char cadena[] = "acab";

int main()
{
	printf("La cadena es %s \n",cadena);
	//Enviamos la cadena completa a la funcion A
	FuncionA(cadena);
	if(indice==strlen(cadena))
	{
		printf("La cadena pertenece \n");
	}
	else
	{
		printf("La cadena no pertenece \n");
	}
	return 0;
}

//Funcion A
void FuncionA(char cadena[])
{
	//A->aBa
	if(cadena[indice]=='a')
    {
		//Se consume a
		Consumir(1,cadena);
		FuncionB(cadena);
		if(cadena[indice]=='a')
		{
			//Se consume a
			Consumir(1,cadena);
		}
		else
		{
			Consumir(0,cadena);
		}
	}
	else
	{
		Consumir(0,cadena);
	}
		
}

//Funcion B
void FuncionB(char cadena[])
{
	//B->bAb
	if(cadena[indice]=='b')
    {
		//Se consume b
		Consumir(1,cadena);
		FuncionA(cadena);
		if(cadena[indice]=='b')
		{
			//Se consume b
			Consumir(1,cadena);
		}
		else
		{
			Consumir(0,cadena);
		}
	}
	//B->c
	else if(cadena[indice]=='c')
    {
		//Se consume c
		Consumir(1,cadena);
	}
	else
	{
		Consumir(0,cadena);
	}	
}

//Consumir
void Consumir(int veredicto, char cadena[])
{
	if(veredicto==1)
	{
		printf("Se consume -> %c\n",cadena[indice]);
		indice++;
	}
	else
	{
		printf("La cadena no pertenece");
		exit(1);
	}
}
