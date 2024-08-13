#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <climits>

std::ifstream in;
std::ofstream out;

void PRIM(std::vector<std::vector<std::pair<int, int>>> &graph) {
    int nodes = static_cast<int>(graph.size());

    std::vector<int> dists(nodes, INT_MAX);
    std::vector<int> parent(nodes, -1);
    std::unordered_set<int> inMST;

    dists[0] = 0;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
    pq.push({0, 0});

    while (!pq.empty()) {
        int curr = pq.top().second;
        pq.pop();
        inMST.insert(curr);

        for (auto &neighs: graph[curr]) {
            int neigh = neighs.first;
            int dist = neighs.second;

            if (inMST.find(neigh) == inMST.end() && dist < dists[neigh]) {
                dists[neigh] = dist;
                parent[neigh] = curr;
                pq.push({dists[neigh], neigh});
            }
        }
    }

    int totalCost = 0;
    for (int i = 0; i < nodes; ++i) {
        if (parent[i] != -1) {
            totalCost += dists[i];
        }
    }

    out << totalCost << std::endl;

    int numEdges = nodes - 1;
    out << numEdges << std::endl;
    for (int i = 1; i < nodes; ++i) {
        out << parent[i] << " " << i << std::endl;
    }
}

int main() {


    in.open(R"(C:\Users\Ale\Desktop\test_2_grafuri\in.txt)");
    out.open(R"(C:\Users\Ale\Desktop\test_2_grafuri\out.txt)");


    int node1, node2, weight;
    int nodes, edges;
    in >> nodes >> edges;

    std::vector<std::vector<std::pair<int, int>>> graph(nodes);

    while (in >> node1 >> node2 >> weight) {
        graph[node1].emplace_back(std::make_pair(node2, weight));
        graph[node2].emplace_back(std::make_pair(node1, weight));
    }

    PRIM(graph);

    in.close();
    out.close();

    return 0;
}

/*
 *
 * Algoritmul incepe de la un nod dat(in cazul nostru de la nodul 0) si il adauga in coada cu prioritati, dupa se extrage
 * nodul curent din coada, se adauga in arborele minim si se compara distantele pentru vecinii acestuia. Daca se gaseste
 * un drum mai scurt la un vecin care nu se afla in arborele minim, se adauga in coada si se actualizeaza distanta si parintele.
 *
 *
 * Un exemplu din viata reala ar fi retele de transport public
 */