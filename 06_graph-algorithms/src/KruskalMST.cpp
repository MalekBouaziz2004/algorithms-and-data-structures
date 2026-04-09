#include "KruskalMST.h"

/**
 * Erstellt einen MST zum Graph G mit dem Kruskal Algorithmus
 *
 * \param[in]  G		Kantengewichteter-Graph
 */
KruskalMST::KruskalMST(EdgeWeightedGraph G)
{
	 // Initialisiere treeID: Jeder Knoten gehört anfangs zu einem eigenen Baum
    treeID.resize(G.getV());
    for (int i = 0; i < G.getV(); ++i)
        treeID[i] = i;

    // Erstelle eine Prioritätswarteschlange mit allen Kanten, sortiert nach Gewicht
    std::priority_queue<Edge, std::vector<Edge>, std::greater<Edge>> pq;
    std::vector<Edge> edges = G.edges();
    for (int i = 0; i < edges.size(); ++i)
        pq.push(edges[i]);

    // Kruskal-Hauptschleife: Wähle Kanten mit kleinstem Gewicht, solange kein Zyklus entsteht
    while (!pq.empty()) {
        Edge e = pq.top();
        pq.pop();

        int v = e.either();
        int w = e.other(v);

        // Wenn v und w in verschiedenen Bäumen sind → verbinden
        if (treeID[v] != treeID[w]) {
            mst.push_back(e);

            // Vereinige die Bäume: alle Knoten mit ID von w bekommen die ID von v
            int treeID_w = treeID[w];
            for (int i = 0; i < G.getV(); ++i) {
                if (treeID[i] == treeID_w)
                    treeID[i] = treeID[v];
            }
        }
    }
}

/**
 * Gibt alle Kanten vom MST zurueck
 *
 * \return Vektor mit Kanten des MST
 */
std::vector<Edge> KruskalMST::edges() const
{
	
	return mst;
}

/**
 * Gibt die Summe aller Gewichte im MST zurueck
 *
 * \return Summe der Gewichte im MST
 */
double KruskalMST::weight() const
{
	double sum = 0.0;
    for (std::size_t i = 0; i < mst.size(); ++i)
    {
        sum += mst[i].weight();   // klassisches for, kein Range-based
    }
    return sum;
}
