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
void Consumir(int veredicto, char cadena[]);

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
	Consumir(1,cadena);	
}

//Funcion B
void FuncionB(char cadena[])
{
	//B->bCD
	if(cadena[indice]=='b')
    {
		//Se consume b
		Consumir(1,cadena);
		FuncionC(cadena);
		FuncionD(cadena);
	}
	//B->a
	else if (cadena[indice]=='a')
	{
		//Se consume a
		Consumir(1,cadena);
	}
	else
	{
		Consumir(0,cadena);
	}
}

//Funcion C
void FuncionC(char cadena[])
{
	//C->cA
	if(cadena[indice]=='c')
    {
		//Se consume c
		Consumir(1,cadena);
		FuncionA(cadena);
	}
	//C->f
	else if (cadena[indice]=='f')
	{
		//Se consume f
		Consumir(1,cadena);
	}
	else
	{
		Consumir(0,cadena);
	}
}

//Funcion D
void FuncionD(char cadena[])
{
	//D->d
	Consumir(1,cadena);
}

//Funcion E
void FuncionE(char cadena[])
{
	//E->e
	Consumir(1,cadena);
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
