#include "graph.hpp"

using namespace std;

Graph::Graph(int v) {
    this->num_vert = v;
}

Graph Graph::read_info() {

    int vertices, edges;
    cin >> vertices >> edges;

    // INICIALIZA O GRAFO
    Graph graph(vertices);

    // LE TODAS AS ARESTAS
    int v1, v2, c;
    for (int i = 0; i < edges; i++) {
        cin >> v1 >> v2 >> c;
        graph.add_edge(v1, v2, c);
    }
    graph.sort();

    return graph;
}

void Graph::add_edge(int v1, int v2, int c) {
    Edge e;
    e.dest = v2;
    e.cost = c;
    graph_map[v1].push_back(e);
}

void Graph::sort() {
    for (int i = 0; i < num_vert; i++) {
        graph_map[i].sort();    
    }
}

void Graph::run() {

    int client;
    cin >> client;

    // CALCULAR O VALOR PADRAO
    int standard_cost = 0;
    for (int i = 0; i < num_vert; i++) {
        // dijkstra
    }
    

    // CALCULAR O VALOR VIP
    int vip_cost = 0;

    // VER QUAL MENOR E PRINTAR
    if (standard_cost < vip_cost) {
        cout << "PADRAO" << "\n" << standard_cost;
    } else if (vip_cost < standard_cost) {
        cout << "VIP" << "\n" << vip_cost;
    } else {
        cout << "NDA" << "\n" << vip_cost;
    }
    
}