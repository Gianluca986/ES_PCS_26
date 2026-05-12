#include <iostream>
#include <vector>
#include <algorithm>
#include "unidirected_edge.hpp"
#include "unidirected_graph.hpp"


int main() {
    unidirected_graph G, H;
    
    /* GRAFO G          GRAFO H
      1                     5
    / | \                   |
   2  |  3                  1
    \ | /                 /   \
      4                  2     3
      |                   \   /
      5                     4 -- +
                            |    |
                            + -- +
    */

    /* Aggiungo gli archi ai grafi G e H*/
    G.add_edge({1,2}); 
    G.add_edge({1,3}); 
    G.add_edge({1,4}); 
    G.add_edge({2,4}); 
    G.add_edge({3,4}); 
    G.add_edge({4,5}); 
    G.add_edge({4,5}); 

    
    H.add_edge({1,2});
    H.add_edge({1,3});
    H.add_edge({1,5});
    H.add_edge({2,4});
    H.add_edge({3,4});
    H.add_edge({4,4});

    std::cout << "\n=============================================" << std::endl;
    std::cout << "TEST all_edges() & add_edge()" << std::endl;
    std::cout << "=============================================" << std::endl;

    std::vector<unidirected_edge> edges_G = G.all_edges();
    std::vector<unidirected_edge> edges_H = H.all_edges();
    
    std::cout << "\nExpected edges of graph G: \n";
    std::cout << "(1,2) (1,3) (1,4) (2,4) (3,4) (4,5)\n";
    std::cout << "Computed edges of graph G: \n";
    print_vector(edges_G);

    std::cout << "\nExpected edges of graph H: \n";
    std::cout << "(1,2) (1,3) (1,5) (2,4) (3,4) (4,4)\n";
    std::cout << "Computed edges of graph H: \n";
    print_vector(edges_H);


    std::cout << "\n=============================================" << std::endl;
    std::cout << "TEST all_nodes()" << std::endl;
    std::cout << "=============================================" << std::endl;

    std::set<int> nodes_G = G.all_nodes();
    std::set<int> nodes_H = H.all_nodes();

    std::cout << "\nExpected nodes of graph G: \n";
    std::cout << "{1,2,3,4,5}\n";
    std::cout << "Computed nodes of graph G: \n";
    std::cout << nodes_G << std::endl;

    std::cout << "\nExpected nodes of graph H: \n";
    std::cout << "{1,2,3,4,5}\n";
    std::cout << "Computed nodes of graph H: \n";
    std::cout << nodes_H << std::endl;


    std::cout << "\n=============================================" << std::endl;
    std::cout << "TEST edge_number()" << std::endl;
    std::cout << "=============================================" << std::endl;


    std::cout << "\nExpected edge number for edge (1,2) of graph G: 0" << std::endl;
    std::cout << "Computed edge number: " << G.edge_number({1,2}) << std::endl;

    /*NOTA: se l'arco non è presente metto -1 al posto di chiamare un'eccezione*/
    std::cout << "\nExpected edge number for edge (1,4) of graph H: -1" << std::endl;
    std::cout << "Computed edge number: " << H.edge_number({1,4}) << std::endl;

    std::cout << "\nExpected edge number for edge (4,4) of graph H: 5" << std::endl;
    std::cout << "Computed edge number: " << H.edge_number({4,4}) << std::endl;

    /* ============================================= */
    std::cout << "\n=============================================" << std::endl;
    std::cout << "TEST edge_at()" << std::endl;
    std::cout << "=============================================" << std::endl;


    /*NOTA: se il numero d'arco non è presente metto (-1,-1) al posto di chiamare un'eccezione */
    std::cout << "\nExpected edge number 9 for graph G: (-1,-1)" << std::endl;
    std::cout << "Computed edge number: " << G.edge_at(9) << std::endl;

    std::cout << "\nExpected edge number 2 for graph G: (1,3)" << std::endl;
    std::cout << "Computed edge number: " << G.edge_at(1) << std::endl;

    std::cout << "\nExpected edge number 5 for graph H: (4,4)" << std::endl;
    std::cout << "Computed edge number: " << H.edge_at(5) << std::endl;


    std::cout << "\n=============================================" << std::endl;
    std::cout << "TEST neighbours()" << std::endl;
    std::cout << "=============================================" << std::endl;

    std::cout << "\nExpected neighbours of node 1 of G: {2,3,4}" << std::endl;
    std::cout << "Computed neighbours of node 1 of G: " << G.neighbors(1) << std::endl;


    std::cout << "\nExpected neighbours of node 4 of H: {2,3,4}" << std::endl;
    std::cout << "Computed neighbours of node 4 of H: " << H.neighbors(4) << std::endl;
    
    std::cout << "\nExpected neighbours of node 8 of H: {}" << std::endl;
    std::cout << "Computed neighbours of node 8 of H: " << H.neighbors(8) << std::endl;

    std::cout << "\n=============================================" << std::endl;
    std::cout << "TEST operator-()" << std::endl;
    std::cout << "=============================================" << std::endl;
    
    std::cout << "\nExpected result for G-H: (1,4) (4,5)" << std::endl;
    std::cout << "Computed result for G-H\n" << G-H  << std::endl;
    print_vector((G-H).all_edges()) ;

    std::cout << "\nExpected result for H-G: (1,5) (4,4)" << std::endl;
    std::cout << "Computed result for H-G:\n " << H-G << std::endl;
    
    return 0;
}