#include "PrimMST.h"

/**
 * Erstellt einen MST zum Graph G mit dem Prim Algorithmus
 *
 * \param[in]  G		Kantengewichteter-Graph
 * \param[in]  s		Startknoten
 */
PrimMST::PrimMST(EdgeWeightedGraph G, int s)

	{
    // 1) marked-Vektor auf false setzen
    marked.resize(G.getV(), false);

    // 2) Startknoten besuchen  – legt alle Kanten von s in die PQ
    visit(G, s);

    // 3) Hauptschleife: solange PQ nicht leer
    while (!pq.empty())
    {
        Edge e = pq.top();   // Kante mit kleinstem Gewicht
        pq.pop();            // aus der Priority-Queue entfernen

        int v = e.either();  // ein Ende der Kante
        int w = e.other(v);  // anderes Ende

        // 4) Zyklus­-Check: falls beide Enden schon im MST, überspringen
        if (marked[v] && marked[w]) continue;

        // 5) Kante in den MST übernehmen
        mst.push_back(e);

        // 6) Den noch unmarkierten Endknoten besuchen,
        //    wodurch seine Randkanten in die PQ gelegt werden
        if (!marked[v]) visit(G, v);
        if (!marked[w]) visit(G, w);
    }
}

/**
 * Markiert Knoten v im Graph G als markiert und fuegt alle Nachbarn zur pq hinzu
 *
 * \param[in]  G		Kantengewichteter-Graph
 * \param[in]  v		Knoten im Graph G
 */
void PrimMST::visit(EdgeWeightedGraph G, int v)
{
	   // Markiere Knoten v als besucht
    marked[v] = true;

    std::vector<Edge> edges = G[v]; // liefert alle Kanten ausgehend vom Knoten v

    // Lege alle Kanten von v zu unmarkierten (noch nicht besuchten) Knoten in die PQ ab
    for (int i = 0; i < edges.size(); i++) {
        if (!marked[edges[i].other(v)]) {
            pq.push(edges[i]);
        }
    }
}

/**
 * Gibt alle Kanten vom MST zurueck
 *
 * \return Vektor mit Kanten des MST
 */
std::vector<Edge> PrimMST::edges() const
{

	return mst;
}

/**
 * Gibt die Summe aller Gewichte im MST zurueck
 *
 * \return Summe der Gewichte im MST
 */
double PrimMST::weight() const
{
	double totalWeight = 0.0;

	for (std::size_t i = 0; i < mst.size(); ++i)
	{
		totalWeight += mst[i].weight();
	}

	return totalWeight;
	
}
