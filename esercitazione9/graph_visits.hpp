#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include "unidirected_graph.hpp"

struct Journey{
    int from;      // nodo padre
    int to;        // nodo figlio
};

/* Non salvo solo il nodo da visitare, ma anche chi l'ha visitato {from, to} [struct Journey].
 * Questo serve perché, quando estraggo un nodo dal contenitore, devo 
 * sapere chi lo ha "scoperto" per poter ricostruire l'arco nell'albero finale.
 * * LOGICA "TO -> FROM":
 * All'interno del ciclo sui vicini, il nodo appena raggiunto (step_to) cambia ruolo:
 * smette di essere la 'destinazione' del viaggio attuale e diventa la 'partenza' 
 * (from) per tutti i viaggi verso i suoi vicini non ancora visitati.
 */
template<typename T>
unidirected_graph graph_visit(const unidirected_graph& G, int source, T& container) {
    /* NOTA: il +1 nelle dimensione dei vettori è perché i nodi partono tutti da 1 e non da 0 */
    std::vector<bool> reached(G.all_nodes().size()+1, false); // inizializzo un vettore di n = #nodi elementi a false 
    unidirected_graph tree;

    container.put({source,source});

    while(!container.empty()) { 
        Journey step = container.get();
        int step_from = step.from;
        int step_to = step.to;

        // Approccio "LATE DISCOVERY": segno il nodo come visitato SOLO DOPO 
        // averlo estratto dal contenitore, non quando lo inserisco.
        // Questo è obbligatorio per far funzionare correttamente la DFS con un singolo 
        // contenitore generico. Inserire più copie dello stesso nodo nel contenitore 
        // è normale: questa riga fa da "filtro" scartando i duplicati già elaborati.
        if (reached[step_to]) {continue;}  // se ho già visitato il nodo figlio passo alla prossima iterazione del while
        reached[step_to] = true;

        if (step_from != step_to) {
            tree.add_edge({step_from, step_to});
        }
        for (auto w : G.neighbors(step_to)) {
            if (!reached[w]) {            
                container.put({step_to, w});
            }
        }
    }
    return tree;
}

// le chiamate per referenze "&" servono a far sì che la funzione helper modifica i valori quando chiamo la funzione principale //
void dfs_helper(const unidirected_graph& G, int u, std::vector<bool>& reached, unidirected_graph& tree) {
    reached[u] = true;
    for (auto w : G.neighbors(u)) {
        if (!reached[w]) {
            tree.add_edge({u,w});
            dfs_helper(G, w, reached, tree);
        }
    }

}

// Visita in profondità (DFS) implementata in modo ricorsivo.
// Anche se non uso esplicitamente la classe 'stack<T>', questa funzione 
// è a tutti gli effetti una visita LIFO. Sfrutta lo "Stack di sistema" (Call Stack)
// generato automaticamente dal C++ ad ogni chiamata di 'dfs_helper'.
unidirected_graph recursive_dfs(const unidirected_graph& G, int source) {
    std::vector<bool> reached(G.all_nodes().size()+1, false); 
    unidirected_graph tree;

    dfs_helper(G, source, reached, tree);
    return tree;
}
    

class Compare {
public:
    bool operator()(std::pair<int, int> a, std::pair<int, int> b) {
        return a.second > b.second;
    }
};

/* NOTA: qui tutti i pesi valgono 1 */
unidirected_graph dijkstra(const unidirected_graph& G, int source) {
    int n = G.all_nodes().size() + 1;
    std::vector<int> pred(n, -1);
    std::vector<int> dist(n, 10000000); 
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, Compare> pq;

    pred[source] = source;
    dist[source] = 0;

    for (int i=1; i < n; i++) {
        pq.push({i, dist[i]});
    }
    while (!pq.empty()) {
        int u = pq.top().first;
        int delta = pq.top().second; // distanza vecchia estratta dalla coda
        pq.pop();

        // LA GHIGLIOTTINA
        // Siccome la std::priority_queue non ha il comando Decrease-Key, quando trovo 
        // una scorciatoia infilo nella coda un "nuovo biglietto" aggiornato, lasciando
        // dentro quello vecchio. 
        // Questo 'if' controlla se il biglietto appena estratto (delta) è ormai "spazzatura"
        // rispetto alla vera distanza ottima che ho salvato sulla lavagna (dist[u]).        
        if (delta > dist[u]) {
            continue;
        }

        for (int w: G.neighbors(u)) {
            if (dist[w] > dist[u] + 1) { 
                dist[w] = dist[u] + 1;
                pred[w] = u;
                
                // IL DECREASE-KEY:
                pq.push({w, dist[w]}); 
            }
        }
    }

    unidirected_graph tree;
    for (int i = 0; i < n; i++) {
        if (pred[i] != -1 && pred[i] != i) { // Se ha un padre valido e non è la sorgente
            tree.add_edge({pred[i], i});
        }
    }
    
    return tree;
}
    
  
inline std::ostream& operator<<(std::ostream& os, const std::pair<int,int>& p)
{
    os << "(" << p.first << "," << p.second << ")";
    return os;
}

