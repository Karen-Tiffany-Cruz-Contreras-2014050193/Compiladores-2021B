//Autor: Karen Tiffany Cruz Contreras
#include<stdio.h>
#include <stdlib.h>
#include <string.h>

/*
	S -> abSA
	S -> bA
	A -> aA
	A -> c
*/

void FuncionS(char cadena[]);
void FuncionA(char cadena[]);
void Consumir(char letra, char cadena[]);

int indice = 0;
char cadena[] = "ababbaacccc";

int main()
{
	printf("La cadena es %s \n",cadena);
	//Enviamos la cadena completa a la funcion S
	FuncionS(cadena);
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

//Funcion S
void FuncionS(char cadena[])
{
	//S -> abSA
	if(cadena[indice]=='a')
    {
		//Se consume a
		Consumir('a',cadena);
		//Se consume b, se manda a llamar a B y si no hay errores se llama a A
		Consumir('b',cadena);
		FuncionS(cadena);
		FuncionA(cadena);
	}
	//S -> bA
	else if (cadena[indice]=='b')
	{
		//Se consume b y se manda a llamar a A 
		Consumir('b',cadena);
		FuncionA(cadena);
	}
	else
	{
		Consumir(' ',cadena);
	}
}

//Funcion A
void FuncionA(char cadena[])
{
	//A -> aA
	if(cadena[indice]=='a')
	{
		//Se consume a y se manda llamar a A
		Consumir('a',cadena);
		FuncionA(cadena);		
	}
	else if (cadena[indice]=='c')
	{
		//A -> c
		Consumir('c',cadena);
	}
	else
	{
		Consumir(' ',cadena);
	}	
}

//Consumir
void Consumir(char letra, char cadena[])
{
	if(cadena[indice]==letra)
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
