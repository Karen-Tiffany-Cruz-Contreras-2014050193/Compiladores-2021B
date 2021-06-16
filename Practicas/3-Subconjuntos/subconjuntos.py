"""Autor: Karen Tiffany Cruz Contreras """

"""Los estados del automata serán representados por cada lugar de la lista
Las trancisiones se econtrarán en los diccionarios"""
#               0                   1           2           3       4           5           6           7           8       9                       
automata=[{'e':['1','7']}, {'e':['2','4']}, {'a':'3'}, {'e':'6'},{'b':'5'},{'e':'6'},{'e':['1','7']},{'a':'8'},{'b':'9'},{'b':'10'},{}]
base=[]

# función para contar epsilon
def pisar(indice):
    #print(automata[indice].values())
    if automata[indice].get('e'):
        est=automata[indice].get('e')
        for n in est:
            base.append(n)
            #print("*",n)
            pisar(int(n))
    else:
        return 0
    return base


"""función para seleccionar de forma única los estados que se encontraron
y ordenar de menor a mayor"""
def seleccion(estados):
    resultado=[]
    for n in estados:
        if n not in resultado: 
            resultado.append(n)
    resultado.sort()
    print(resultado)  


if automata[0].get('e'):
    print("Resultado del algoritmo de los subconjuntos:")
    seleccion(pisar(0))
else:
    print("No hay epsilon que salgan del estado inicial")


