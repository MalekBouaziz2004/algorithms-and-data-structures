#pragma once
#include "EdgeWeightedDigraph.h"
#include "EdgeWeightedGraph.h"
#include <iostream>

namespace Graphsearch {

	/**
		* Fuehrt eine rekursive Tiefensuche im Graphen G,
		* ab dem Knoten v aus und markiert alle besuchten
		* Knoten in marked.
		* Alle besuchten Knoten werden ausgegeben.
		*
		* \param[in]	 G			Graph
		* \param[in]	 v			Startknoten
		* \param[in/out] marked		Bereits besuchte Knoten
		* \param[in/out] edgeTo		Vektor mit dem Nachfolgeknoten zu jedem Knoten
		*/
	void DFS_recursive(const EdgeWeightedGraph& G, int v, std::vector<bool>& marked, std::vector<int>& edgeTo) {
		marked[v] = true;

	// Ausgabe des Knotens sofort beim Besuch:
	std::cout << static_cast<char>('A' + v) << " ";

	for (const Edge& e : G.getAdj(v)) {
		int w = e.other(v);
		if (!marked[w]) {
			edgeTo[w] = v;
			DFS_recursive(G, w, marked, edgeTo);
		}
	}
	}

	/**
		* Fuehrt eine rekursive Tiefensuche im Graphen g, ab dem Knoten v aus.
		* Alle besuchten Knoten werden ausgegeben.
		* Starterfunktion zu DFS_recursive(EdgeWeigtedGraph, int, std::vector<bool>, std::vector<int>)
		*
		* \param[in]  G			Graph
		* \param[out] marked	Bereits besuchte Knoten
		* \param[out] edgeTo	Vektor mit dem Nachfolgeknoten zu jedem Knoten
		* \param[in]  v			Startknoten
		* \return	  true		Graph ist zusammenhaengend
		*			  false		Graph ist nicht zusammenhaengend
		*/

	bool DFS(const EdgeWeightedGraph& G, int v, std::vector<bool>& marked, std::vector<int>& edgeTo) {
		
	
	int V = G.getV(); // Anzahl der Knoten

	// Initialisierung
	marked.assign(V, false);
	edgeTo.assign(V, -1);

	// Pfadsuche starten
	DFS_recursive(G, v, marked, edgeTo);

	// Ausgabe der besuchten Knoten
	std::cout << "DFS besucht: ";
	for (int i = 0; i < V; ++i) {
		if (marked[i]) {
			std::cout << static_cast<char>('A' + i) << " ";
		}
	}
	std::cout << std::endl;

	// Prüfen, ob alle Knoten erreicht wurden → zusammenhängend
	for (int i = 0; i < marked.size(); ++i){
	if (!marked[i]) return false;
}
return true;}

	/**
		* Fuehrt eine iterative Breitensuche im Graphen g, ab dem Knoten v aus.
		* Alle besuchten Knoten werden ausgegeben.
		*
		* \param[in]  G			Graph
		* \param[in]  v			Startknoten
		* \param[out] marked	Gibt an welche Knoten besucht wurden bei der Suche
		* \param[out] edgeTo	Gibt den Nachfolgerknoten eines Knoten an
		* \return	  true		Graph ist zusammenhaengend
		*			  false		Graph ist nicht zusammenhaengend
		*/
	bool BFS(const EdgeWeightedGraph& G, int v, std::vector<bool>& marked, std::vector<int>& edgeTo) {
    int V = G.getV(); // Anzahl Knoten

    marked = std::vector<bool>(V, false); // Alle Knoten unbesucht
    edgeTo = std::vector<int>(V, -1);     // Kein Vorgänger bekannt

    std::queue<int> q;
    q.push(v);

    std::cout << "BFS besucht: ";

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        if (marked[current]) {
            continue;
        }

        marked[current] = true;
        std::cout << static_cast<char>('A' + current) << " ";

        for (const Edge& e : G.getAdj(current)) {
            int w = e.other(current);
            if (!marked[w]) {
                if (edgeTo[w] == -1) {
                    edgeTo[w] = current;
                    q.push(w);
                }
            }
        }
    }

    std::cout << std::endl;

    // Prüfen, ob alle Knoten besucht wurden
    for (int i = 0; i < V; ++i) {
        if (!marked[i]) {
            return false; 
    }
     
}

return true;}}
