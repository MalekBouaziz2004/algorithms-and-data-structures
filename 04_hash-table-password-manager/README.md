# 🔐 Custom Hash Table — Password Manager

**Author:** Malek Bouaziz
**Course:** Algorithms & Data Structures · Praktikum 2.2
**Language:** C++17

A **hash table built from scratch** — no `std::unordered_map` — used to implement
a functional password manager. Demonstrates open addressing, collision resolution,
and automatic rehashing.

---

## 📋 Overview

The table stores `Account` entries (website · username · hashed password). It uses
a polynomial rolling hash function and resolves collisions with open addressing.
Once the load factor exceeds **0.6**, the table resizes to the next prime ≥ 2×
current capacity and rehashes all entries.

---

## 🗂️ Files

| File | Role |
|------|------|
| `MyHashTable.h` | `Account` struct + `MyHashTable` class declaration |
| `MyHashTable.cpp` | Hash, insert, login, rehash implementations |
| `main.cpp` | Interactive password manager CLI |

---

## ⚙️ Design

| Property | Value |
|----------|-------|
| Hash function | Polynomial rolling hash (prime = 31) |
| Collision handling | Open addressing — linear probing |
| Load factor threshold | 0.6 |
| Resize policy | Next prime ≥ 2× size |
| Password storage | Hex-encoded hash (never plaintext) |

---

## 🚀 Build & Run
```bash
g++ -std=c++17 -o hashtable main.cpp MyHashTable.cpp
./hashtable
```

**Interactive menu:** 
=== Password Manager ===

Add new entry
Attempt login
List all websites
Exit
---

## 🧠 Concepts

- Hash table internals: slots, buckets, open addressing
- Collision resolution: linear probing
- Load factor monitoring and dynamic rehashing
- Prime number table sizing for uniform distribution
- Password hashing (educational — not cryptographically secure)
