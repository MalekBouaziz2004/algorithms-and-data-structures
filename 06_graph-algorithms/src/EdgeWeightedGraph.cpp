#include "EdgeWeightedGraph.h"
#include <fstream>
#include <assert.h>
#include <iostream>

/**
 * Erstellt einen Kantengewichteten-Gaph mit V Knoten
 *
 * \param[in]  V		Anzahl der Knoten
 */
EdgeWeightedGraph::EdgeWeightedGraph(int V)
	: V{V}
	, E{0}
{
	adj.resize(V);
}

/**
* Erstellt einen Kantengewichteten-Gaph anhand der Kantenliste in fname
*
* \param[in]  fname		Dateiname der Kantenliste
*/
EdgeWeightedGraph::EdgeWeightedGraph(std::string filename)
{
	std::ifstream infile(filename);
	int tmp_e = 0;
	infile >> this->V >> tmp_e;

	this->E = 0;

	this->adj.resize(this->V, std::vector<Edge>());

	int v, w;
	double weight;
	while (infile >> v >> w >> weight)
	{
		this->add(Edge(v, w, weight));
	}

	assert(("Missing edges!", tmp_e == this->E));
}
/**
 * Erstellt einen Kantengewichteten-Gaph mit V Knoten und den Kanten in edges
 *
 * \param[in]  V	Anzahl der Knoten
 * \param[in]  E	Kantenliste
 */
EdgeWeightedGraph::EdgeWeightedGraph(int V, std::vector<Edge> E)
{
	this->V = V;
	this->adj.resize(V);

	for (Edge e : E)
	{
		this->add(e);
	}
}

/**
 * Gibt zurueck ob der Knoten v ein gueltiger Knoten im Graph ist
 *
 * \param[in]  v		Knoten
 * \return Gueltigkeit des Knoten
 */
bool EdgeWeightedGraph::validateVertex(int v) const
{
	return v >= 0 && v < this->V;
}

/**
 * Gibt eine Fehlermeldung aus, wenn der Knoten v im Graph nicht gueltig ist
 *
 * \param[in]  v		Knoten
 */
void EdgeWeightedGraph::validateVertexWithError(int v) const
{
	assert(("Vertex is out of bounds!", this->validateVertex(v)));
}

/**
 * Gibt die Anzahl der Knoten zurueck
 *
 * \return Anzahl der Knoten
 */
int EdgeWeightedGraph::getV() const
{
	return this->V;
}

/**
 * Gibt die Anzahl der Kanten zurueck
 *
 * \return Anzahl der Kanten
 */
int EdgeWeightedGraph::getE() const
{
	return this->E;
}

/**
 * Fuegt die Kante e zum Graphen hinzu
 *
 * \param[in]  e	neue Kante
 */
void EdgeWeightedGraph::add(Edge e)
{
	this->validateVertexWithError(e.either());
	this->validateVertexWithError(e.other(e.either()));

	this->adj[e.either()].push_back(e);
	this->adj[e.other(e.either())].push_back(e);

	this->E++;
}

/**
 * Liefert alle benachbarten Kanten zu v
 * 
 * \param[in] v Knoten von dem aus gesucht wird
 * \return Vektor mit allen benachbarten Kanten
 */
std::vector<Edge> EdgeWeightedGraph::getAdj(int v) const
{
	std::vector<Edge> neighbors;
	for (auto const& n : adj[v]) {
		neighbors.push_back(n);
	}
	return neighbors;
}

std::vector<std::vector<Edge>> EdgeWeightedGraph::getAdj() const
{
	return this->adj;
}

/**
 * Gibt alle Kanten im Graph zurueck
 *
 * \return Vektor mit allen Kanten im Graph
 */
std::vector<Edge> EdgeWeightedGraph::edges() const
{
	std::vector<Edge> edgeList;
	for (int v = 0; v < this->V; v++)
	{
		int selfLoops = 0;
		for (Edge e : this->adj[v])
		{
			if (e.other(v) > v) {
				edgeList.push_back(e);
			}
			// add only one copy of each self loop (self loops will be consecutive)
			else if (e.other(v) == v) {
				if (selfLoops % 2 == 0) edgeList.push_back(e);
				selfLoops++;
			}
		}
	}
	return edgeList;
}

bool EdgeWeightedGraph::del_Edge(Edge e)
{
	int v = e.either();
    int w = e.other(v);
    bool removed = false;

    // 1) Entferne e aus der Liste von v
    auto& listV = adj[v];
    for (auto it = listV.begin(); it != listV.end(); ++it) {
        if (it->other(v) == w && it->weight() == e.weight()) {
            listV.erase(it);
            removed = true;
            break;
        }
    }

    if (!removed) {
        // Kante nicht in v gefunden → existiert nicht
        return false;
    }

    // 2) Entferne e aus der Liste von w
    auto& listW = adj[w];
    for (auto it = listW.begin(); it != listW.end(); ++it) {
        if (it->other(w) == v && it->weight() == e.weight()) {
            listW.erase(it);
            break;
        }
    }

    // 3) Zähle Kanten neu
    --E;
    return true;
}


/**
 * Gibt die verbunden Knoten eines Knoten v zurueck
 *
 * \param[in]  v		Knoten
 * \return Verbundene Knoten des Knoten v
 */
const std::vector<Edge> EdgeWeightedGraph::operator[](int v) const
{
	this->validateVertexWithError(v);
	return this->adj[v];
}

void EdgeWeightedGraph::print() const {
    for (int v = 0; v < getV(); ++v) {
        char vChar = 'A' + v;
        std::cout << vChar << "  ";

        for (const Edge& e : adj[v]) {
            int w = e.other(v);
            char wChar = 'A' + w;
            std::cout << "-> " << wChar << " [" << (int)e.weight() << "]  ";
        }

        std::cout << std::endl;
    }
}






