"""Autor: Karen Tiffany Cruz Contreras """

#(ab)*|abc

#Se importa la libreria networkx como nx
import networkx as nx

#Se importa la libreria pyplot de matplotlib como plt
import matplotlib.pyplot as plt

def simbolo(G):
    #Se crean los nodos:
    #Nodo Venezuela
    G.add_node("1")

    #Se crean los nodos de los estados
    #G.add_nodes_from(["Carabobo","Miranda","Aragua","Merida","Lara","Distrito Capital"])

    #Se crean los nodos de las ciudades.
    G.add_node("2")

    #Se crean los enlaces de los estados
    G.add_edge("1","2")
    
    return G


def automata():
    #Se crea un grafo vacio
    G=nx.Graph()
    G=simbolo(G)

    #Se dibuja el grafo
    nx.draw(G)
    #Se muestra en pantalla
    plt.show()
    
    

if __name__ == "__main__":
    cadena="(ab)*|abc"
    automata()