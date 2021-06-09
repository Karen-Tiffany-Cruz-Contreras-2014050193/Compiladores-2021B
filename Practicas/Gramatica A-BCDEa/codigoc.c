//Autor: Karen Tiffany Cruz Contreras
#include<stdio.h>
#include <stdlib.h>
#include <string.h>

/*
	A->BCDEa
	B->bCD
	B->a
	C->cA
	C->f
	D->d
	E->e
*/

void FuncionA(char cadena[]);
void FuncionB(char cadena[]);
void FuncionC(char cadena[]);
void FuncionD(char cadena[]);
void FuncionE(char cadena[]);
void Consumir(char letra, char cadena[]);

int indice = 0;
char cadena[] = "bcafdeadfdea";

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
	//A->BCDEa
	FuncionB(cadena);
	FuncionC(cadena);
	FuncionD(cadena);
	FuncionE(cadena);
	Consumir('a',cadena);	
}

//Funcion B
void FuncionB(char cadena[])
{
	//B->bCD
	if(cadena[indice]=='b')
    {
		//Se consume b
		Consumir('b',cadena);
		FuncionC(cadena);
		FuncionD(cadena);
	}
	//B->a
	else if (cadena[indice]=='a')
	{
		//Se consume a
		Consumir('a',cadena);
	}
	else
	{
		Consumir(' ',cadena);
	}
}

//Funcion C
void FuncionC(char cadena[])
{
	//C->cA
	if(cadena[indice]=='c')
    {
		//Se consume c
		Consumir('c',cadena);
		FuncionA(cadena);
	}
	//C->f
	else if (cadena[indice]=='f')
	{
		//Se consume f
		Consumir('f',cadena);
	}
	else
	{
		Consumir(' ',cadena);
	}
}

//Funcion D
void FuncionD(char cadena[])
{
	//D->d
	Consumir('d',cadena);
}

//Funcion E
void FuncionE(char cadena[])
{
	//E->e
	Consumir('e',cadena);
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
