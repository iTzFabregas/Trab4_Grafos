#ifndef __GRAPH_HPP__
#define __GRAPH_HPP__

#include <iostream>
#include <map>
#include <list>
#include <vector>
#include <stack>

using namespace std;

struct Edge {
    int dest;
    int cost;
};

class Graph {

private:
    int num_vert;
    map<int, list< Edge >> graph_map;

    /**
     * @brief função para adicionar uma aresta
     * 
     * @param v1 um extremo da aresta
     * @param v2 o outro extremo da aresta
     */
    void add_edge(int v1, int v2, int c);

    /**
     * @brief função para ordenar todas as listas de adjacência dos vertices
     * 
     */
    void sort();

    int void dijkstra(int origem, int destino) {(int origem, int destino);

public:
    /**
     * @brief construtor da classe Graph
     * 
     * @param v numero de vertices
     */
    Graph(int v);

    /**
     * @brief função para pegar todos os inputs e criar o grafo
     * 
     * @return Graph grafo gerado
     */
    static Graph read_info();

    /**
     * @brief função que roda o programa pedido no trabalho 3
     * 
     */
    void run();
    
};

#endif