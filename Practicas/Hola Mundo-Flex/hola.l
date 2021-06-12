%{
	#include<stdio.h>
	
%}

%%

hola	{printf("¡Hola Mundo!\n");}
adios	{printf("bye\n");}
gato	{printf("cat\n");}
perro	{printf("dog\n");}

[0-9]+			{printf("Número\n");}
int|char|float|void	{printf("Palabra reservada\n");}
[a-zA-Z][a-zA-Z0-9]*	{printf("Identificador\n");}
[+-]			{printf("Operador\n");}
[;]			{printf("Separador\n");}

