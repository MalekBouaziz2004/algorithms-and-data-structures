# 🌳 Binary Search Tree (BST)

**Author:** Malek Bouaziz
**Course:** Algorithms & Data Structures · Praktikum 1.2
**Language:** C++17

A complete **Binary Search Tree** built from scratch with full CRUD operations and all four classic traversal strategies. Includes an interactive CLI for live testing.

---

## 📋 Overview

Each node stores an integer value. The tree enforces the BST property at all times: left child < parent < right child. Deletion handles all three structural cases, including the two-child case via in-order successor replacement.

---

## 🗂️ Files

| File | Role |
|------|------|
| `bst.h` | `node` struct + `bst` class declaration |
| `bst.cpp` | Insert, find, delete, traversal implementations |
| `main.cpp` | Preset tree (13 nodes) + interactive menu |

---

## ⚙️ Operations & Complexity

| Operation | Average | Worst Case |
|-----------|---------|------------|
| `insert(value)` | O(log n) | O(n) |
| `find(value)` | O(log n) | O(n) |
| `deleteValue(value)` | O(log n) | O(n) |
| All traversals | O(n) | O(n) |

**Traversals implemented:** Inorder · Preorder · Postorder · Levelorder (BFS)

---

## 🚀 Build & Run
```bash
g++ -std=c++17 -o bst main.cpp bst.cpp
./bst
```

The program initializes a tree with `{46, 83, 95, 22, 17, 68, 11, 82, 21, 31, 54, 99, 74}`,
then deletes `{68, 21, 17, 95}` before opening the interactive menu.

**Interactive menu:** Insert node
Search node
Delete node
Show Inorder traversal
Show all traversals
Exit

## 🧠 Concepts

- BST structure and invariants
- Recursive Inorder / Preorder / Postorder traversal
- Level-order traversal using `std::queue`
- Node deletion: leaf · one child · two children (in-order successor)
- Dynamic pointer-based tree construction
