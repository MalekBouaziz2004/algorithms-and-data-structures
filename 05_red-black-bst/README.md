# 🔴⚫ Left-Leaning Red-Black BST

**Author:** Malek Bouaziz
**Course:** Algorithms & Data Structures · Praktikum 3
**Language:** C++17
**Reference:** Sedgewick & Wayne — Algorithms, 4th Edition, §3.3

A **Left-Leaning Red-Black Binary Search Tree** that guarantees O(log n) insert
and search by maintaining balance through color assignments and rotations.
Internally equivalent to a 2-3-4 tree.

---

## 📋 Overview

Every insertion is followed by at most three structural fixes — `rotateLeft`,
`rotateRight`, `flipColors` — applied bottom-up. The left-leaning constraint
means red links always lean left, reducing the number of cases to handle
compared to classic RB tree variants.

### Balancing Rules (Sedgewick p. 464–468)
Right child RED + left child BLACK   →  rotateLeft
Left child RED + left-left RED       →  rotateRight
Both children RED                    →  flipColors
---

## 🗂️ Files

| File | Role |
|------|------|
| `Node.h` / `Node.cpp` | Tree node: key, RED/BLACK color, child pointers |
| `RedBlackBST.h` / `RedBlackBST.cpp` | Insert, rotate, flip, size, print |
| `RBTreeTest.cpp` | Catch2 unit tests |
| `main.cpp` | Demo tree + interactive insert/display menu |
| `gip_mini_catch.h` | Lightweight Catch2 header |

---

## ⚙️ Complexity Guarantees

| Operation | Complexity |
|-----------|------------|
| `insert(key)` | O(log n) — guaranteed |
| `size()` | O(1) |
| `print()` | O(n) |

Height is bounded at **2 log n** in the worst case — far better than
an unbalanced BST.

---

## 🚀 Build & Run
```bash
g++ -std=c++17 -o rbtree main.cpp RedBlackBST.cpp Node.cpp RBTreeTest.cpp
./rbtree
```

The program runs unit tests, builds a sample tree from
`{503, 502, 403, 1002, 2002, 3002}`, displays its structure, then opens:
Insert key manually
Display tree structure
Exit
---

## 🧠 Concepts

- Self-balancing BST invariants
- Red-Black tree (Sedgewick Left-Leaning variant)
- Left/right rotations and color flipping
- Equivalence: Red-Black BST ↔ 2-3-4 tree
- Catch2 unit testing
