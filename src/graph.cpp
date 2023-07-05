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

    // LE TODAS AS ARESTAS E OS PESOS
    int v1, v2, c;
    for (int i = 0; i < edges; i++) {
        cin >> v1 >> v2 >> c;
        graph.add_edge(v1, v2, c);
    }

    return graph;
}

void Graph::add_edge(int v1, int v2, int c) {
    Edge e;
    e.dest = v2;
    e.cost = c;
    graph_map[v1].push_back(e);
}

vector<AncDist> Graph::dijkstra(int origem) {

    AncDist initial;
    initial.ancestor = -1;
    initial.dista = numeric_limits<int>::max();

    vector<AncDist> ancestor_distances(num_vert, initial);

    ancestor_distances[origem].dista = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, origem));

    while (!pq.empty()) {
        int curr = pq.top().second;
        pq.pop();

        for (auto edge : graph_map[curr]) {
            int v = edge.dest;
            int c = edge.cost;

            if (ancestor_distances[curr].dista + c <= ancestor_distances[v].dista) {
                ancestor_distances[v].ancestor = curr;
                ancestor_distances[v].dista = ancestor_distances[curr].dista + c;
                pq.push(make_pair(ancestor_distances[v].dista, v));
            }
        }
    }
    return ancestor_distances;
}

void Graph::run() {

    // PEGA QUAL O VERTICE DO CLIENTE
    int client;
    cin >> client;

    vector<AncDist> ancestor_distances = dijkstra(0);

    // CALCULAR O VALOR PADRAO
    int standard_cost = 0;
    for (int i = 1; i < num_vert; i++) {
        standard_cost += ancestor_distances[i].dista - ancestor_distances[ancestor_distances[i].ancestor].dista;
    }

    // CALCULAR O VALOR VIP
    int vip_cost = ancestor_distances[client].dista;
    int curr = client;
    int cnt = 1;
    // VERIFICA QUANTOS VERTICES PARTICIPAM DA ENTRAGA VIP
    while (ancestor_distances[curr].ancestor != -1) {
        cnt++;
        curr = ancestor_distances[curr].ancestor;
    }
    vip_cost = vip_cost * (num_vert - cnt);

    // VER QUAL MENOR E PRINTAR
    if (standard_cost < vip_cost) {
        cout << "PADRAO" << "\n" << standard_cost;
    } else if (vip_cost < standard_cost) {
        cout << "VIP" << "\n" << vip_cost;
    } else {
        cout << "NDA" << "\n" << vip_cost;
    }
}