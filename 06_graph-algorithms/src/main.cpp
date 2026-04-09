#include <iostream>
#include "EdgeWeightedGraph.h"
#include "PrimMST.h"
#include "Graphsearch.h"
#include "KruskalMST.h"
#include "DijkstraSP.h"


void runTests();

int main() {
	runTests();
    EdgeWeightedGraph* graph = nullptr;
    EdgeWeightedDigraph* digraph = nullptr;
    std::string filename;
    int startNode;

    int choice;
    do {
        std::cout << "\nPraktikum 4: Graphenalgorithmen:\n"
                  << "1) Graph einlesen\n"
                  << "2) Tiefensuche\n"
                  << "3) Breitensuche\n"
                  << "4) MST nach Prim (Eingabe: Startknoten)\n"
                  << "5) MST nach Kruskal\n"
                  << "6) Kürzeste Wege nach Dijkstra (Eingabe: Startknoten)\n"
                  << "7) Ausgabe der Adjazenzliste\n"
                  << "8) Kante löschen\n"
                  << "9) Kante hinzufügen\n"
                  << "10) Programm beenden\n"
                  << "?> ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Dateiname für Graph eingeben: ";
                std::cin >> filename;
                delete graph;  // vorherigen Graph löschen
                graph = new EdgeWeightedGraph(filename);
                digraph = new EdgeWeightedDigraph(filename); // Für Dijkstra
                std::cout << "Graph erfolgreich geladen.\n";
                break;

            case 2:
                if (!graph) { std::cout << "Bitte zuerst Graph einlesen.\n"; break; }
                std::cout << "Startknoten (0-basiert): ";
                std::cin >> startNode;
                {
                    std::vector<bool> marked;
                    std::vector<int> edgeTo;
                    Graphsearch::DFS(*graph, startNode, marked, edgeTo);
                }
                break;

            case 3:
                if (!graph) { std::cout << "Bitte zuerst Graph einlesen.\n"; break; }
                std::cout << "Startknoten (0-basiert): ";
                std::cin >> startNode;
                {
                    std::vector<bool> marked;
                    std::vector<int> edgeTo;
                    Graphsearch::BFS(*graph, startNode, marked, edgeTo);
                }
                break;

            case 4:
                if (!graph) { std::cout << "Bitte zuerst Graph einlesen.\n"; break; }
                std::cout << "Startknoten (0-basiert): ";
                std::cin >> startNode;
                {
                    PrimMST prim(*graph, startNode);
                    for (auto e : prim.edges())
                        std::cout << e.either() << " - " << e.other(e.either()) << " (" << e.weight() << ")\n";
                    std::cout << "Gesamtgewicht: " << prim.weight() << "\n";
                }
                break;

            case 5:
                if (!graph) { std::cout << "Bitte zuerst Graph einlesen.\n"; break; }
                {
                    KruskalMST kruskal(*graph);
                    for (auto e : kruskal.edges())
                        std::cout << e.either() << " - " << e.other(e.either()) << " (" << e.weight() << ")\n";
                    std::cout << "Gesamtgewicht: " << kruskal.weight() << "\n";
                }
                break;

            case 6:
                if (!digraph) { std::cout << "Bitte zuerst Graph einlesen.\n"; break; }
                std::cout << "Startknoten (0-basiert): ";
                std::cin >> startNode;
                {
                    DijkstraSP dijkstra(*digraph, startNode);
                    for (int v = 0; v < digraph->getV(); ++v) {
                        if (dijkstra.hasPathTo(v)) {
                            std::cout << "Pfad zu " << v << " (Kosten: " << dijkstra.distTo(v) << "): ";
                            for (const auto& edge : dijkstra.pathTo(v)) {
                                std::cout << edge.from() << " -> " << edge.to() << " [" << edge.weight() << "]  ";
                            }
                            std::cout << "\n";
                        } else {
                            std::cout << "Kein Pfad zu Knoten " << v << "\n";
                        }
                    }
                }
                break;

            case 7:
                if (graph) graph->print();
                else std::cout << "Bitte zuerst Graph einlesen.\n";
                break;

            case 8:
                if (!graph) { std::cout << "Bitte zuerst Graph einlesen.\n"; break; }

    {
        int v, w;
        double weight;
        std::cout << "Kante löschen – Startknoten v, Zielknoten w, Gewicht: ";
        std::cin >> v >> w >> weight;

        Edge e(v, w, weight);
        if (graph->del_Edge(e)) {
            std::cout << "Kante erfolgreich gelöscht.\n";
        } else {
            std::cout << "Kante konnte nicht gelöscht werden (nicht gefunden?).\n";
        }
    }
    break;
                

            case 9:
                if (!graph) { std::cout << "Bitte zuerst Graph einlesen.\n"; break; }

    {
        int v, w;
        double weight;
        std::cout << "Kante hinzufügen – Startknoten v, Zielknoten w, Gewicht: ";
        std::cin >> v >> w >> weight;

        Edge e(v, w, weight);
        graph->add(e);
        std::cout << "Kante hinzugefügt.\n";
    }
    break;
            case 10:
                std::cout << "Programm wird beendet.\n";
                break;

            default:
                std::cout << "Ungültige Eingabe!\n";
        }

    } while (choice != 10);

    delete graph;
    delete digraph;
     system("pause");
	return 0;
}

   
