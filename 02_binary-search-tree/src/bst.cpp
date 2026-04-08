// ADS Praktikum 1.2 BST
// Name: Max Mustermann
#include <iostream>
#include <queue>
#include "bst.h"

/**
* Start-Funktion zur Suche eines Integer-Zahlenwertes im Baum
*
* @param value Integer-Zahlenwert, der gesucht werden soll
*
*/
node* bst::find(int value)
{
    node* current = root;
    while (current != NULL) {
        if (current->data == value) {
            return current;
        } else if (current->data > value) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return NULL;
}

/**
* Funktion zum Einfügen eines Integer-Zahlenwertes in den Baum
*
* @param value Integer-Zahlenwert, der eingefügt werden soll
*
*/
void bst::insert(int value)
{
    if (!root)
        root = new node{ value, 0, NULL, NULL };
    else
        insert_impl(root, value);
}

/**
* Rekursive Funktion zum Einfügen eines Integer-Zahlenwertes im Baum
*
* @param current Knoten, hinter den eingefügt werden soll
* @param value Integer-Zahlenwert, der eingefügt werden soll
*
*/
void bst::insert_impl(node* current, int value)
{
    if (value < current->data)
    {
        if (current->left == NULL) {
            current->left = new node{ value, 0, NULL, NULL };
        } else {
            insert_impl(current->left, value);
        }
    }
    else
    {
        if (current->right == NULL) {
            current->right = new node{ value, 0, NULL, NULL };
        } else {
            insert_impl(current->right, value);
        }
    }

    int left_height = (current->left != NULL) ? current->left->height : 0;
    int right_height = (current->right != NULL) ? current->right->height : 0;
    current->height = 1 + std::max(left_height, right_height);
}

//INORDER-LWR
void bst::printInorder() {
    printInorder_impl(root, 0);
}

void bst::printInorder_impl(node* current, int depth) {
    if (current != nullptr) {
        printInorder_impl(current->left, depth + 1);
        std::cout << "Knoten: " << current->data << " | Hoehe: " << depth << std::endl;
        printInorder_impl(current->right, depth + 1);
    }
}

//PREORDER-WLR
void bst::printPreorder() {
    printPreorder_impl(root, 0);
}

void bst::printPreorder_impl(node* current, int depth) {
    if (current != nullptr) {
        std::cout << "Knoten: " << current->data << " | Hoehe: " << depth << "\n";
        printPreorder_impl(current->left, depth + 1);
        printPreorder_impl(current->right, depth + 1);
    }
}

//POSTORDER-LRW
void bst::printPostorder() {
    printPostorder_impl(root, 0);
}

void bst::printPostorder_impl(node* current, int depth) {
    if (current != nullptr) {
        printPostorder_impl(current->left, depth + 1);
        printPostorder_impl(current->right, depth + 1);
        std::cout << "Knoten: " << current->data << " | Hoehe: " << depth << "\n";
    }
}

//LEVEL-ORDER
void bst::printLevelorder() {
    if (root == nullptr) return;

    std::queue<std::pair<node*, int>> tree;
    tree.push({ root, 0 });

    while (!tree.empty()) {
        node* current = tree.front().first;
        int depth = tree.front().second;
        tree.pop();

        std::cout << "Knoten: " << current->data << " | Hoehe: " << depth << "\n";

        if (current->left != nullptr)
            tree.push({ current->left, depth + 1 });
        if (current->right != nullptr)
            tree.push({ current->right, depth + 1 });
    }
}

/**
* Funktion zum Löschen eines Knotenwertes im Baum
*
* @param value Integer-Zahlenwert, der gelöscht werden soll
*
*/
void bst::deleteValue(int value)
{
    node* current = root;
    node* parent = NULL; // <- Parent de current

    while (current != NULL && current->data != value) {
        parent = current;
        if (value < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    if (current == NULL) return;

    // Fall 1: Z ist ein Blatt
    if (current->left == NULL && current->right == NULL) {
        if (parent == NULL) {
            // delete root
            root = NULL;
        } else if (parent->left == current) {
            parent->left = NULL;
        } else {
            parent->right = NULL;
        }
        delete current;
    }
    // Fall 2 : Z hat ein Nachfolger
    else if (current->left == NULL || current->right == NULL) {
        node* child = (current->left != NULL) ? current->left : current->right;

        if (parent == NULL) {
            root = child;
        } else if (parent->left == current) {
            parent->left = child;
        } else {
            parent->right = child;
        }
        delete current;
    }
    // Fall 3 : Z hat 2 Nachfolger
    else {
        node* Parents = current; // <- Parent du ziel
        node* ziel = current->right;

        // kleinste Element im rechten Teilbaum
        while (ziel->left != NULL) {
            Parents = ziel;
            ziel = ziel->left;
        }

        // ziel n'est pas le fils direct de current
        if (Parents != current) {
            Parents->left = ziel->right;
            ziel->right = current->right;
        }

        ziel->left = current->left;

        // Den Elternknoten neu verbinden
        if (parent == NULL) {
            root = ziel;
        } else if (parent->left == current) {
            parent->left = ziel;
        } else {
            parent->right = ziel;
        }
        delete current;
    }

    // Aktualisieren Sie außerdem die Höhen der Knoten des betroffenen Teilbaums
    node* temp = root;
    while (temp != NULL) {
        int leftHeight = (temp->left != NULL) ? temp->left->height : 0;
        int rightHeight = (temp->right != NULL) ? temp->right->height : 0;

        temp->height = 1 + std::max(leftHeight, rightHeight);

        if (value < temp->data) {
            temp = temp->left;
        } else if (value > temp->data) {
            temp = temp->right;
        } else {
            break;
        }
    }
}




