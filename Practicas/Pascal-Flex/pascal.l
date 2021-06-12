%{
	#include<stdio.h>
	
%}

DIGIT	[0-9]
ID	[a-z][a-z0-9]*

%%

{DIGIT}+				{printf("Entero: %s (%d)\n",yytext,atoi(yytext));}
{DIGIT}+"."{DIGIT}*			{printf("Flotante: %s (%g)\n",yytext,atof(yytext));}
if|then|begin|end|procedure|function	{printf("Palabra reservada: %s\n",yytext);}
{ID}					{printf("Identificador: %s\n",yytext);}
"+"|"-"|"*"|"/"			{printf("Operador: %s\n",yytext);}
"{"[^{}\n]*"}"				/*COMENTARIOS*/
[\t\n]+				/*ESPACIOS EN BLANCO*/
.					{printf("Caracter no reconocido: %s\n",yytext);}

%%

int main (int argc, char **argv)
{
	++argv, --argc; /*Ignora el nombre del programa*/
	if(argc>0)
		yyin=fopen(argv[0],"r");
	else
		yyin=stdin;
	yylex();
}
