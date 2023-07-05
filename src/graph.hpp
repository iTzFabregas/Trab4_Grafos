#ifndef __GRAPH_HPP__
#define __GRAPH_HPP__

#include <iostream>
#include <map>
#include <list>
#include <vector>
#include <stack>
#include <queue>
#include <limits>

using namespace std;

struct Edge {
    int dest;
    int cost;
};

struct AncDist {
    int ancestor;
    int dista;
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
     * @brief essa função implementa o algoritmo dikstra que calcula o
     * menor cmainho do vertice origem até os outros vértices do grafo
     * 
     * @param origem vértice inial para a busca pelo menor caminho
     * @return vector<AncDist> esse vector retorna, para cada vértice,
     * o custo mínimo para chegar até ele; e tambem é retornado o
     * seu vertice antecessor
     */
    vector<AncDist> dijkstra(int origem);

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