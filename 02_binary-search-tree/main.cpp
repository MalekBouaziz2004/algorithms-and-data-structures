// ADS Praktikum 1.2 BST
// Name: Max Mustermann
#include "bst.h"
#include <iostream>
#include <queue> // notwendig für Levelorder

void menuAnzeigen() {
    std::cout << "--- Binary Search Tree Menu ---" << std::endl;
    std::cout << "1. Knoten einfuegen" << std::endl;
    std::cout << "2. Knoten suchen" << std::endl;
    std::cout << "3. Knoten loeschen" << std::endl;
    std::cout << "4. Inorder Traversierung anzeigen" << std::endl;
    std::cout << "5. Alle Traversierungen anzeigen" << std::endl;
    std::cout << "0. Beenden" << std::endl;
    std::cout << "Bitte Auswahl eingeben: ";
}

int main() {
    bst meinBaum;
    int eingabe = 0;

    //  Initiale Baum
    int werte[] = {46, 83, 95, 22, 17, 68, 11, 82, 21, 31, 54, 99, 74};
    const int anzahl = 13;
    
    for (int i = 0; i < anzahl; ++i) {
        meinBaum.insert(werte[i]);
    }

    // Ausgabe Inorder
    std::cout << "Inorder Traversierung des Anfangsbaums:" << std::endl;
    meinBaum.printInorder();

    // Suche nach 17 und 11
    std::cout << "Suche nach 17: ";
    if (meinBaum.find(17)) std::cout << "Gefunden!" << std::endl;
    else std::cout << "Nicht gefunden." << std::endl;

    std::cout << "Suche nach 11: ";
    if (meinBaum.find(11)) std::cout << "Gefunden!" << std::endl;
    else std::cout << "Nicht gefunden." << std::endl;

    // Löschen der Knoten
    int zuLoeschen[] = {68, 21, 17, 95};
    const int anzahlLoeschen = 4;

    for (int i = 0; i < anzahlLoeschen; ++i) {
        meinBaum.deleteValue(zuLoeschen[i]);
    }

    // Erneute Suche
    std::cout << "Erneute Suche nach 17: ";
    if (meinBaum.find(17)) std::cout << "Gefunden!" << std::endl;
    else std::cout << "Nicht gefunden." << std::endl;

    std::cout << "Erneute Suche nach 11: ";
    if (meinBaum.find(11)) std::cout << "Gefunden!" << std::endl;
    else std::cout << "Nicht gefunden." << std::endl;

    // Ausgabe aller Traversierungen
    std::cout << "Inorder Traversierung:" << std::endl;
    meinBaum.printInorder();

    std::cout << "Preorder Traversierung:" << std::endl;
    meinBaum.printPreorder();

    std::cout << "Postorder Traversierung:" << std::endl;
    meinBaum.printPostorder();

    std::cout << "Levelorder Traversierung:" << std::endl;
    meinBaum.printLevelorder();

    // --- User-Menu ---
    do {
        menuAnzeigen();
        std::cin >> eingabe;

        int wert = 0;
        switch (eingabe) {
            case 1:
                std::cout << "Geben Sie den Wert zum Einfuegen ein: ";
                std::cin >> wert;
                meinBaum.insert(wert);
                break;
            case 2:
                std::cout << "Geben Sie den zu suchenden Wert ein: ";
                std::cin >> wert;
                if (meinBaum.find(wert)) std::cout << "Gefunden!" << std::endl;
                else std::cout << "Nicht gefunden." << std::endl;
                break;
            case 3:
                std::cout << "Geben Sie den Wert zum Loeschen ein: ";
                std::cin >> wert;
                meinBaum.deleteValue(wert);
                break;
            case 4:
                std::cout << "Inorder Traversierung:" << std::endl;
                meinBaum.printInorder();
                break;
            case 5:
                std::cout << "Inorder Traversierung:" << std::endl;
                meinBaum.printInorder();
                std::cout << "Preorder Traversierung:" << std::endl;
                meinBaum.printPreorder();
                std::cout << "Postorder Traversierung:" << std::endl;
                meinBaum.printPostorder();
                std::cout << "Levelorder Traversierung:" << std::endl;
                meinBaum.printLevelorder();
                break;
            case 0:
                std::cout << "Programm wird beendet." << std::endl;
                break;
            default:
                std::cout << "Ungueltige Auswahl. Versuchen Sie es erneut." << std::endl;
        }
    } while (eingabe != 0);

    return 0;
}
