// ADS Praktikum 1.2 BST
// Name: Malek Bouaziz
#pragma once

/**
* Struktur zur Darstellung eines Knotens eines (Bin�r-)Baumes
*
* @param data Zahlenwert der im Baum gespeichert wird
* @param left Linkes Kind des Knotens
* @param right Rechtes Kind des Knotens
*
*/
struct node
{
	int data;
	int height;
	node* left, * right;
};

/**
* Klasse zur Darstellung eines Bin�rbaumes
*
* @param root Wurzelknoten des Baumes
*
*/
class bst
{
	node* root = nullptr;
public:
	node* find(int value);
	void insert(int value);
	void deleteValue(int value);
	void printInorder();
    void printPreorder();
    void printPostorder();
    void printLevelorder();
private:
	void insert_impl(node* current, int value);
	void printInorder_impl(node* current, int depth);
    void printPreorder_impl(node* current, int depth);
    void printPostorder_impl(node* current, int depth);
};
