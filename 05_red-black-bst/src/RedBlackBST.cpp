#include <iostream>
#include <queue>
#include <vector>


#include "RedBlackBST.h"

RedBlackBST::RedBlackBST()
{
    root = nullptr;
}

bool RedBlackBST::isRED(Node* x)
{
    if (x == nullptr)
        return false;
    return x->color == RED;
}

Node* RedBlackBST::rotateLeft(Node* h)
{
     // 1. Merke dir den rechten Nachfolger von h
    Node* x = h->right;

    // 2. Das linke Kind von x wird nun rechter Nachfolger von h
    h->right = x->left;

    // 3. h wird das linke Kind von x
    x->left = h;

    // 4. Farben anpassen: x übernimmt die Farbe von h
    x->color = h->color;
    h->color = true;

    // 5. x ist nun die neue Wurzel des Teilbaums
    return x;
}

Node* RedBlackBST::rotateRight(Node* h)
{
    // Schritt 1: Merke dir das linke Kind von h
    Node* x = h->left;

    // Schritt 2: Das rechte Kind von x wird nun das linke Kind von h
    h->left = x->right;

    // Schritt 3: h wird das rechte Kind von x
    x->right = h;

    // Schritt 4: Farben tauschen (x übernimmt die Farbe von h)
    x->color = h->color;
    h->color = true;

    // Schritt 5: x ist jetzt Wurzel des Teilbaums
    return x;
}

void RedBlackBST::flipColors(Node* h)
{
   if(isRED(h->left) && isRED(h->right)){
    h->color=true;
    h->left->color=false;
    h->right->color=false;
   }
}// flipColors wandelt einen 4-Knoten in zwei 2-Knoten um

bool RedBlackBST::insert(int key)
{
     root = insertRecursive(root, key);
    if (root) root->color = BLACK; // Wurzel immer schwarz
    return true;

}

Node* RedBlackBST::insertRecursive(Node* h, int key) {
    if (h == nullptr)
        return new Node(key, key, 1, RED); // Neuer Knoten: rot und val = key

    // Top-Down: 4-Knoten beim Abstieg auflösen
    if (isRED(h->left) && isRED(h->right))
        flipColors(h);

    // Rekursive Einfügephase
    if (key < h->key)
        h->left = insertRecursive(h->left, key);
    else if (key > h->key)
        h->right = insertRecursive(h->right, key);
    else {
        h->val = key;
        return h; // Duplikat, Wert aktualisieren
    }

    // Bottom-Up Balancing – alle Fälle prüfen

    // RL-Fall: rechter Kind rot, dessen linker Kind rot
    if (isRED(h->right) && h->right && isRED(h->right->left)) {
        h->right = rotateRight(h->right);
        h = rotateLeft(h);
    }
    // LR-Fall: linker Kind rot, dessen rechter Kind rot
    else if (isRED(h->left) && h->left && isRED(h->left->right)) {
        h->left = rotateLeft(h->left);
        h = rotateRight(h);
    }
    // LL-Fall: zwei linke Rote → einfache Rechtsrotation
    else if (isRED(h->left) && h->left && isRED(h->left->left)) {
        h = rotateRight(h);
    }
    // RR-Fall: zwei rechte Rote → einfache Linksrotation
    else if (isRED(h->right) && h->right && isRED(h->right->right)) {
        h = rotateLeft(h);
    }

    h->N = size(h->left) + size(h->right) + 1; // Knotenzahl aktualisieren
    return h;
}

int RedBlackBST::size()
{
    return size(root);
}

int RedBlackBST::size(Node* h)
{
    if (h == nullptr)
        return 0;
    else
        return h->N;
}


void RedBlackBST::print()
{
   std::queue<Node*> blackNodesQueue;
 std::queue<int> niveauQueue;
 int currentNiveau = -1;
 int niveau;
 Node* h = root;
 if (h == nullptr)
 {
 std::cout << "Baum ist leer!" << std::endl;
 return;
 }
 blackNodesQueue.push(h);
 niveauQueue.push(0);
 while (!blackNodesQueue.empty())
 {
 h = blackNodesQueue.front();
 blackNodesQueue.pop();
 niveau = niveauQueue.front();
 niveauQueue.pop();
 // Niveauwechsel
 if (niveau != currentNiveau)
 {
 std::cout << std::endl << "Niveau " << niveau << ": ";
 currentNiveau = niveau;
 }
 // Ausgabe des 2-er, 3-er oder 4-er Knoten
 std::cout << "(";
 if (isRED(h->left))
 {
 std::cout << h->left->key << ", ";
 if (h->left->left)
 {
 blackNodesQueue.push(h->left->left);
 niveauQueue.push(niveau + 1);
 }
 if (h->left->right)
 {
 blackNodesQueue.push(h->left->right);
 niveauQueue.push(niveau + 1);
 }
 }
 else
 {
 if (h->left)
 {
 blackNodesQueue.push(h->left);
 niveauQueue.push(niveau + 1);
 }
 }
 std::cout << h->key;
 if (isRED(h->right))
 {
 // rechter Nachfolger ist rot. Dann diesen ausgeben und die
 // schwarzen Nachfolger des roten
 // Knotens in die Queue legen
 // roten rechten Nachfolger ausgeben
 std::cout << ", " << h->right->key;
 // schwarze Kindknoten des rechten Nachfolgers in die Queue
 if (h->right->left)
 {
 blackNodesQueue.push(h->right->left);
 niveauQueue.push(niveau + 1);
 }
 if (h->right->right)
 {
 blackNodesQueue.push(h->right->right);
 niveauQueue.push(niveau + 1);
 }
 }
 else
 {
 if (h->right)
 {
 blackNodesQueue.push(h->right);
 niveauQueue.push(niveau + 1);
 }
 }
 std::cout << ") ";
 }
 std::cout << std::endl << std::endl;
}