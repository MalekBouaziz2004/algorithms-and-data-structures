#include <assert.h>
#include <cfloat> // DBL_MAX
#include "DijkstraSP.h"
#include <algorithm> 

/**
 * F�ge eine Kante mit minimalen Kosten hinzu, die von einem
 * Baumknoten zu einem Nicht-Baumknoten verl�uft und deren
 * Ziel w dem Startknoten s am n�chsten ist.
 *
 * \param[in]  G		Kantengewichteter-Digraph
 * \param[in]  v		Zielknoten
 */
void DijkstraSP::relax(EdgeWeightedDigraph G, int v)
{
	 std::vector<DirectedEdge> edges = G.getAdj(v);   // alle Kanten, die von v ausgehen

    for (std::size_t i = 0; i < edges.size(); ++i)
    {
        const DirectedEdge& e = edges[i];
        int w = e.to();                               // Zielknoten der Kante

        // Prüfe, ob der Pfad über v kürzer ist
        if (distToVect[w] > distToVect[v] + e.weight())
        {
            distToVect[w] = distToVect[v] + e.weight();
            edgeTo[w]     = e;                        // Vorgänger­kante speichern

            // Distanz in der Priority-Queue aktualisieren
            if (pq.contains(w))
                pq.change(w, distToVect[w]);
            else
                pq.push(w, distToVect[w]);
        }
    }}

/**
 * Fuert den Dijkstra Algorithmus von s, im Graph G aus.
 *
 * \param[in]  G		Kantengewichteter-Digraph
 * \param[in]  s		Startknoten
 */
DijkstraSP::DijkstraSP(EdgeWeightedDigraph G, int s)
{
	 // Distanzvektor anlegen
    distToVect.resize(G.getV());

  
    for (int v = 0; v < G.getV(); ++v) {
        distToVect[v] = DBL_MAX;
    }

    // Startknoten hat Distanz 0
    distToVect[s] = 0.0;

    // Startknoten in die Priority-Queue (Key = Distanz)
    pq.push(s, 0.0);            // <-- ggf. Signatur deiner PQ anpassen

    // Hauptschleife
    while (!pq.empty()) {
        int min_node = pq.top().value;   // Knoten mit kleinster Distanz
        pq.pop();                        // aus Queue entfernen

        // Füge immer eine Kante mit minimalen Pfadkosten zu s hinzu
        relax(G, min_node);
    }
}

/**
 * Gibt die Distanz von s zum Knoten v zurueck
 *
 * \param[in]  v		Zielknoten
 * \return Summe der Gewichte auf dem Pfad zu v
 */
double DijkstraSP::distTo(int v) const
{
	return distToVect[v];
}

/**
 * Gibt zurueck ob es einen Pfad zu v von s aus gibt
 *
 * \param[in]  v		Zielknoten
 * \return true, wenn es einen Pfad von s nach v gibt, sonst false
 */
bool DijkstraSP::hasPathTo(int v) const
{
	return distToVect[v] < DBL_MAX;
}

/**
 * Gibt den Pfad von s nach v als Vektor zurueck
 *
 * \param[in]  v		Zielknoten
 * \return Vektor mit allen Kanten des Pfades von s nach v
 */
std::vector<DirectedEdge> DijkstraSP::pathTo(int v) 
{
	 std::vector<DirectedEdge> path;

    
    if (!hasPathTo(v)) return path;//leer

    // Wir gehen rückwärts vom Zielknoten v zum Startknoten,
    // indem wir über die gespeicherten Kanten in edgeTo zurückverfolgen
    for (int current = v; edgeTo.find(current) != edgeTo.end(); current = edgeTo[current].from()) {
        path.push_back(edgeTo[current]);
    }

    // Da wir rückwärts gesammelt haben, müssen wir den Pfad umdrehen
    std::reverse(path.begin(), path.end());

    return path;
}
