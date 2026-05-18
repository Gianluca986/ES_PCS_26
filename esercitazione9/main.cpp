#include <iostream>
#include "containers.hpp"
#include "unidirected_graph.hpp"
#include "graph_visits.hpp"


int main() {

    unidirected_graph G;

    G.add_edge({1, 2});
    G.add_edge({1, 3});
    G.add_edge({1, 4});
    G.add_edge({1, 6});

    G.add_edge({2, 4});
    G.add_edge({2, 5});
    G.add_edge({2, 7});

    G.add_edge({3, 6});

    G.add_edge({4, 6});
    G.add_edge({4, 7});

    G.add_edge({5, 7});

    G.add_edge({6, 7});
    G.add_edge({6, 8});

    G.add_edge({7, 9});
    
    G.add_edge({8, 9});
    
    stack<Journey> s;
    auto dfsG = graph_visit(G, 1, s);
    std::cout << "DFS Tree" << std::endl;
    std::cout << dfsG;
    std::cout << "========================================\n";

    queue<Journey> q;
    auto bfsG = graph_visit(G, 1, q);
    std::cout << "BFS Tree" << std::endl;
    std::cout << bfsG;
    std::cout << "========================================\n";

    auto dfsG_recursive = recursive_dfs(G, 1);
    std::cout << "Recursive DFS Tree" << std::endl;
    std::cout << dfsG_recursive;
    std::cout << "========================================\n";


    auto dijkstraG = dijkstra(G, 1);
    std::cout << "Dijkstra Tree" << std::endl;
    std::cout << dijkstraG;
    std::cout << "========================================\n";
   
    return 0;
}



